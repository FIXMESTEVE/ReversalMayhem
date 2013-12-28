//main.cpp
//by Tom Solacroup


/*
BUILD WITH:
C:\MinGW\bin>mingw32-g++.exe -Wall  -g -DSFML_STATIC    -IC:\SFMLMinGW-2.1\include  -c C:\Users\Tom\workspace\ReversalMayhem\src\*.cpp

C:\MinGW\bin>mingw32-g++.exe -Wall  -g -DSFML_STATIC    -LC:\SFMLMinGW-2.1\lib -o RM.exe *.o -lsfml-graphics-d -lsfml-system-d -lsfml-window-d
*/
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "entities/Ball.hpp"
#include "entities/Player.hpp"
#include "CollisionEngine.hpp"
#include "utils.hpp"

using namespace std;
using namespace sf;

//We center the players at game start
const Vector2f PLAYER1_POS_INIT(WINDOW_SIZE.x/2 - PLAYER_SIZE/2, WINDOW_SIZE.y - PLAYER_SIZE);
const Vector2f PLAYER2_POS_INIT(WINDOW_SIZE.x/2 - PLAYER_SIZE/2, 0);
//We center the ball at game start
const Vector2f BALL_POS_INIT(WINDOW_SIZE.x/2 - BALL_SIZE/2, WINDOW_SIZE.y/2 - BALL_SIZE/2);


int main(){
	//let's create objects
	RenderWindow app(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y, 32), "Reversal Mayhem v0.1 prealpha");
	app.setFramerateLimit(MAX_FRAMERATE);
	Ball* ball = new Ball(BALL_POS_INIT, BALL_SIZE, BALL_SPEED, BALL_SPEED, BALL_SPEED);
	Player* player1 = new Player(PLAYER1_POS_INIT, PLAYER_SIZE, PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED, 1);
	Player* player2 = new Player(PLAYER2_POS_INIT, PLAYER_SIZE, PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED, 2);
	CollisionEngine* collision = new CollisionEngine(ball, player1, player2, WINDOW_SIZE);

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
		player1->handleInput();
		player2->handleInput();
		//cout << "ball X == " << ball->getShape()->getPosition().x << "; ball Y == " << ball->getShape()->getPosition().y << endl;
		//game logic ends here

        ball->handleAnimation();
        player1->handleAnimation();
        player2->handleAnimation();

		//screen clear and filling (black by default)
		app.clear();

		//graphics are being drawn here
		app.draw(*(ball->getAnimatedSprite()));

		app.draw(*(player1->getAnimatedSprite()));
		app.draw(*(player2->getAnimatedSprite()));

		app.draw(player1->getHitboxShape());
		app.draw(player2->getHitboxShape());
		//all graphics are drawn past this line

		//display the window
		app.display();
	}
	//delete all objects before leaving
	delete ball;
	delete player1;
	delete player2;
	delete collision;

	return EXIT_SUCCESS;
}

