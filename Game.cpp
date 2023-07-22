#include "Game.h"

SDL_Renderer* gRenderer = nullptr; // ~ this is a definition

Entity* player = nullptr;
Entity* newT = nullptr;

int speedX = 0;
int lt_accel = 0;
int rt_accel = 0;

int speedY = 0;
int jumpStr = 26;
int gravity = 2;

int up = 0;
int collision = 1;

void Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (mWindow != NULL) {

			gRenderer = SDL_CreateRenderer(mWindow, -1, 0);

			isRunning = true;
		}
	}
	player = new Entity();
	newT = new Entity();
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
	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_d)]) {
		rt_accel++;
	}
	else {
		rt_accel = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_a)]) {
		lt_accel++;
	}
	else {
		lt_accel = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_SPACE)]) {
		up = 1;
		gravity = 0;
	}
	else {
		up = 0;
	}

	if (player->isColliding(player->getRect(), newT->getTile())) {
		gravity = 0;
		collision = 0;
	}
	else {
		collision = 1;
	}

	speedX += rt_accel - lt_accel;
	gravity++;
	speedY += (gravity * collision) - (jumpStr * up);
}

void Game::render() {
	SDL_RenderClear(gRenderer);
	// --------------------------

	player->drawPlayer(200, 100, 50, 50);
	newT->drawTile(400, 300, 100, 40);

	// --------------------------
	SDL_SetRenderDrawColor(gRenderer, 64, 64, 64, 1);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}