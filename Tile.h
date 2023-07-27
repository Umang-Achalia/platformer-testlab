#pragma once

#include <SDL.h>
#include "Game.h"
#include "Layout.h"
using namespace std;

class Tile {
private:
	SDL_Rect t_rect;

public:
	Tile(int, int);
	SDL_Rect* getTile() { return &t_rect; }
};
