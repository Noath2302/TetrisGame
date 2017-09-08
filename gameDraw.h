#pragma once
#include "textTure.h"
#include "textBox.h"
#include "numBox.h"
enum drawType {BLOCK,COLL};
class gameDraw
{
public:
	gameDraw(SDL_Renderer *renderer);
	~gameDraw();

	SDL_Renderer *renderer;

	void DrawRectangle(int upLeftX, int upLeftY, int downRightX, int downRightY, drawType type);
	int GetKey();
	void renderHint();

	textBox *title;
	image *bg;
	numBox *pointBox;
	textBox *next;
	textBox *score;

	textBox *rotate;
	textBox *drop;
	textBox *pause;
	textBox *control;
	image *arrow;

	textBox *VGU;

	int timehint;
private:
	// ===== for drawregtangle =====
	image *coll;
	image *block;
	
};

