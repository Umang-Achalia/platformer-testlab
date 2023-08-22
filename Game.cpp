#include "Game.h"
#include <SDL.h>
#include "ExternDecl.h"
#include "Player.h"
#include "Tile.h"

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

Player* player = nullptr;

Tile* tile1 = nullptr;
Tile* tile2 = nullptr;
Tile* tile3 = nullptr;

// HORIZONTAL
float runStrR = 0.0f;
float runStrL = 0.0f;
float speedX = 0.0f;

// VERTICAL
float speedY = 0.0f;
float gravity = 5.2f;
float jumpStr = 15.2f;

// flags
int right = 0;
int left = 0;
int up = 0;

void Game::init(const char* title, int x, int y, int w, int h, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		// create window
		gWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		// if window created successfully
		if (gWindow != NULL) {
			// create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

			isRunning = true;
		}
		player = new Player();
		player->setRect(540, 250, 50, 100);

		tile1 = new Tile(500, 300, 50, 50);
		tile2 = new Tile(550, 300, 50, 50);
		tile3 = new Tile(600, 300, 50, 50);
	}
}

void Game::handleEvent() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {

		switch (ev.type) {

		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}

void Game::update() {
	player->update();

	// if right key pressed
	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_d)]) {
		right = 1; // right flag is set
	}
	else {
		runStrR = 0; // right-speed is reset
		right = 0; // right flag is reset
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_a)]) {
		left = 1;
	}
	else {
		runStrL = 0;
		left = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_SPACE)]) {
		up = 1;
		gravity = 0;
	}

	runStrR += 0.5; // right-speed is incremented
	runStrL += 0.5;

	gravity += 1.5f;

	// HORIZONTAL
	speedX = (runStrR * right) - (runStrL * left);

	// VERTICAL
	speedY = gravity - (jumpStr * up);
}

void Game::render() {
	SDL_RenderClear(gRenderer);
	//-------------------------------------------
	player->drawPlayer();
	tile1->drawTile();
	tile2->drawTile();
	tile3->drawTile();
	//-------------------------------------------
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 1);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}