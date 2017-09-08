#include "Tetris.h"


Tetris::Tetris(SDL_Renderer *Tetris_renderer, SDL_Event *Tetris_event, int Tetris_width, int Tetris_height,bool *isRun) :
tetris_renderer(Tetris_renderer), tetris_event(Tetris_event), tetris_width(Tetris_width), tetris_height(Tetris_height), isRun(isRun)
{
	next_game_state = TETRIS;
	// ===== initiate Tetris variable =====
	Tetris_lose = false;
	Tetris_pause = false;
	Tetris_point = 0;

	// ===== this should be where you put the render =====
	render_init();
}


Tetris::~Tetris()
{
	tetris_renderer = NULL;
	tetris_event = NULL;
	render_clean();
}

// ===== game managing function ===== 
void Tetris::render(){
	SDL_RenderClear(tetris_renderer);
	// ===== rendering stuffs go here =====
	render_render();
	SDL_RenderPresent(tetris_renderer);
}
void Tetris::handle(){
	if (tetris_event->type == SDL_QUIT){
		*isRun = false;
	}
	if (tetris_event->type == SDL_KEYDOWN && tetris_event->key.keysym.sym == SDLK_SPACE){
		next_game_state = MENU;
	}
	// ===== handle =====
	render_handle_in();
	render_handle_out();
}

void Tetris::update(){
	// ===== game update ===== 
	Tetris_Game->vertical();
}

bool Tetris::onEnter(){
	std::cout << "\n===== Tetris State =====\n";
	return true;
}
bool Tetris::onExit(){
	std::cout << "\n===== Tetris Out~s =====\n";
	return true;
}

// ===== game render function ===== 
void Tetris::render_init(){
	// ===== game =====
	Tetris_Draw = new gameDraw(tetris_renderer);
	Tetris_Pieces = new Pieces;
	Tetris_Board = new Board(Tetris_Pieces, tetris_height,&Tetris_point);
	Tetris_Game = new Game(tetris_renderer, tetris_event, Tetris_Board, Tetris_Pieces, Tetris_Draw, tetris_height,&Tetris_pause,&Tetris_lose,&Tetris_point);

	// ===== pause =====
	pause = new pauseGame(tetris_renderer, tetris_event, &Tetris_pause, tetris_width, tetris_height, &next_game_state);
	// ===== game_over =====
	game_Over = new Game_over(tetris_renderer, &next_game_state, Tetris_point, tetris_width, tetris_height);
}		// for initiating procs around the state

// ----- handle -----
void Tetris::render_handle_in(){
	Tetris_Game->handle();
	if (!Tetris_lose){
		pause->handle();
	}
	else if (Tetris_lose){
		game_Over->handle(tetris_event);
	}
}
void Tetris::render_handle_out(){

}

void Tetris::render_render(){
	Tetris_Game->DrawScene();
	if (!Tetris_lose){
		pause->render();
	}
	else if (Tetris_lose){
		game_Over->render(Tetris_point);
	}
}
void Tetris::render_clean(){
	// ===== game =====
	delete Tetris_Pieces;
	delete Tetris_Board;
	delete Tetris_Game;
	delete Tetris_Draw;

	// ===== pause =====
	delete pause;
	
	// ===== game_over =====
}
