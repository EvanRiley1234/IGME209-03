#include <iostream>
#include <Box2D.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Box2D/Common/b2Settings.h"
#include "Box2D/Common/b2Draw.h"
#include "Box2D/Common/b2Timer.h"

#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Collision/Shapes/b2EdgeShape.h"
#include "Box2D/Collision/Shapes/b2ChainShape.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"

#include "Box2D/Collision/b2BroadPhase.h"
#include "Box2D/Collision/b2Distance.h"
#include "Box2D/Collision/b2DynamicTree.h"
#include "Box2D/Collision/b2TimeOfImpact.h"

#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Dynamics/b2WorldCallbacks.h"
#include "Box2D/Dynamics/b2TimeStep.h"
#include "Box2D/Dynamics/b2World.h"

#include "Box2D/Dynamics/Contacts/b2Contact.h"

#include "Box2D/Dynamics/Joints/b2DistanceJoint.h"
#include "Box2D/Dynamics/Joints/b2FrictionJoint.h"
#include "Box2D/Dynamics/Joints/b2GearJoint.h"
#include "Box2D/Dynamics/Joints/b2MotorJoint.h"
#include "Box2D/Dynamics/Joints/b2MouseJoint.h"
#include "Box2D/Dynamics/Joints/b2PrismaticJoint.h"
#include "Box2D/Dynamics/Joints/b2PulleyJoint.h"
#include "Box2D/Dynamics/Joints/b2RevoluteJoint.h"
#include "Box2D/Dynamics/Joints/b2RopeJoint.h"
#include "Box2D/Dynamics/Joints/b2WeldJoint.h"
#include "Box2D/Dynamics/Joints/b2WheelJoint.h"
#include <string>

#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>



int main()
{
	//variables for while loop
	bool escapePress = false;


	//creating the physics world
	b2Vec2 gravity(0.0f, -0.1f);
	b2World world(gravity);

	//number of keypresses and score
	int keyPresses = 0;
	int targetsHit = 0;

	b2Vec2 snakePositionM;
	b2Vec2 targetPositionM;

	b2Vec2* targetLocations[20];
	b2Vec2 currentLocation;

	//position for the target
	float targetX = 0;
	float targetY = 0;

	//target object creation
	b2BodyDef targetBody;
	targetBody.position.Set(0.0f, 0.0f);
	b2Body* tBody = world.CreateBody(&targetBody);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(1.0f, 1.0f);

	//create the snake body as a dynamic body
	b2BodyDef snakeBody;
	snakeBody.type = b2_dynamicBody;
	snakeBody.position.Set(0.0f, 4.0f);
	b2Body* sBody = world.CreateBody(&snakeBody);
	//attach a polygon shape to it
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	sBody->CreateFixture(&fixtureDef);


	moveTarget(tBody);

	//for part 2
	char numTargets[10];
	bool checkInputLoop = true;
	bool firstCheckFail = false;
	bool secondCheckFail = false;
	int currentTarget = 0;

	std::cout << "Welcome to Gravity Snake\n";
	std::cout << "Use the arrow keys to move\n";
	std::cout << "How many targets would you like (a number between 1 and 10)? ";
	std::cin >> numTargets;

	while (checkInputLoop)
	{
		//make sure the user entered a number
		for (int i = 0; i < strlen(numTargets); i++)
		{
			if(isdigit(numTargets[i]) == false)
			{
				firstCheckFail = true;
			}
		}

		//check to see if its greather then ten
		if (atoi(numTargets) > 10)
		{
			secondCheckFail = true;
		}

		//what happens if the checks fail or not
		if (!secondCheckFail && !firstCheckFail)
		{
			checkInputLoop = false;
		}
		else if(secondCheckFail || firstCheckFail)
		{
			std::cout << "Please enter an integer from 1 to 10 ";
			std::cin >> numTargets;
			firstCheckFail = false;
			secondCheckFail = false;
		}
	}

	targetLocations[19] = setupTargets(atoi(numTargets));
	std::cout << "\n";

	//while loop for running
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	int x = 10;
	int y = 10;

	while (targetsHit < atoi(numTargets))
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		currentLocation = selectNextTarget(currentTarget, targetLocations[19]);
		currentLocation = b2Vec2(200, 200);
		
		//display(sBody, targetPositionM.y, targetPositionM.y);
		processInput(sBody);
		
		if (_kbhit())
		{
			applyForces(sBody);
			keyPresses++;
		}
		
		sf::CircleShape circle(50.f);
		circle.setFillColor(sf::Color(100, 250, 50));
		circle.setPosition(snakePositionM.x + 350, snakePositionM.y + 250);
		window.draw(circle);

		sf::RectangleShape curTarget(sf::Vector2f(120.f, 50.f));
		curTarget.setFillColor(sf::Color(250, 250, 250));
		curTarget.setPosition(currentLocation.x + 350, currentLocation.y + 250);
		window.draw(curTarget);

		circle.move(5, 5);
		
		update(world, sBody, snakePositionM, circle);
		if (currentLocation.x - 10 < snakePositionM.x < currentLocation.x + 10 && currentLocation.y - 10 < snakePositionM.y < currentLocation.y + 10)
		{
			moveTarget(tBody);
			targetsHit++;
		}
		
		
		if (_kbhit() && _getch() == 27)
		{
			escapePress = true;
		}
		if (escapePress)
		{
			window.close();
		}
		window.display();
	}
	window.close();
	std::cout << "\nYour number of key presses: " << keyPresses;
}
