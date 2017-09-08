#pragma once
#include "gameStates.h"
#include <iostream>
#include "textBox_ColorChange.h"
#include "textTure.h"
#include "bubble.h"
class Menu :
	public game_states
{
public:
	Menu(SDL_Renderer *menu_renderer, SDL_Event *menu_event, int menu_width, int menu_height, bool *isRun);
	~Menu();
	// ===== game_managing function
	void render();
	void handle();
	void update();
	
	// ===== signaling function =====
	bool onEnter();
	bool onExit();

	// ===== game_managing variable =====
	SDL_Event *menu_event;
	SDL_Renderer *menu_renderer;
	bool *menu_isRun;

// ===== render function =====
	void render_init();		// for initiating procs around the state

	// ----- handle -----
	void render_handle_in();
	void render_handle_out();

	void render_render();
	void render_clean();

	// ===== state calling =====
	virtual states getStateIDhandle(){ return next_game_state; }
	virtual states getStateIDconst(){ return MENU; }

	// ===== window size =====
	int menu_width;
	int menu_height;
private:
	// ===== Menu render procs =====
	image *bg;
	textBox_ColorChange *Start;
	textBox *start_note;
	textBox_ColorChange *Exit;
	textBox *exit_note;

	textBox *title_add1;
	textBox *title;
	textBox *title_add2;

	bubble *bubb;
	textBox *VGU;
};

