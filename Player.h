#pragma once

#include <SDL.h>

class Player {
private:
	SDL_Rect rect;
public:
	void drawPlayer();
	void setRect(int x, int y, int w, int h);
	void update();
	SDL_Rect* getRect() { return &rect; }
};