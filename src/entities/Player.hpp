//Player.hpp
//by Tom Solacroup

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "MovableGraphicElement.hpp"

//player animation states
enum animationStates {
    IDLE,
    MOVING
};

class Player : public MovableGraphicElement{
private:
    int _playerId;
    int _score;
    bool _left, _right, _up, _down, _attack;


    animationStates _state;
    Animation* _pirateIdle;
    Animation* _pirateMove;
    Animation* _pirateAttack;

    //Colored area for debugging purpose
    sf::RectangleShape _hitbox;
public:
    Player(sf::Vector2f position, int size, int dx, int dy, int speed, int id);
    ~Player();
    void handleInput();
    void handleAnimation();
    void setScore(int n);
    int getScore() const;
    bool getAttack() const;
    sf::IntRect getHitbox() const;


    sf::RectangleShape getHitboxShape() const;
};

#endif // PLAYER_HPP_INCLUDED
