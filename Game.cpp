#include "Game.h"

SDL_Renderer* gRenderer = nullptr; // ~ this is a definition

Entity* player = nullptr;
Entity* newT = nullptr;

SDL_Rect intersect;

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
		if (SDL_IntersectRect(player->getRect(), newT->getTile(), &intersect)) {
			int left, right2;
	
			left = player->getRect()->x;

			right2 = newT->getTile()->x + newT->getTile()->w;

			if (left <= right2) {
				up = 0;
				speedY += (intersect.h);
			}
		}
	}
	else {
		lt_accel = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_SPACE)]) {
		up = 1;
		gravity = 0;

		if (SDL_IntersectRect(player->getRect(), newT->getTile(), &intersect)) {
			int top, bottom2;

			top = player->getRect()->y;

			bottom2 = newT->getTile()->y + newT->getTile()->h;

			if (top <= bottom2) {
				up = 0;
				speedY += (intersect.h);
			}
		}
	}
	else {
		up = 0;
	}

	if (SDL_IntersectRect(player->getRect(), newT->getTile(), &intersect)) {
		int top, bottom, left, right;
		int top2, bottom2, left2, right2;

		top = player->getRect()->y;
		bottom = player->getRect()->y + player->getRect()->h;
		left = player->getRect()->x;
		right = player->getRect()->x + player->getRect()->w;

		top2 = newT->getTile()->y;
		bottom2 = newT->getTile()->y + newT->getTile()->h;
		left2 = newT->getTile()->x;
		right2 = newT->getTile()->x + newT->getTile()->w;

		if (bottom >= top2) {
			gravity = 0;
			collision = 0;
			speedY -= (intersect.h - 1);
		}

		/*
		if (top <= bottom2) {
			up = 0;
			speedY += (intersect.h);
		}
		*/

		if (right >= left2) {
			gravity = 0;
			speedX -= intersect.w;
		}
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