#pragma once
#include "GameObject.h"

class Brick : public GameObject
{

	sf::Sprite object;
	sf::Vector2f position;
	sf::Vector2f scale;
	double rotation = 0;
	sf::Texture texture;

public:
	Brick();
	virtual ~Brick();
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


