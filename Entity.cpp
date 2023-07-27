#include "Entity.h"

void Entity::drawPlayer(int x, int y, int w, int h) {
	p_rect.x = x;
	p_rect.x += speedX;
	p_rect.y = y;
	p_rect.y += speedY;
	p_rect.w = w;
	p_rect.h = h;

	SDL_SetRenderDrawColor(gRenderer, 0, 138, 216, 1);
	SDL_RenderDrawRect(gRenderer, &p_rect);
	SDL_RenderFillRect(gRenderer, &p_rect);
}