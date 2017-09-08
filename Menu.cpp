#include "Menu.h"


Menu::Menu(SDL_Renderer *menu_renderer, SDL_Event *menu_event, int menu_width, int menu_height, bool *isRun) :
menu_renderer(menu_renderer), menu_event(menu_event), menu_width(menu_width), menu_height(menu_height), menu_isRun(isRun)
{
	next_game_state = MENU;
	// ===== this should be where you put the render =====
	render_init();
}


Menu::~Menu()
{
	menu_renderer = NULL;
	menu_event = NULL;

	// ===== render_clean =====
	render_clean();
}

void Menu::render(){
	SDL_RenderClear(menu_renderer);
	// ===== rendering stuffs go here =====
	render_render();
	SDL_RenderPresent(menu_renderer);
}
void Menu::handle(){
	if (menu_event->type == SDL_QUIT){
		*menu_isRun = false;
	}
	if (menu_event->type == SDL_KEYDOWN && menu_event->key.keysym.sym == SDLK_SPACE){
		next_game_state = TETRIS;
	}
	if (menu_event->type == SDL_KEYDOWN && menu_event->key.keysym.sym == SDLK_ESCAPE){
		*menu_isRun = false;
	}
	// ===== render_handle out-renderings logics , using the signal from renderings bool vars =====
	render_handle_out();

	// ===== render_handle in-renderings logics , handling renderings ' selves signals for render =====
	render_handle_in();

}

void Menu::update(){

}

bool Menu::onEnter(){
	std::cout << "\n===== Menu State =====\n";
	return true;
}
bool Menu::onExit(){
	std::cout << "\n===== Menu Out~s =====\n";
	return true;
}


// ===== render function =====

void Menu::render_init(){
	bg = new image("pic/fl01.jpg", menu_renderer);
	Start = new textBox_ColorChange("START", "pic/font/gamer.ttf", { 150,0,20 }, { 250, 150, 0 }, 60, menu_renderer, menu_event, 430, 200);
	start_note = new textBox("1 space bar 1", "pic/font/gamer.ttf", { 100, 100, 100 }, 20, menu_renderer);

	Exit = new textBox_ColorChange("EXIT", "pic/font/gamer.ttf", { 150, 0, 20 }, { 250, 150, 0 }, 60, menu_renderer, menu_event, 430, 300);
	exit_note = new textBox("1 escape 1", "pic/font/gamer.ttf", { 100, 100, 100 }, 20, menu_renderer);

	title_add1 = new textBox("another", "pic/font/gamer.ttf", { 200, 200, 200 }, 20,menu_renderer);
	title = new textBox("TETRIS", "pic/font/gamer.ttf", { 250, 10, 50 }, 70, menu_renderer);
	title_add2 = new textBox("game", "pic/font/gamer.ttf", { 200, 200, 200 }, 20, menu_renderer);

	bubb = new bubble(menu_renderer);
	VGU = new textBox("VGU", "pic/font/gamer.ttf", { 250, 150, 50 },30, menu_renderer);
}

// ----- handle -----
void Menu::render_handle_in(){
	Start->handle();
	Exit->handle();
}

void Menu::render_handle_out(){
	if (Start->isClick() && Start->isPointed){
		next_game_state = TETRIS;
	}
	if (Exit->isClick() && Exit->isPointed){
		*menu_isRun = false;
	}
}

void Menu::render_render(){
	bg->draw(0,50, menu_width -150, menu_height+50);
	Start->render(430, 200);
	start_note->render(430, 260);

	Exit->render(430, 300);
	exit_note->render(430, 360);

	title_add1->render(title->dst.x, 10);
	title->render(150, 30);
	title_add2->render(title->dst.x + title->src.w - title_add2->src.w, 93);

	bubb->render();
	VGU->render(640-VGU->src.w-10,480-VGU->src.h-10);
}

void Menu::render_clean(){
	delete bg;
	delete Start;
	delete start_note;

	delete Exit;
	delete exit_note;

	delete title_add1;
	delete title;
	delete title_add2;
}