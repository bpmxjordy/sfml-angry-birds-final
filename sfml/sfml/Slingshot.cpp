#include "Slingshot.h"

Slingshot::Slingshot()
{
}

Slingshot::~Slingshot()
{
	delete this;
}


void Slingshot::update()
{
	this->setPos(this->getPos().x, this->getPos().y);
	this->setRotation(this->getRotation());
	this->setScale(this->getScale());

}

void Slingshot::render()
{

}

void Slingshot::initialise()
{
}

void Slingshot::setPos(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	this->animal.setPosition(this->position);
}

sf::Vector2f Slingshot::getPos()
{
	return this->position;
}

void Slingshot::setScale(sf::Vector2f scale)
{
	this->scale = scale;
	this->animal.setScale(scale);
}

sf::Vector2f Slingshot::getScale()
{
	return this->animal.getScale();
}

void Slingshot::setRotation(double rot)
{
	this->rotation = rot;
	this->animal.setRotation(rot);
}

float Slingshot::getRotation()
{
	return this->animal.getRotation();
}

void Slingshot::setVelocity(sf::Vector2f pos, float dt)
{
	this->position += pos * dt;
	setPos(this->position.x, this->position.y);
}

void Slingshot::setTexture(sf::Texture* tex)
{
	this->texture = *tex;
	this->animal.setTexture(*tex);
}

sf::Sprite Slingshot::getSprite()
{
	return this->animal;
}

void Slingshot::setOrigin(sf::Vector2f o)
{
	this->animal.setOrigin(o);
}