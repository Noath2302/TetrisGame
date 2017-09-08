#include "bubble.h"


bubble::bubble(SDL_Renderer *renderer,const char* font):
bub_renderer(renderer)
{
	u = new textBox("Happy", font, {0,0,0},50,renderer);
	dots = new textBox("...", font, { 0, 0, 0 }, 50, renderer);;
	wanna = new textBox("BD", font, { 0, 0, 0 }, 50, renderer);;
	play = new textBox("Khoi", font, { 0, 0, 0 }, 50, renderer);

	bub = new image("pic/bubble.png",renderer);
	time = SDL_GetTicks();
	time2 = 0;
}


bubble::~bubble()
{
	delete u;
	delete dots;
	delete wanna;
	delete play;
	delete bub;
}

void bubble::render(){
	// ===== sequence of dialog =====
		bub->draw(400, 50, 600, 200);
		time2 = SDL_GetTicks();
	if (time2%10000 < 2000){
		u->render(bub->dst.x + bub->dst.w / 2 - u->src.w / 2, bub->dst.y + bub->dst.h / 2 - u->src.h / 2 -10);
	}
	else if (time2%10000 < 3000){
		wanna->render_fading(bub->dst.x + bub->dst.w / 2 - wanna->src.w / 2, bub->dst.y + bub->dst.h / 2 - wanna->src.h / 2 -10);
	}
	else if (time2%10000 < 4500){
		play->render(bub->dst.x + bub->dst.w / 2 - play->src.w / 2, bub->dst.y + bub->dst.h / 2 - play->src.h / 2 - 10);
	}
	else{
		dots->render_fading(bub->dst.x + bub->dst.w / 2 - dots->src.w / 2, bub->dst.y + bub->dst.h / 2 - dots->src.h / 2 -10);
	}
}