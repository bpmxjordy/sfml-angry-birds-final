#include "Pig.h"
#include "Player.h"

Pig::Pig()
{
	rotation = 0;
}

Pig::~Pig()
{
	delete this;
}


void Pig::update()
{
	this->setPos(this->getPos().x, this->getPos().y);
	this->setRotation(this->getRotation());
	this->setScale(this->getScale());

}

void Pig::render()
{

}

void Pig::initialise()
{
}



void Pig::setPos(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	this->animal.setPosition(this->position);
	;
}

sf::Vector2f Pig::getPos()
{
	return this->animal.getPosition();
}

void Pig::setScale(sf::Vector2f scale)
{
	this->scale = scale;
	this->animal.setScale(scale);
}

sf::Vector2f Pig::getScale()
{
	return this->animal.getScale();
}

void Pig::setRotation(double rot)
{
	this->rotation = rot;
	this->animal.setRotation(rot);
}

float Pig::getRotation()
{
	return this->animal.getRotation();
}

void Pig::setVelocity(sf::Vector2f pos, float dt)
{
	this->position += pos * dt;
	setPos(this->position.x, this->position.y);
}

void Pig::setTexture(sf::Texture* tex)
{
	this->texture = *tex;
	this->animal.setTexture(*tex);
}

sf::Sprite Pig::getSprite()
{
	return this->animal;
}

void Pig::setOrigin(sf::Vector2f o)
{
	this->animal.setOrigin(o);
}

void Pig::setOpacity(float opacity) {
	this->getSprite().setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(opacity * 255)));
}
