#include "Player.h"
#include "ExternDecl.h"

void Player::drawPlayer(int x, int y, int w, int h, Color color) {
	x += move;
	DrawRectangle(x, y, w, h, color);
}