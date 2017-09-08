#include "Game_over.h"



Game_over::Game_over(SDL_Renderer *go_renderer, states *nextGameState, int score, int Tetris_width, int Tetris_height) :
go_renderer(go_renderer), nextGameState(nextGameState), go_width(Tetris_width), go_height(Tetris_height)
{
	std::string game_score = IntToString(score);
	point_box = new textBox(game_score.c_str(), "pic/font/Old Wise Sketch.otf", { 200, 250, 200 }, 120, Game_over::go_renderer);
	
	game_over_box = new textBox("Game Over", "pic/font/typogarden-demo.ttf", { 250, 200, 50 }, 170, Game_over::go_renderer);

	background = new image("pic/game_over.png", Game_over::go_renderer);
	hintBox = new textBox("hit space", "pic/font/gamer.ttf", { 150, 150, 150 }, 20, go_renderer);
}


Game_over::~Game_over()
{
	go_renderer = NULL;
	nextGameState = NULL;
	delete game_over_box;
	delete background;
	delete hintBox;
}

void Game_over::render(int score){
	background->draw(0, 0, go_width,go_height);
	std::string game_score = IntToString(score);
	if (!point_box->updated){
		point_box->update_text(game_score.c_str(), { 250, 100, 50 });
	}
	point_box->render(200, 100);
	game_over_box->render(20, 220);
	hintBox->render_fading(450,150);
}

void Game_over::handle(SDL_Event *go_event){
	if (go_event->type == SDL_KEYDOWN && go_event->key.keysym.sym == SDLK_SPACE){
		std::cout << "game over invoked";
		*nextGameState = MENU;
	}
}

