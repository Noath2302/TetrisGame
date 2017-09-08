#pragma once
#include "textTure.h"
#include "textBox.h"
#include "textBox_ColorChange.h"
#include "gameStates.h"

class pauseGame
{
public:
	pauseGame(SDL_Renderer *pause_renderer, SDL_Event *pause_event, int *Tetris_pause, int Tetris_width, int Tetris_weight, states *nextGameState);
	~pauseGame();

	// ===== render pause state =====
	void render();
	void handle();

	// ===== vars to interact with Tetris =====
	int Tetris_width;
	int Tetris_height;

	states *nextGameState;

	int *Tetris_pause;
	SDL_Renderer *pause_renderer;
	SDL_Event *pause_event;
private:
	image *pause_box;
	textBox *pause_title;
	textBox_ColorChange *pause_toMenu;
	textBox_ColorChange *pause_toResume;
};

