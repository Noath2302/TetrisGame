#pragma once 
#include "textBox.h"
#include <vector>
#include "function.h"

class numBox
{
public:
	numBox(SDL_Renderer *num_renderer,const char* font, SDL_Color Color, int size, int num = 0);
	~numBox();

	void num_render(int num,int pX,int pY);
	SDL_Renderer *num_renderer;
private:
	int num;
	std::vector<textBox*> num_array;
};

