#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
class Chain : public sf::RectangleShape{
	

public:
	Chain();
	virtual ~Chain();
	void init(float linkWidth, float linkHeight);

};

