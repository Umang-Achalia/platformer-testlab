#pragma once

#include <SDL.h>
#include "Game.h"

extern float speedX;
extern float speedY;

class Entity {
private:
	SDL_Rect p_rect;
	SDL_Rect top, bottom, left, right;

public:
	void drawPlayer(int, int, int, int);
	SDL_Rect* getRect() { return &p_rect; }
};
