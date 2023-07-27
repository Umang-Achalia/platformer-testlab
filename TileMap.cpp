#include "TileMap.h"

void TileMap::create_level(const char* tileMap[]) {
	for (int count = 0; count < 10; count++) {
		for (int index = 0; index < 29; index++) {
			if (tileMap[count][index] == 'X') {
				int x, y;
				x = count * 50;
				y = index * 50;
				new Tile(x, y);
			}
		}
	}
}