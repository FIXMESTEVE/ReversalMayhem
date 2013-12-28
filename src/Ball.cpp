/*
 * Ball.cpp
 *
 *  Created on: 17 sept. 2013
 *      Author: Tom
 */

#include <iostream>
#include "entities/Ball.hpp"
#include "utils.hpp"

using namespace std;
using namespace sf;

Ball::Ball(Vector2f position, int size, int dx, int dy, int speed)
: MovableGraphicElement(position, size, size, dx, dy, speed){
    // load texture
    if (!_texture->loadFromFile("gfx/pandaBall.png"))
    {
        cout << "Error loading player.png!" << endl;
    }

    //push frames
    _rotatingBall = new Animation();
    _rotatingBall->setSpriteSheet(*_texture);
    _rotatingBall->addFrame(IntRect(BALL_SIZE*0,BALL_SIZE*0,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*1,BALL_SIZE*0,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*2,BALL_SIZE*0,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*3,BALL_SIZE*0,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*4,BALL_SIZE*0,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*0,BALL_SIZE*1,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*1,BALL_SIZE*1,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*2,BALL_SIZE*1,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*3,BALL_SIZE*1,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*4,BALL_SIZE*1,BALL_SIZE,BALL_SIZE));
    _rotatingBall->addFrame(IntRect(BALL_SIZE*0,BALL_SIZE*2,BALL_SIZE,BALL_SIZE));

    _animatedSprite->setAnimation(*_rotatingBall);
}

Ball::~Ball(){
    delete _rotatingBall;
	cout << "Ball deleted" <<endl; //did we delete the Ball?
}

IntRect Ball::getHitbox() const{
	IntRect hitBox;
	hitBox.left = _animatedSprite->getPosition().x;
	hitBox.top = _animatedSprite->getPosition().y;
	hitBox.width = BALL_SIZE;
	hitBox.height = BALL_SIZE;

	return hitBox;
}

void Ball::handleAnimation(){
    _animatedSprite->play();
    _animatedSprite->update(_frameClock.restart());
}

void Ball::resetPosition(){
    _animatedSprite->setPosition(WINDOW_SIZE.x/2 - BALL_SIZE/2, WINDOW_SIZE.y/2 - BALL_SIZE/2);
}
void Ball::reverseDx(){_dx *= -1;}
void Ball::reverseDy(){_dy *= -1;}
