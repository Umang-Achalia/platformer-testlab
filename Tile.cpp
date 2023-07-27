#include "Tile.h"

const char* tile_map[10] = {
"                            ",
" XX    XXX            XX    ",
" XX                         ",
" XXXX          XX        XX ",
" XXXX        XX             ",
" XX    X  XXXX    XX   XX   ",
"       X  XXXX    XX   XXX  ",
"     XXX  XXXXXX  XX   XXXX ",
"XXXXXXXX  XXXXXX  XX   XXXX ",
};

Tile::Tile(int x, int y) {
	t_rect.x = x;
	t_rect.y = y;
	t_rect.w = 50;
	t_rect.h = 50;

	SDL_SetRenderDrawColor(gRenderer, 251, 219, 101, 1);
	SDL_RenderDrawRect(gRenderer, &t_rect);
	SDL_RenderFillRect(gRenderer, &t_rect);
}