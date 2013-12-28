#include <iostream>
#include "entities/Player.hpp"

#include "utils.hpp"

using namespace std;
using namespace sf;

Player::Player(Vector2f position, int size, int dx, int dy, int speed, int id) : MovableGraphicElement(position,size,size,dx,dy,speed){
    _score = 0;
    _playerId = id;
    _attack = false; _left = false; _right = false; _up = false; _down = false;
    _state = IDLE;

    if (!_texture->loadFromFile("gfx/pirateCat.png"))
    {
        cout << "Error loading pirateCat.png!" << endl;
    }
    _pirateIdle = new Animation(); _pirateMove = new Animation();
    _pirateIdle->setSpriteSheet(*_texture);
    _pirateMove->setSpriteSheet(*_texture);

    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*0,PLAYER_SIZE*0,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*1,PLAYER_SIZE*0,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*2,PLAYER_SIZE*0,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*3,PLAYER_SIZE*0,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*0,PLAYER_SIZE*1,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*1,PLAYER_SIZE*1,PLAYER_SIZE,PLAYER_SIZE));
    _pirateIdle->addFrame(IntRect(PLAYER_SIZE*2,PLAYER_SIZE*1,PLAYER_SIZE,PLAYER_SIZE));

    _pirateMove->addFrame(IntRect(PLAYER_SIZE*3,PLAYER_SIZE*1,PLAYER_SIZE,PLAYER_SIZE));
    _pirateMove->addFrame(IntRect(PLAYER_SIZE*0,PLAYER_SIZE*2,PLAYER_SIZE,PLAYER_SIZE));
    _pirateMove->addFrame(IntRect(PLAYER_SIZE*1,PLAYER_SIZE*2,PLAYER_SIZE,PLAYER_SIZE));
    _pirateMove->addFrame(IntRect(PLAYER_SIZE*2,PLAYER_SIZE*2,PLAYER_SIZE,PLAYER_SIZE));
    _pirateMove->addFrame(IntRect(PLAYER_SIZE*3,PLAYER_SIZE*2,PLAYER_SIZE,PLAYER_SIZE));

    _animatedSprite->setAnimation(*_pirateIdle);

    _hitbox.setFillColor(sf::Color(255,0,0)); //remove this later

    _hitbox.setSize(Vector2f(PLAYER_SIZE, HITBOX_HEIGHT));

    if(_playerId == 1)
        _hitbox.setPosition(_animatedSprite->getPosition().x,     //x
                            _animatedSprite->getPosition().y - HITBOX_HEIGHT);   //y
    else
        _hitbox.setPosition(_animatedSprite->getPosition().x,     //x
                            _animatedSprite->getPosition().y + PLAYER_SIZE);   //y
}

Player::~Player(){
    delete _pirateIdle; delete _pirateMove;
    cout << "Player deleted" << endl;
}

void Player::handleInput(){
    //TODO: implement different inputs between P1 and P2
    if(_playerId == 1){
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            _left = true;
        } else _left = false;

        if(Keyboard::isKeyPressed(Keyboard::Right)){
            _right = true;
        } else _right = false;

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            _up = true;
        } else _up = false;

        if(Keyboard::isKeyPressed(Keyboard::Down)){
            _down = true;
        } else _down = false;

        if(Keyboard::isKeyPressed(Keyboard::M)){
            _attack = true;
        } else _attack = false;
    }

    if(_playerId == 2){
        if(Keyboard::isKeyPressed(Keyboard::Q)){
            _left = true;
        } else _left = false;

        if(Keyboard::isKeyPressed(Keyboard::D)){
            _right = true;
        } else _right = false;

        if(Keyboard::isKeyPressed(Keyboard::Z)){
            _up = true;
        } else _up = false;

        if(Keyboard::isKeyPressed(Keyboard::S)){
            _down = true;
        } else _down = false;

        if(Keyboard::isKeyPressed(Keyboard::F)){
            _attack = true;
        }
        else _attack = false;
    }

    if(_up || _down || _left || _right || _attack){

        if(_left){
            _animatedSprite->move(-8, 0); _hitbox.move(-8,0); _state = MOVING;
        }

        if(_right){
            _animatedSprite->move(8, 0); _hitbox.move(8,0); _state = MOVING;
        }

        if(_up){
            _animatedSprite->move(0, -8); _hitbox.move(0,-8); _state = MOVING;
        }

        if(_down){
            _animatedSprite->move(0, 8); _hitbox.move(0,8); _state = MOVING;
        }

        if(_attack){
            _hitbox.setFillColor(sf::Color(255,0,255));
        } else _hitbox.setFillColor(sf::Color(255,0,0));
    }
    else _state = IDLE;
}

void Player::handleAnimation(){
    if( (_animatedSprite->getAnimation() != _pirateMove) && (_state == MOVING) )
        _animatedSprite->setAnimation(*_pirateMove);

    if( (_animatedSprite->getAnimation() != _pirateIdle) && (_state == IDLE) )
        _animatedSprite->setAnimation(*_pirateIdle);

    _animatedSprite->play();
    _animatedSprite->update(_frameClock.restart());
}

int Player::getScore() const{ return _score;}

void Player::setScore(int n){ _score = n;}

bool Player::getAttack() const{
    return _attack;
}

IntRect Player::getHitbox() const{
	IntRect hitBox;
	int x, y;
	x = _animatedSprite->getPosition().x;
    if(_playerId == 1)
        y = _animatedSprite->getPosition().y - HITBOX_HEIGHT;
    else
        y = _animatedSprite->getPosition().y + PLAYER_SIZE;

	hitBox.left   = x;
	hitBox.top    = y;
	hitBox.width  = PLAYER_SIZE;
	hitBox.height = HITBOX_HEIGHT;

	return hitBox;
}

RectangleShape Player::getHitboxShape() const{ return _hitbox; }
