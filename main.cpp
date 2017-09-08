// ===== include library =====
#include "main_window.h"

// ===== main function =====
int main(int argc, char* args[]){
	SDL_Event main_event;
	main_window game("Blocks", 640, 480, &main_event);

	// ===== game loop =====
	while (game.win_isRun){
		game.RUN();
	}
	return 0;
}