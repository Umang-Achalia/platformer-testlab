#include "Game.h"

SDL_Renderer* gRenderer = nullptr; // ~ this is a definition

Entity* player = nullptr;
Entity* tile = nullptr;

vector <Entity*> walls{}; // dynamic vector that stores instances of class Body

int shift = 0;

void Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (mWindow != NULL) {

			gRenderer = SDL_CreateRenderer(mWindow, -1, 0);

			isRunning = true;
		}
	}
	player = new Entity;
}

void Game::handleEvents() {

	SDL_Event event; // SDL_Event class can only ever have one object

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}

void Game::update() {
	player->loadTexture("assets/tard/tard_00.png");
	for (int count = 0; count < 5; count++) {
		walls.push_back(new Entity());
		walls[count]->loadTexture("assets/grass_tile.png");
	}
	shift += 15;
	player->giveRect()->y += shift; 
}

void Game::render() {
	int x_increment = 320;

	SDL_RenderClear(gRenderer);
	// --------------------------

	player->drawTexture(300, 150, 4);

	for (int count = 0; count < 5; count++) {
		walls[count]->drawTexture(x_increment, 350, 2); 
		x_increment += (24 * 2);
	}

	for(int count=0;count<5;count++)
	{
		if (SDL_HasIntersection(player->giveRect(), walls[count]->giveRect())) { // same as ~ tile->giveRect()
			player->giveRect()->y = walls[count]->giveRect()->y - walls[count]->giveRect()->h;
		}
	}

	// --------------------------
	SDL_SetRenderDrawColor(gRenderer, 64, 64, 64, 1);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}