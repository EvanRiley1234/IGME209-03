#pragma once
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
#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

void update(b2World& world, b2Body* snake, b2Vec2& sPos, sf::CircleShape circle);

void display(b2Body* snake, float xPos, float yPos);

void applyForces(b2Body* snake);

void moveTarget(b2Body* target);

void processInput(b2Body* player);

void ApplyForceUp(b2Body* player);

void ApplyForceDown(b2Body* player);

void ApplyForceLeft(b2Body* player);

void ApplyForceRight(b2Body* player);

void StopMoving(b2Body* player);

void ReverseGravity(b2World* world);

b2Vec2* setupTargets(int cnt);

b2Vec2 selectNextTarget(int cnt, b2Vec2 targets[]);

#endif