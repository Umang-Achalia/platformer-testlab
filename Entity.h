#pragma once

#include <SDL.h>
#include "Game.h"

extern int speedX;
extern int speedY;

extern int gravity;
extern int collision;

extern SDL_Rect intersect;

class Entity {
private:
	SDL_Rect p_rect;
	SDL_Rect t_rect;

public:
	void drawPlayer(int, int, int, int);
	void drawTile(int, int, int, int);
	SDL_Rect* getRect() { return &p_rect; }
	SDL_Rect* getTile() { return &t_rect; }
	bool isColliding(SDL_Rect*, SDL_Rect*);
};
