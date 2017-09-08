#pragma once
#include "SDL_image.h"

class image
{
public:
	image(const char* pic_direc,SDL_Renderer *render);
	~image();
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Rect src, dst;

	void draw(int upLeftX, int upLeftY, int downRightX, int downRightY);

};

