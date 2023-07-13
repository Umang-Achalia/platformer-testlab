#include "Entity.h"

void Entity::loadTexture(const char* path) {
	texture = IMG_LoadTexture(gRenderer, path);
}

void Entity::drawTexture(int x_pos, int y_pos, int magnify) {
	src.x = 0;
	src.y = 0;

	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	dest.x = x_pos;

	dest.y = y_pos;

	dest.w = src.w * magnify;
	dest.h = src.h * magnify;

	SDL_RenderCopy(gRenderer, texture, &src, &dest);
}