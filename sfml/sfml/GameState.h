#pragma once
#include "state.h"
class GameState : public state
{
	GameState();
	~GameState();
	void update() = 0;
	void render() = 0;
};

