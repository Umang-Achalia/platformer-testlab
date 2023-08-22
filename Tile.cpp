#include "Tile.h"
#include "ExternDecl.h"

Tile::Tile(int x, int y, int w, int h) {
	tile.x = x;
	tile.y = y;
	tile.w = w;
	tile.h = h;
}

void Tile::drawTile() {
	SDL_SetRenderDrawColor(gRenderer, 224, 165, 38, 1);
	SDL_RenderDrawRect(gRenderer, &tile);
	SDL_RenderFillRect(gRenderer, &tile);
}