#pragma once
#include "GameStates.h"
#include <iostream>
#include "textBox.h"
#include "textTure.h"
#include "function.h"
#include <string>

class Game_over
{
public:
	Game_over(SDL_Renderer *go_renderer,states *nextGameState,int score,int Tetris_width,int Tetris_height);
	~Game_over();

	void render(int score);
	void handle(SDL_Event *go_event);

private:
	// ===== vars from Tetris =====
	int go_width, go_height;
	SDL_Renderer *go_renderer;
	states *nextGameState;

	// ===== renderings =====
	image *background;
	textBox *point_box;
	textBox *game_over_box;
	textBox *hintBox;
};

