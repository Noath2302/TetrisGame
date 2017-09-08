#include "textBox.h"


textBox::textBox(const char* textInput, const char* fontType, SDL_Color textColor, int textSize, SDL_Renderer *textRenderer)
{
	text_color = textColor;
	updated = false;
	TTF_Init();
	textBox::textInput = textInput;
	textBox::fontType = fontType;
	textBox::textSize = textSize;
	
	textBox::textRenderer = textRenderer;

	SDL_Surface *message;
	font = TTF_OpenFont(textBox::fontType, textBox::textSize);

	TTF_SetFontStyle(font, NULL);
	message = TTF_RenderText_Blended(font,textBox::textInput,textColor);

	textTexture = SDL_CreateTextureFromSurface(textBox::textRenderer,message);
	SDL_FreeSurface(message);

	SDL_QueryTexture(textTexture, NULL, NULL, &src.w, &src.h);
	src.x = src.y = 0;
	dst.h = src.h;
	dst.w = src.w;
}

textBox::~textBox()
{
	SDL_DestroyTexture(textTexture);
	textRenderer = NULL;
	font = NULL;
}

void textBox::render(int pX, int pY){
	dst.x = pX;
	dst.y = pY;
	SDL_RenderCopy(textRenderer, textTexture, &src, &dst);
}
void textBox::render_fading(int pX, int pY){
	SDL_SetTextureAlphaMod(textTexture, ((SDL_GetTicks() / 100) % 16)*16);
	render(pX, pY);
}
void textBox::update_text(const char* textInput, SDL_Color text_color){
		textBox::textInput = textInput;
		SDL_Surface *message;
		font = TTF_OpenFont(textBox::fontType, textBox::textSize);

		TTF_SetFontStyle(font, NULL);
		message = TTF_RenderText_Solid(font, textBox::textInput, text_color);
		SDL_DestroyTexture(textTexture);
		textTexture = SDL_CreateTextureFromSurface(textBox::textRenderer, message);
		SDL_FreeSurface(message);

		SDL_QueryTexture(textTexture, NULL, NULL, &src.w, &src.h);
		src.x = src.y = 0;
		dst.h = src.h;
		dst.w = src.w;
		updated = true;
}
