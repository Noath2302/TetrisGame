#include "main_window.h"


main_window::main_window(const char* main_window_title, int main_window_width, int mainwindow_height, SDL_Event *main_event) :
mainWin_width(main_window_width), mainWin_height(mainwindow_height), mainWin_event(main_event)
{
	// ===== window and renderer init =====
	mainWin_window = SDL_CreateWindow(main_window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mainWin_width, mainWin_height, SDL_WINDOW_SHOWN);
	mainWin_renderer = SDL_CreateRenderer(mainWin_window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(mainWin_renderer, 255, 255, 255, 255);

	// ===== isRun =====
	win_isRun = true;

	// ===== game obj =====
	gSm = new game_state_machine(mainWin_renderer, mainWin_event, &win_isRun, mainWin_width, mainWin_height);

}


main_window::~main_window()
{
	// ===== clean thing in class main_window =====
	SDL_DestroyRenderer(mainWin_renderer);
	SDL_DestroyWindow(mainWin_window);
	mainWin_event = NULL;

	// ===== clean obj =====
	delete gSm;
}

void main_window::render(){
	gSm->render();
}

void main_window::handle(){
	// ===== check States =====
	gSm->changeState();

	// ===== event procs =====
	if (SDL_PollEvent(mainWin_event)){
		gSm->handle();
	}
}

void main_window::update(){
	gSm->update();
}


void main_window::RUN(){
	render();
	handle();
	update();
}