#include "numBox.h"


numBox::numBox(SDL_Renderer *num_renderer, const char* font, SDL_Color Color, int size, int num):
num(num), num_renderer(num_renderer)
{
	for (int i = 0; i < 10; i += 1){
		num_array.push_back(new textBox((IntToString(i).c_str()), font, Color, size, num_renderer));
	}
}


numBox::~numBox()
{
	while (!num_array.empty()){
		delete num_array.back();
		num_array.pop_back();
	}
}

void numBox::num_render(int num,int pX,int pY){
	std::vector<int> numm;
	if (num == 0){
		num_array[0]->render(pX, pY);
		return;
	}
	while (num != 0){
		numm.push_back(num % 10);
		num /= 10;
	}
	int posX = pX;
	for (int i = numm.size() - 1; i >= 0; i -= 1){
		num_array[numm[i]]->render(posX, pY);
		posX += num_array[numm[i]]->src.w;
	}
}