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
	myShape = new RectangleShape();
	myShape->setFillColor(sf::Color(0,0,255));
	myShape->setSize(Vector2f(size,size));
	myShape->setPosition(position);
}

Ball::~Ball(){
	delete myShape;
	cout << "ball deleted" <<endl; //did we delete the ball?
}

RectangleShape* Ball::getShape(){return myShape;}

void Ball::moveX(){
	myShape->move(myDx, 0);
}

void Ball::moveY(){
	myShape->move(0, myDy);
}

void Ball::reverseDx(){myDx *= -1;}
void Ball::reverseDy(){myDy *= -1;}

IntRect Ball::getHitbox() const{
	IntRect hitBox;
	hitBox.left = myShape->getPosition().x;
	hitBox.top = myShape->getPosition().y;
	hitBox.width = mySize;
	hitBox.height = mySize;

	return hitBox;
}
