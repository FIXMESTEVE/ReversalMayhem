/*
 * Ball.hpp
 *
 *  Created on: 17 sept. 2013
 *      Author: Tom
 */

#ifndef BALL_HPP_
#define BALL_HPP_
#include "MovableGraphicElement.hpp"

class Ball : public MovableGraphicElement{
private:
    Animation* _rotatingBall;
public:
	Ball(sf::Vector2f position, int size, int dx, int dy, int speed);
	virtual ~Ball();
	void handleAnimation();
	sf::IntRect getHitbox() const;
	void resetPosition();
	void reverseDx();
	void reverseDy();
};

#endif /* BALL_HPP_ */
