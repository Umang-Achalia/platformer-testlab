#include "Game.h"

SDL_Renderer* gRenderer = nullptr; // ~ this is a definition

Entity* player = nullptr;
Entity* newT = nullptr;

SDL_Rect intersect;

SDL_Rect sink = {400, 100, 27, 27};

float speedX = 0;
float lt_accel = 0;
float rt_accel = 0;
float maxX = 25.2f;

float speedY = 0;
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

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				up = 1;
				gravity = 0;
				continue;
			}

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				up = 0;
				continue;
			}
		}
	}
}

void Game::update() {
	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_d)]) {
		rt_accel++;
		if (rt_accel >= maxX) { rt_accel = maxX; }
	}
	else {
		rt_accel = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_a)]) {
		lt_accel++;
		if (lt_accel <= -maxX) { lt_accel = -maxX; }
	}
	else {
		lt_accel = 0;
	}

	/*
	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_SPACE)]) {
		up = 1;
		gravity = 0;
	}
	else {
		up = 0;
	}
	*/

	if (SDL_IntersectRect(player->getRect(), newT->getTile(), &intersect)) {

		// comparing height: top / bottom
		if (intersect.h <= sink.h) {

			// top collision special if
			if(intersect.y == sink.y){
				gravity = 0;
				collision = 0;
				speedY -= intersect.h ;
			}
			
			// bottom collision special if
			if (intersect.y > (sink.y + 1)) {
				gravity = 0;
				up = 0;
				jumpStr = 0;
				speedY += (intersect.h);
			}
		}

		// coparing width: left / right
		if (intersect.w <= sink.w && intersect.y >= (sink.y + 1)) {

			// left special condition
			if(intersect.x == sink.x) {
				gravity = 0;
				rt_accel = 0;
				speedX -= intersect.w;
			}

			// right special condition
			if (intersect.x > sink.x) {
				gravity = 0;
				lt_accel = 0;
				speedX += intersect.w;
			}
		}
	}
	else {
		collision = 1;
		jumpStr = 26;
	}

	speedX += rt_accel - lt_accel;
	gravity++;
	speedY += (gravity * collision) - (jumpStr * up);
}

void Game::render() {
	SDL_RenderClear(gRenderer);
	// --------------------------

	player->drawPlayer(200, 100, 50, 50);
	newT->drawTile(400, 100, 100, 300);

	// --------------------------
	SDL_SetRenderDrawColor(gRenderer, 64, 64, 64, 1);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}