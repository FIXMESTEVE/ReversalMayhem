//MovableGraphicElement.hpp
//by Tom Solacroup
#ifndef MOVABLEGRAPHICELEMENT_HPP_INCLUDED
#define MOVABLEGRAPHICELEMENT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "GameElement.hpp"
#include "../Animation.hpp"
#include "../AnimatedSprite.hpp"

class MovableGraphicElement : public GameElement{
protected:
    sf::Clock _frameClock;
    sf::Sprite* _shape;
    sf::Texture* _texture;
    Animation* _animation;
    AnimatedSprite* _animatedSprite;
    int _dx;
    int _dy;
    int _speed;
public:
    MovableGraphicElement(sf::Vector2f position, int width, int height, int dx, int dy, int speed);
    virtual ~MovableGraphicElement();
    sf::Sprite* getShape() const;
    AnimatedSprite* getAnimatedSprite() const;
    void moveX();
    void moveY();
};

#endif // MOVABLEGRAPHICELEMENT_HPP_INCLUDED
