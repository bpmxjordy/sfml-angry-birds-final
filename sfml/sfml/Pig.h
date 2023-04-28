#pragma once
#include "GameObject.h"

class Pig : public GameObject
{

	sf::Sprite animal;
	sf::Vector2f position;
	sf::Vector2f scale;
	double rotation;
	sf::Texture texture;

	float m_movementSpeed = 1;

public:
	Pig();
	virtual ~Pig();
	void initialise();
	void update();
	void render();
	void setPos(int x, int y);
	sf::Vector2f getPos();
	void setScale(sf::Vector2f scale);
	sf::Vector2f getScale();
	void setRotation(double rot);
	float getRotation();
	void setOrigin(sf::Vector2f o);
	void setTexture(sf::Texture* tex);
	sf::Sprite getSprite();
	void setVelocity(sf::Vector2f pos, float dt);
	void setOpacity(float opacity);
};


