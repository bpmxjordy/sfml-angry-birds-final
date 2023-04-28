#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class GameObject
{

public:

	GameObject();
	virtual ~GameObject() = 0;

	virtual void initialise() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void setPos(int x, int y) = 0;
	virtual sf::Vector2f getPos() = 0;
	virtual void setScale(sf::Vector2f scale) = 0;
	virtual sf::Vector2f getScale() = 0;
	virtual void setRotation(double rot) = 0;
	virtual float getRotation() = 0;
	virtual void setOrigin(sf::Vector2f o);
	virtual void setTexture(sf::Texture* tex) = 0;
	virtual sf::Sprite getSprite() = 0;

};

