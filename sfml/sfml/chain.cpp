#include "chain.h"

#include <vector>
#include <SFML/Graphics.hpp>

Chain::Chain()
{
}

Chain::~Chain()
{
}

void Chain::init(float linkWidth, float linkHeight)
    {
        setSize(sf::Vector2f(linkWidth, linkHeight));
        setOrigin(linkWidth / 2, linkHeight / 2);
        setFillColor(sf::Color(100, 100, 100));
    }
