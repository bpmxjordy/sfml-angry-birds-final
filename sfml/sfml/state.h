#pragma once
#include "Game.h"
class state
{
	state();
	virtual ~state();

	virtual void update() = 0;
	virtual void render() = 0;
};

