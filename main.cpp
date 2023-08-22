#include <iostream>
#include <SDL.h>
#include "Game.h"

const int WIN_WIDTH = 1080;
const int WIN_HEIGHT = 720;

const int FPS = 60;
const int delayTime = 1000.0f / FPS;

Game* game = nullptr;

int main(int num_args, char* argv[]) {
	Uint32 frameStart, frameTime;

	game = new Game();

	// initialize everything
	game->init("TEST RUN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);

	// Game looop
	while (game->running() == true) { 
		frameStart = SDL_GetTicks();

		game->handleEvent();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < delayTime) {
			SDL_Delay((int)(delayTime - frameTime));
		}
	}
	game->clean();

	return 0;
}