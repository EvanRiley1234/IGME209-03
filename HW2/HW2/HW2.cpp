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

#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

b2Vec2* tagetLocations;
b2Vec2 currentLocation;
typedef;

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
	//while loop for running

	std::cout << "Welcome to Gravity Snake\n";
	std::cout << "Use W, A, and S to move\n";


	while (targetsHit < 4 && !escapePress)
	{
		update(world, sBody, tBody, targetX, targetY, snakePositionM, targetPositionM);
		display(sBody, targetPositionM.y, targetPositionM.y);
		if (_kbhit())
		{
			applyForces(sBody);
			keyPresses++;
		}
		if (targetPositionM.x == snakePositionM.x && targetPositionM.y == snakePositionM.y)
		{
			moveTarget(tBody);
			targetsHit++;
		}
		if (_kbhit() && _getch() == 27)
		{
			escapePress = true;
		}

		
	}

	std::cout << "\nYour number of key presses: " << keyPresses;
}
