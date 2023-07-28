#pragma once

#include <SDL.h>

class Tile {
private:
	SDL_Rect t_rect;

public:
	Tile(int, int);
	SDL_Rect* getTile() { return &t_rect; }
};
