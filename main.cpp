#include "Game.h"

const int SCREEN_WIDTH = 900; 
const int SCREEN_HEIGHT = 500;

const int FPS = 60; 
const int desired_delta = 1000 / FPS; 

Game* game = nullptr;

int main(int num_args, char* argv[]) {

	int start_loop, delta;

	game = new Game();
	game->init("SDL EXP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	while (game->running()) {

		// SDL_GetTicks() - gives time passed since SDL initialization
		start_loop = SDL_GetTicks(); 

		game->handleEvents();
		game->update();
		game->render();

        // delta = (time passed since SDL initialization + time to process one frame) - time passed since SDL initialization
        // i.e, time for one frame = total time - time passed since SDL initialization
		delta = SDL_GetTicks() - start_loop;

		if (delta < desired_delta) {
			SDL_Delay(desired_delta - delta);
		}

	}
	game->clean();
	return 0;
}