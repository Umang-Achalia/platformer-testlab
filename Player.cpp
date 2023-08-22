#include "Player.h"
#include "ExternDecl.h"

void Player::setRect(int x, int y, int w, int h) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Player::drawPlayer() {
	SDL_SetRenderDrawColor(gRenderer, 0, 163, 225, 1);
	SDL_RenderDrawRect(gRenderer, &rect);
	SDL_RenderFillRect(gRenderer, &rect);
}

void Player::update() {
	// HORIZONTAL MOVEMENT
	rect.x += speedX;
	rect.y += speedY;
}