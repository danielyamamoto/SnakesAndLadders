#pragma once
#include <iostream>
#include "Tile.h"

using namespace std;

#ifndef SNAKE_TILE
#define SNAKE_TILE

class SnakeTile : public Tile {
public:
	SnakeTile(int _n);
	~SnakeTile();

	string getType();
};

#endif // !SNAKE_TILE