#pragma once
#include "SDL_ttf.h"
#include "function.h"

class textBox
{
public:
	textBox(const char* textInput, const char* fontType, SDL_Color textColor,int textSize, SDL_Renderer *textRenderer);
	~textBox();

	SDL_Texture *textTexture;
	SDL_Renderer *textRenderer;
	TTF_Font *font;

	SDL_Rect src, dst;

	bool updated;
	void render(int pX,int pY);
	void update_text(const char* inputText, SDL_Color textColor);
	void render_fading(int pX,int pY);

	const char* textInput;
protected:
	int textSize;
	const char* fontType;
	SDL_Color text_color;
};

