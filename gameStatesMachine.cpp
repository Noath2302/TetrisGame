#include "gameStatesMachine.h"

// ===== con, des =====
game_state_machine::game_state_machine(SDL_Renderer *game_state_renderer, SDL_Event *game_state_event, bool *game_state_isRun, int game_win_width, int game_win_height) :
game_state_renderer(game_state_renderer), game_state_event(game_state_event), game_state_isRun(game_state_isRun), game_win_width(game_win_width), game_win_height(game_win_height)
{
	pushState(new Menu(game_state_renderer, game_state_event, game_win_width, game_win_height, game_state_isRun));
}

game_state_machine::~game_state_machine()
{
	game_state_event = NULL;
	game_state_renderer = NULL;
	game_state_isRun = NULL;
}

// ===== game_managing_function =====
void game_state_machine::render(){
	if (vector_gamestates.back() != NULL){
		vector_gamestates.back()->render();
	}
}
void game_state_machine::handle(){
	if (vector_gamestates.back() != NULL){
		vector_gamestates.back()->handle();
	}
}
void game_state_machine::update(){
	if (vector_gamestates.back() != NULL){
		vector_gamestates.back()->update();
	}
}

// ===== state managing function =====
states game_state_machine::getStateIDhandle(){
	return vector_gamestates.back()->getStateIDhandle();
}
// ===== get a state =====
void game_state_machine::pushState(game_states *input_state){
	vector_gamestates.push_back(input_state);
	vector_gamestates.back()->onEnter();
}
// ===== delete state =====
void game_state_machine::popState(){
	if (!vector_gamestates.empty()){
		if (vector_gamestates.back()->onExit()){
			delete vector_gamestates.back();
			vector_gamestates.pop_back();
		}
	}
}
// ===== change state =====
void game_state_machine::changeState(){

	states nextGameState = vector_gamestates.back()->getStateIDhandle();
	if (!vector_gamestates.empty()){
		if (vector_gamestates.back()->getStateIDconst() == nextGameState){
			return;
			// ===== stay if same state =====
		}
		if (vector_gamestates.back()->onExit()){
			delete vector_gamestates.back();
			vector_gamestates.pop_back();
			// ===== delete if different state =====
		}
	}
	if (nextGameState == MENU){
		vector_gamestates.push_back(new Menu(game_state_renderer, game_state_event, game_win_width, game_win_height, game_state_isRun));
	}
	if (nextGameState == TETRIS){
		vector_gamestates.push_back(new Tetris(game_state_renderer, game_state_event, game_win_width, game_win_height,game_state_isRun));
	}
	if (vector_gamestates.back() != NULL){
		vector_gamestates.back()->onEnter();
	}
}

