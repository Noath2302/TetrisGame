#pragma once
// ===== include library beforehand =====
#include "SDL.h"

// ===== game_States ID =====
enum states { MENU, TETRIS };

class game_states
{
public:
	// ===== game operation =====
	virtual void render() = 0;
	virtual void handle() = 0;
	virtual void update() = 0;

	// ===== signal for debugging =====
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	// ===== handling ID for gameStates =====
	virtual states getStateIDhandle() = 0;
	virtual states getStateIDconst() = 0;

protected:
	states next_game_state;
};

