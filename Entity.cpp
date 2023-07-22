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

void Entity::drawTile(int x, int y, int w, int h) {
	t_rect.x = x;
	t_rect.y = y;
	t_rect.w = w;
	t_rect.h = h;

	SDL_SetRenderDrawColor(gRenderer, 251, 219, 101, 1);
	SDL_RenderDrawRect(gRenderer, &t_rect);
	SDL_RenderFillRect(gRenderer, &t_rect);
}

bool Entity::isColliding(SDL_Rect* player, SDL_Rect* tile) {
	
	int top, bottom, left, right;
	int top2, bottom2, left2, right2;

	top = player->y;
	bottom = player->y + player->h;
	left = player->x;
	right = player->x + player->w;

	top2 = tile->y;
	bottom2 = tile->y + tile->h;
	left2 = tile->x;
	right2 = tile->x + tile->w;

	if (bottom < top2 || top > bottom2 || right < left2 || left > right2) {
		return false;
	}
	return true;
	/*
	if (SDL_HasIntersection(player, tile)) {
		return true;
	}
	return false;
	*/
}