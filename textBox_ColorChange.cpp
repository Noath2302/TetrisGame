#include "textBox_ColorChange.h"


textBox_ColorChange::textBox_ColorChange(const char* textInput, const char* font, SDL_Color normalColor, SDL_Color pointedColor, int fontSize, SDL_Renderer *textRenderer, SDL_Event *textEvent,int pX, int pY) :
textEvent(textEvent), textRenderer(textRenderer)
{
	text_coord.x = pX;
	text_coord.y = pY;
	textNormal = new textBox(textInput, font, normalColor, fontSize, textRenderer);
	textPointed = new textBox(textInput, font, pointedColor, fontSize, textRenderer);
	isPointed = false;
}


textBox_ColorChange::~textBox_ColorChange()
{
	delete textNormal;
	delete textPointed;

	textRenderer = NULL;
	textEvent = NULL;
}

void textBox_ColorChange::render(int pX,int pY){
	text_coord.x = pX;
	text_coord.y = pY;
	if (isPointed){
		textPointed->render(pX, pY);
	}
	else{
		textNormal->render(pX, pY);
	}
}
void textBox_ColorChange::handle(){
	if (textEvent->type == SDL_MOUSEMOTION){
		SDL_GetMouseState(&mouse_cursor.x,&mouse_cursor.y);
	}
	if ((mouse_cursor.x > text_coord.x && mouse_cursor.x < text_coord.x + textNormal->dst.w) &&
		(mouse_cursor.y > text_coord.y && mouse_cursor.y < text_coord.y + textNormal->dst.h)){
		isPointed = true;
	}
	else {
		isPointed = false;
	}
}

bool textBox_ColorChange::isClick(){
	if ( (textEvent->type == SDL_MOUSEBUTTONDOWN && textEvent->button.button == SDL_BUTTON_LEFT) && isPointed){
		return true;
	}
	return false;
}