#pragma once

#include <iostream>
#include "Tile.h"
#include <vector>
using namespace std;

extern vector < Tile* > group_of_tiles;

class TileMap {
private:
	
public:
	void create_level(const char*[]);
};
