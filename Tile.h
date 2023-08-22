#pragma once

#include <SDL.h>

class Tile {
private:
	SDL_Rect tile;

public:
	Tile(int x, int y, int w, int h);
	void drawTile();
	SDL_Rect* getTile() { return &tile; }
};