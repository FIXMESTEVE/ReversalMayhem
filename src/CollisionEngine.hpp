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
	public:
		CollisionEngine(Ball *ball);
		void collideX();
		void collideY();
};


#endif /* COLLISIONENGINE_HPP_ */
