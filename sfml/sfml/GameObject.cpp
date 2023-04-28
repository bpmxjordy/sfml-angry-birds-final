#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	delete this;
}


void GameObject::update()
{

}

void GameObject::render()
{

}

void GameObject::initialise()
{
}

void GameObject::setPos(int x, int y)
{
	
}

sf::Vector2f GameObject::getPos()
{
	return this->getPos();
}

void GameObject::setScale(sf::Vector2f scale)
{
	
}

sf::Vector2f GameObject::getScale()
{
	return this->getScale();
}

void GameObject::setRotation(double rot)
{
	
}

float GameObject::getRotation()
{
	return this->getRotation();
}

void GameObject::setTexture(sf::Texture* tex)
{
}

sf::Sprite GameObject::getSprite()
{
	return this->getSprite();
}

void GameObject::setOrigin(sf::Vector2f o)
{
}