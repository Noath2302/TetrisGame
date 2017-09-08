#include "gameDraw.h"


gameDraw::gameDraw(SDL_Renderer *render) :renderer(render)
{
	block = new image("pic/sqr.png", renderer);
	coll = new image("pic/coll.png", renderer);
	bg = new image("pic/Night.jpg", renderer);

	pointBox = new numBox(renderer,"pic/font/typogarden-demo.ttf", { 200, 250, 50 }, 100);
	title = new textBox("Tetris", "pic/font/gamer.ttf", { 255, 50, 100 }, 50,renderer);

	next = new textBox("next piece :", "pic/font/gamer.ttf", { 255, 200, 100 }, 30, renderer);
	score = new textBox("score :", "pic/font/gamer.ttf", { 255, 200, 100 }, 30, renderer);

	rotate = new textBox("rotate  .z.", "pic/font/gamer.ttf", { 255, 180, 180 }, 20, renderer);
	drop = new textBox("drop     .x.", "pic/font/gamer.ttf", { 180, 255, 180 }, 20, renderer);
	pause = new textBox("pause .esc.", "pic/font/gamer.ttf", { 180, 180, 255 },20, renderer);
	control = new textBox("control key :", "pic/font/gamer.ttf", { 230, 230, 230 },25, renderer);
	arrow = new image("pic/arrow.png", renderer);

	VGU = new textBox("VGU", "pic/font/gamer.ttf", { 250, 150, 50 },30, renderer);
	timehint = 0;
}


gameDraw::~gameDraw()
{
	delete rotate;
	delete drop;
	delete control;
	delete arrow;
	delete pause;
		
	delete title;
	delete block;
	delete coll;
	delete bg;
	delete next;
	delete score;
}

int gameDraw::GetKey()
{
	SDL_Event event;
	while (true)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			break;
		if (event.type == SDL_QUIT)
			exit(3);
	};
	return event.key.keysym.sym;
}

void gameDraw::DrawRectangle(int upLeftX, int upLeftY, int downRightX, int downRightY, drawType type){
	switch (type)
	{
	case BLOCK:
		block->draw(upLeftX, upLeftY, downRightX, downRightY);
		break;
	case COLL:
		coll->draw(upLeftX, upLeftY, downRightX, downRightY);
		break;
	default:
		break;
	}
}

void gameDraw::renderHint(){
		rotate->render(10, 200);
		drop->render(10, 230);
		pause->render(10, 260);

		arrow->draw(10, 320, arrow->src.w + 10, arrow->src.h + 320);
		control->render(30, 320);

		VGU->render(640 - VGU->src.w - 10, 480 - VGU->src.h - 10);
}