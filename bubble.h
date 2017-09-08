#pragma once
#include "textBox.h"
#include "textTure.h"
class bubble
{
public:
	bubble(SDL_Renderer *renderer, const char* font = "pic/font/atwriter.ttf");
	~bubble();

	void render();
	SDL_Renderer *bub_renderer;
private:
	textBox *u;
	textBox *dots;
	textBox *wanna;
	textBox *play;

	image *bub;
	int time;
	int time2;
};

