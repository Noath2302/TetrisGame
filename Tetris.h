#pragma once
#include "gameStates.h"
#include <iostream>
#include "Pieces.h"
#include "Board.h"
#include "Game.h"
#include "gameDraw.h"
#include "pauseGame.h"
#include "Game_over.h"

class Tetris :
	public game_states
{
public:
	Tetris(SDL_Renderer *tetris_renderer, SDL_Event *tetris_event, int tetris_width, int tetris_height,bool *isRun);
	~Tetris();
	// ===== game_managing function
	void render();
	void handle();
	void update();

	bool onEnter();
	bool onExit();

	// ===== game_managing variable =====
	SDL_Event *tetris_event;
	SDL_Renderer *tetris_renderer;
	bool *isRun;
	// ===== game render function ===== 
	void render_init();		// for initiating procs around the state

	// ----- handle -----
	void render_handle_in();
	void render_handle_out();

	void render_render();
	void render_clean();


	// ===== managing states inside Tetris =====
	bool Tetris_lose;
	int Tetris_pause;

	// ===== point or score whatever =====
	int Tetris_point;

	// ===== state calling =====
	virtual states getStateIDhandle(){ return next_game_state; }
	virtual states getStateIDconst(){ return TETRIS; }

	// ===== window size =====
	int tetris_width;
	int tetris_height;

	// ===== Tetris render procs =====
	// ===== game =====
	gameDraw *Tetris_Draw;
	Pieces *Tetris_Pieces;
	Board *Tetris_Board;
	Game *Tetris_Game;

	// ===== pause =====
	pauseGame *pause;
	// ===== game_over =====
	Game_over *game_Over;
};

