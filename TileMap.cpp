#include "TileMap.h"

void TileMap::create_level(const char* tileMap[]) {
	for (int count = 0; count < 10; count++) {
		for (int index = 0; index < 28; index++) {
			if (tileMap[count][index] == 'X') {
				int x, y;
				x = index * 50;
				y = count * 50;	
				group_of_tiles.push_back(new Tile(x, y));
			}
		}
	}
}