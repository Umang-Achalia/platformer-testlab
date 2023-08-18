#include "Game.h"
#include "Player.h"
#include "ExternDecl.h"
#include <raylib.h>

Player* player = nullptr;
int move = 50;

void Game::init(int w, int h, const char* title) {
	InitWindow(w, h, title);
	SetTargetFPS(60);
	player = new Player();
}

void Game::handleEvent() {
	if (IsKeyPressed(KEY_D)) {
	}
}

void Game::update() {
	move += 10;
}

void Game::render() {
	BeginDrawing();
	ClearBackground(BLACK);
	//--------------------
	player->drawPlayer(490, 335, 100, 50, BLUE);
	//--------------------
	EndDrawing();
}

void Game::clean() {
	CloseWindow();
}