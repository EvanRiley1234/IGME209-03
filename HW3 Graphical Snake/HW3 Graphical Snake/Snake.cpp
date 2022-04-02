#include "Snake.h"
#include <Box2D.h>
#include <stdio.h>   
#include <conio.h>   
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

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

float timeStep = 1.0f / 10000.0f;
int32 velocityIterations = 7;
int32 positionIterations = 2;

void update(b2World& world, b2Body* snake, b2Vec2& sPos, sf::CircleShape circle)
{
	world.Step(timeStep, velocityIterations, positionIterations);
	b2Vec2 position = snake->GetPosition();
	sPos = position;
	circle.move(5, 5);
}

void display(b2Body* snake, float xPos, float yPos)
{
	b2Vec2 snakePosition = snake->GetPosition();
	printf("Snake Position: %4.2f %4.2f, TargetPosition: %4.2f %4.2f\r", snakePosition.x, snakePosition.y, xPos, yPos);
}

void applyForces(b2Body* snake)
{
	b2Vec2 snakePosition = snake->GetPosition();
	//left
	if (_getch() == 97)
	{
		snake->ApplyForceToCenter(b2Vec2(-10000, 0), true);
	}
	//up
	else if (_getch() == 119)
	{
		snake->ApplyForceToCenter(b2Vec2(0, 10000), true);
	}
	//right
	else if (_getch() == 100)
	{
		snake->ApplyForceToCenter(b2Vec2(10000, 0), true);
	}
}

void moveTarget(b2Body* target)
{
	b2Vec2 tPosition;
	srand(time(0));
	tPosition.x = rand() % 5 - 5;
	srand(time(0));
	tPosition.y = rand() % 5 - 5;
	target->SetTransform(tPosition, 0);
}


//for part 2
void processInput(b2Body* player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		ApplyForceLeft(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		ApplyForceRight(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		ApplyForceUp(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		ApplyForceDown(player);
	}
}

void ApplyForceUp(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0,10), true);
}

void ApplyForceDown(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0, -10), true);
}

void ApplyForceLeft(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-10, 0), true);
}

void ApplyForceRight(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(10, 0), true);
}

void StopMoving(b2Body* player)
{
	player->SetLinearVelocity(b2Vec2(0, 0));
}

void ReverseGravity(b2World* world)
{
}

b2Vec2 * setupTargets(int cnt)
{
	int xpos;
	int ypos;
	b2Vec2 targets[20];
	for (int i = 0; i < cnt; i++)
	{
		srand(time(0));
		xpos = rand() % 10 - 10;
		srand(time(0));
		ypos = rand() % 10 - 10;
		targets[i] = b2Vec2(xpos, ypos);
	}

	targets[cnt + 1] = b2Vec2(-1000, 1000);
	return targets;
}

b2Vec2 selectNextTarget(int cnt, b2Vec2 targets[])
{
	b2Vec2 current = targets[cnt];
	return current;
}