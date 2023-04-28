#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	delete this;
}


void Player::update()
{
	this->setPos(this->getPos().x, this->getPos().y);
	this->setRotation(this->getRotation());
	this->setScale(this->getScale());
	
}

void Player::render()
{

}

void Player::initialise()
{
}



void Player::setPos(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	this->animal.setPosition(this->position);
	;
}

sf::Vector2f Player::getPos()
{
	return this->animal.getPosition();
}

void Player::setScale(sf::Vector2f scale)
{
	this->scale = scale;
	this->animal.setScale(scale);
}

sf::Vector2f Player::getScale()
{
	return this->animal.getScale();
}

void Player::setRotation(double rot)
{
	this->rotation = rot;
	this->animal.setRotation(rot);
}

float Player::getRotation()
{
	return this->animal.getRotation();
}

void Player::setVelocity(sf::Vector2f pos, float dt)
{
	this->position += pos * dt;
	setPos(this->position.x, this->position.y);
}

void Player::setTexture(sf::Texture* tex)
{
	this->texture = *tex;
	this->animal.setTexture(*tex);
}

sf::Sprite Player::getSprite()
{
	return this->animal;
}

void Player::setOrigin(sf::Vector2f o)
{
	this->animal.setOrigin(o);
}