/*
 * CollisionEngine.hpp
 *
 *  Created on: 1 oct. 2013
 *      Author: Tom
 */

#ifndef COLLISIONENGINE_HPP_
#define COLLISIONENGINE_HPP_

#include "entities/Ball.hpp"
#include "entities/Player.hpp"

class CollisionEngine{
	private:
		Ball *_ball;
		Player *_p1;
		Player *_p2;
		sf::Vector2f _screen;
	public:
		CollisionEngine(Ball *ball, Player *p1, Player *p2, sf::Vector2f screen);
		~CollisionEngine();
		void collideX();
		void collideY();
};


#endif /* COLLISIONENGINE_HPP_ */
