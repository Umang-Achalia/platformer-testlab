#pragma once

#include <SDL.h>

extern SDL_Renderer* gRenderer; // ~ this is a declaration
extern SDL_Renderer* gRenderer; // ~ this is a declaration too. So, many declaraitons do not matter.
// extern - asks the compiler to look for definition of `SDL_Renderer* gRenderer' in other files.
// once declared, gRenderer can be used anywhere as long as this header is included.

class Game {
private:
	SDL_Window* mWindow = nullptr;
	bool isRunning = false;

public:
	void init(const char*, int, int, int, int, int);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
};