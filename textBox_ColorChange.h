#pragma once
#include "textBox.h"
class textBox_ColorChange
{
public:
	textBox_ColorChange(const char* textInput, const char* font, SDL_Color normalColor, SDL_Color pointedColor, int fontSize, SDL_Renderer *textRenderer, SDL_Event *textEvent, int pX, int pY);
	~textBox_ColorChange();

	// ===== render function for coloralter text  =====
	void render(int pX,int Py);
	void handle();
	bool isClick();

	bool isPointed;

	SDL_Point mouse_cursor;
	SDL_Point text_coord;

	textBox *textNormal;
	textBox *textPointed;
private:
	SDL_Renderer *textRenderer;
	SDL_Event *textEvent;

	

	
};

