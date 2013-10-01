/*
 * CollisionEngine.hpp
 *
 *  Created on: 1 oct. 2013
 *      Author: Tom
 */

#ifndef COLLISIONENGINE_HPP_
#define COLLISIONENGINE_HPP_

#include "entities/Ball.hpp"
class CollisionEngine{
	private:
		Ball *myBall;
		sf::Vector2f myScreen;
	public:
		CollisionEngine(Ball *ball, sf::Vector2f screen);
		~CollisionEngine();
		void collideX();
		void collideY();
};


#endif /* COLLISIONENGINE_HPP_ */
