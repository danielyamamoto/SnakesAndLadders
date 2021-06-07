#pragma once
#include <iostream>
#include "Tile.h"

using namespace std;

#ifndef LADDER_TILE
#define LADDER_TILE

class LadderTile : public Tile {
public:
	LadderTile(int _n);
	~LadderTile();

	string getType();
};

#endif // !LADDER_TILE