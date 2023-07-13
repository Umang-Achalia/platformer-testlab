#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <map>
#include <vector>
using namespace std;

extern int shift;

class Entity {
private:
	SDL_Texture* texture;
	SDL_Rect src, dest;

public:
	void loadTexture(const char*);
	void drawTexture(int, int, int);
	SDL_Rect* giveRect() { return &dest; }
};
