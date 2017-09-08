#include "textTure.h"


image::image(const char* pic_direc, SDL_Renderer *render) :renderer(render)
{
	SDL_Surface *temp = IMG_Load(pic_direc);
	texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);

	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
	src.x = src.y = 0;
}


image::~image()
{
	SDL_DestroyTexture(texture);
	renderer = NULL;
}

void image::draw(int upLeftX, int upLeftY, int downRightX, int downRightY){
	dst.x = upLeftX;
	dst.y = upLeftY;
	dst.w = downRightX - upLeftX;
	dst.h = downRightY - upLeftY;
	SDL_RenderCopy(renderer, texture, &src, &dst);
}