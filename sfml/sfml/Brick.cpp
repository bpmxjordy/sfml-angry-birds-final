#include "Brick.h"

#include "Brick.h"

Brick::Brick()
{
	rotation = 0;
}

Brick::~Brick()
{
	
}


void Brick::update()
{
	this->setPos(this->getPos().x, this->getPos().y);
	this->setRotation(this->getRotation());
	this->setScale(this->getScale());

}

void Brick::render()
{

}

void Brick::initialise()
{
}



void Brick::setPos(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	this->object.setPosition(this->position);
	;
}

sf::Vector2f Brick::getPos()
{
	return this->object.getPosition();
}

void Brick::setScale(sf::Vector2f scale)
{
	this->scale = scale;
	this->object.setScale(scale);
}

sf::Vector2f Brick::getScale()
{
	return this->object.getScale();
}

void Brick::setRotation(double rot)
{
	this->rotation = rot;
	this->object.setRotation(rot);
}

float Brick::getRotation()
{
	return this->object.getRotation();
}

void Brick::setVelocity(sf::Vector2f pos, float dt)
{
	this->position += pos * dt;
	setPos(this->position.x, this->position.y);
}

void Brick::setTexture(sf::Texture* tex)
{
	this->texture = *tex;
	this->object.setTexture(*tex);
}

sf::Sprite Brick::getSprite()
{
	return this->object;
}

void Brick::setOrigin(sf::Vector2f o)
{
	this->object.setOrigin(o);
}

void Brick::setOpacity(float opacity) {
	this->getSprite().setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(opacity * 255)));
}
