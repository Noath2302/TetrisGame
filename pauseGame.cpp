#include "pauseGame.h"

pauseGame::pauseGame(SDL_Renderer *pause_renderer, SDL_Event *pause_event, int *Tetris_pause, int Tetris_width, int Tetris_height, states *nextGameState) :
pause_renderer(pause_renderer), pause_event(pause_event), Tetris_pause(Tetris_pause), Tetris_width(Tetris_width), Tetris_height(Tetris_height), nextGameState(nextGameState)
{
	// ===== initiate renderings =====
	pause_box = new image("pic/pause_box/pause_box.png", pause_renderer);
	pause_title = new textBox("Tetris Paused", "pic/font/gamer.ttf", { 255, 100, 100 }, 35, pause_renderer);
	pause_toMenu = new textBox_ColorChange("Exit To Menu", "pic/font/gamer.ttf", { 100, 10, 50 }, { 255, 200, 100 }, 30, pause_renderer, pause_event, 0, 0);
	pause_toResume = new textBox_ColorChange("Resume Game", "pic/font/gamer.ttf", { 100, 10, 50 }, { 255, 200, 100 }, 30, pause_renderer, pause_event, 0, 0);
}


pauseGame::~pauseGame()
{
	delete pause_title;
	delete pause_box;
	delete pause_toMenu;
	delete pause_toResume;
}

// ===== render function for pause =====
void pauseGame::render(){
	if (*Tetris_pause){
		pause_box->draw(Tetris_width / 2 - pause_box->src.w / 2, Tetris_height / 2 - pause_box->src.h / 2, Tetris_width / 2 - pause_box->src.w / 2 + pause_box->src.w, Tetris_height / 2 - pause_box->src.h / 2 + pause_box->src.h);
		pause_title->render(Tetris_width / 2 - pause_title->src.w / 2, Tetris_height / 2 - pause_title->src.h / 2 - 30);
		pause_toMenu->render(Tetris_width / 2 - pause_toMenu->textNormal->src.w / 2, Tetris_height / 2 - pause_toMenu->textNormal->src.h / 2 + 20);
		pause_toResume->render(Tetris_width / 2 - pause_toResume->textNormal->src.w / 2, Tetris_height / 2 - pause_toResume->textNormal->src.h / 2 + 70);
	}
}

void pauseGame::handle(){
	if (*Tetris_pause){
		pause_toMenu->handle();
		pause_toResume->handle();
		if (pause_toResume->isClick()){
			*Tetris_pause = false;
		}
		else if (pause_toMenu->isClick()){
			*nextGameState = MENU;
		}
	}
}