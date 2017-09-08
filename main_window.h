#pragma once
// ===== include library =====

#include "gameStatesMachine.h"

class main_window
{
public:
	// ===== con,des =====
	main_window(const char* main_window_title,int main_window_width,int mainwindow_height,SDL_Event *main_event);
	~main_window();
	
	// ===== window operating function =====
	void render();	// ===== drawing scene =====
	void handle();	// =====get user input =====
	void update();	// ===== do game input =====

	void RUN();

	// ===== window DIM =====
	int mainWin_width;
	int mainWin_height;

	// ===== isRun variable =====
	bool win_isRun;

	// ===== game_state machine =====
	game_state_machine *gSm;
private:
	SDL_Renderer *mainWin_renderer;
	SDL_Event *mainWin_event;
	SDL_Window *mainWin_window;
};

