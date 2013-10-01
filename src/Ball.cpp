/*
 * Ball.cpp
 *
 *  Created on: 17 sept. 2013
 *      Author: Tom
 */

#include <iostream>
#include "entities/Ball.hpp"

using namespace std;
using namespace sf;

Ball::Ball(Vector2f position, int size, int dx, int dy, float speed)
: mySize(size), myDx(speed), myDy(speed), mySpeed(speed)
{
	myShape = new CircleShape();
	myShape->setFillColor(sf::Color(100,250,50));
	myShape->setRadius(mySize/2);
	myShape->setPosition(position);
}

Ball::~Ball(){
	delete myShape;
	cout << "ball deleted" <<endl; //did we delete the ball?
}

CircleShape* Ball::getShape(){return myShape;}

void Ball::moveX(){
	myShape->move(myDx, 0);
}

void Ball::moveY(){
	myShape->move(0, myDy);
}

void Ball::reverseDx(){myDx *= -1;}
void Ball::reverseDy(){myDy *= -1;}
