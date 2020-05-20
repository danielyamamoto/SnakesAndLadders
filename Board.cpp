#include "Board.h"

Board::Board() {
	for (int t = 1; t <= TILES; t++) {
		tiles[t - 1] = new Tile(t, NAME_TILE);
	}

	for (int s = 1; s <= SNAKES; s++) {
		int snakeRandom = rand() % TILES;
		do {
			snakeRandom = rand() % TILES;
			} while (tiles[snakeRandom]->getType() == "S");
		tiles[snakeRandom]->setType("S");
	}

	for (int l = 1; l <= LADDERS; l++) {
		int ladderRandom = rand() % (TILES-3);
		do {
			ladderRandom = rand() % (TILES-3);
		} while (tiles[ladderRandom]->getType() == "L" && tiles[ladderRandom]->getType() == "S");
		tiles[ladderRandom]->setType("L");
	}
}

Board::~Board() { }

string Board::toString() {
	string msg = "";
	
	for (int t = 0; t < TILES; t++) {
		msg += tiles[t]->toString();
		msg += "\t";
		if ((t+1) % 10 == 0)
			msg += "\n";
	}

	return msg;
}

string Board::getTile(int pos) { 
	return tiles[pos]->getType();  
}

void Board::setPlayer(int prevPos, int newPos, string type) { 
	tiles[prevPos - 1]->setType(NAME_TILE);
	tiles[newPos]->setType(type); 
}