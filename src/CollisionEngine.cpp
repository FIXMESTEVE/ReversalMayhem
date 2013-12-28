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

CollisionEngine::CollisionEngine(Ball *b, Player *p1, Player *p2, Vector2f screen){
	_ball = b;
	_p1 = p1;
	_p2 = p2;

	_screen = screen;
}

CollisionEngine::~CollisionEngine(){}

void CollisionEngine::collideX(){
    IntRect ballRect = _ball->getHitbox();
    IntRect p1Rect = _p1->getHitbox();
    IntRect p2Rect = _p2->getHitbox();
	bool ballSideCollision = (ballRect.intersects(p1Rect) && ballRect.left < p1Rect.left+p1Rect.width)
                                || (ballRect.intersects(p1Rect) && ballRect.left+ballRect.width > p1Rect.left)
                                || (ballRect.intersects(p2Rect) && ballRect.left < p2Rect.left+p2Rect.width)
                                || (ballRect.intersects(p2Rect) && ballRect.left+ballRect.width > p2Rect.left);


	if(ballRect.left < 0 || ballRect.left+ballRect.width > _screen.x )
		_ball->reverseDx();
}

void CollisionEngine::collideY(){
	IntRect ballRect = _ball->getHitbox();
    IntRect p1Rect = _p1->getHitbox();
    IntRect p2Rect = _p2->getHitbox();

    if(ballRect.top < 0 ){
        _ball->resetPosition();
        _p2->setScore(_p2->getScore()+1);
        cout << "P1: " << _p1->getScore() << " P2: " << _p2->getScore() << endl;
    }
    if(ballRect.top+ballRect.height > _screen.y){
        _ball->resetPosition();
        _p1->setScore(_p1->getScore()+1);
        cout << "P1: " << _p1->getScore() << " P2: " << _p2->getScore() << endl;
    }
    if( (_p1->getAttack() && ballRect.intersects(p1Rect)) || (ballRect.intersects(p2Rect) && _p2->getAttack()) )
        _ball->reverseDy();
}
