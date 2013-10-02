//main.cpp
//by Tom Solacroup
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "entities/Ball.hpp"
#include "CollisionEngine.hpp"

using namespace std;
using namespace sf;

//Game constants
const Vector2f WINDOW_SIZE(800,600);
const unsigned int MAX_FRAMERATE = 30;
const int BALL_SIZE = 35;
//We center the ball at game start
const Vector2f BALL_POS_INIT(WINDOW_SIZE.x/2 - BALL_SIZE/2, WINDOW_SIZE.y/2 - BALL_SIZE/2);
const int BALL_SPEED = 8;

int main(){
	//let's create objects
	RenderWindow app(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y, 32), "Reversal Mayhem v0.1 prealpha");
	app.setFramerateLimit(MAX_FRAMERATE);
	Ball* ball = new Ball(BALL_POS_INIT, BALL_SIZE, BALL_SPEED, BALL_SPEED, BALL_SPEED);
	CollisionEngine* collision = new CollisionEngine(ball, WINDOW_SIZE);
	//main loop
	while (app.isOpen()){
		Event event;

		while (app.pollEvent(event)){
			if(event.type == Event::Closed)
				app.close();
		}

		//game logic starts here
		ball->moveX();
		collision->collideX();
		ball->moveY();
		collision->collideY();
		//cout << "ball X == " << ball->getShape()->getPosition().x << "; ball Y == " << ball->getShape()->getPosition().y << endl;
		//game logic ends here

		//screen clear and filling (black by default)
		app.clear();

		//graphics are being drawn here
		app.draw(*(ball->getShape()));
		//all graphics are drawn past this line

		//display the window
		app.display();
	}
	//delete all objects before leaving
	delete ball;
	delete collision;

	return EXIT_SUCCESS;
}

