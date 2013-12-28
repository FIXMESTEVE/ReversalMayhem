#include <iostream>
#include "entities/MovableGraphicElement.hpp"

using namespace std;
using namespace sf;

MovableGraphicElement::MovableGraphicElement(sf::Vector2f position, int width, int height, int dx, int dy, int speed) : GameElement(),
_dx(dx), _dy(dy), _speed(speed){
    _texture = new Texture();
    _shape = new Sprite();
    _animatedSprite = new AnimatedSprite(seconds(0.08));
    //_shape->setSize(Vector2f(width, height));
    _shape->setPosition(position);
    _animatedSprite->setPosition(position);
}

MovableGraphicElement::~MovableGraphicElement(){
    delete _shape; cout<<"for real!"<<endl;
    delete _texture;
    delete _animatedSprite;
}

Sprite* MovableGraphicElement::getShape() const
{
    return _shape;
}

AnimatedSprite* MovableGraphicElement::getAnimatedSprite() const
{
    return _animatedSprite;
}

void MovableGraphicElement::moveX(){_animatedSprite->move(_dx, 0);}
void MovableGraphicElement::moveY(){_animatedSprite->move(0, _dy);}
