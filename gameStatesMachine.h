#pragma once
// ===== include game_states header =====
#include "gameStates.h"
#include <vector>
#include "Menu.h"
#include "Tetris.h"

class game_state_machine
{
public:
	// ===== con, des =====
	game_state_machine(SDL_Renderer *game_state_render, SDL_Event *game_state_event, bool *game_state_isRun, int game_win_width, int game_win_height);
	~game_state_machine();

	// ===== game_managing_function =====
	void render();
	void handle();
	void update();

	// ===== state managing function =====
	states getStateIDhandle();
	void pushState(game_states* pState);
	void changeState();
	void popState();

	// ===== variable for passing to states =====
	int game_win_width;
	int game_win_height;

	// ===== friend class =====
	friend class game_win;
private:

	SDL_Event *game_state_event;
	SDL_Renderer *game_state_renderer;
	bool *game_state_isRun;

	// ===== game_state array =====
	std::vector<game_states*> vector_gamestates;
};

