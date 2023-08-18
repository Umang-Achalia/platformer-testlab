#include <raylib.h>
#include "Game.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

Game* game = nullptr;

int main() {
	game = new Game;
	game->init(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib");

	while (!WindowShouldClose()) {
		game->handleEvent();
		game->update();
		game->render();
	}
	game->clean();
}