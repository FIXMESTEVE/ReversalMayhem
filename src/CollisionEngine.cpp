/*
 * CollisionEngine.cpp
 *
 *  Created on: 1 oct. 2013
 *      Author: Tom
 */

#include <iostream>
#include "CollisionEngine.hpp"

using namespace std;
using namespace sf;

CollisionEngine::CollisionEngine(Ball *b, Vector2f screen){
	myBall = b;
	myScreen = screen;
}

CollisionEngine::~CollisionEngine(){}

void CollisionEngine::collideX(){
	IntRect ballRect = myBall->getHitbox();

	if(ballRect.left < 0 || ballRect.left+ballRect.width > myScreen.x)
		myBall->reverseDx();
}

void CollisionEngine::collideY(){
	IntRect ballRect = myBall->getHitbox();

	if(ballRect.top < 0 || ballRect.top+ballRect.height > myScreen.y)
		myBall->reverseDy();
}
