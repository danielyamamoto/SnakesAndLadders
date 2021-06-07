#include "Board.h"

Board::Board(int _tiles, int _snakes, int _ladders) {
	nTiles = _tiles;

	for (int t = 0; t < nTiles; t++) {
		tiles.push_back(new Tile(t));
	}

	for (int s = 0; s < _snakes; s++) {
		int snakeRandom = rand() % nTiles;
		tiles[snakeRandom] = new SnakeTile(snakeRandom);
	}

	for (int l = 0; l < _ladders; l++) {
		int ladderRandom = rand() % (nTiles - _ladders);
		do {
			int ladderRandom = rand() % (nTiles - _ladders);
		} while (ladderRandom == tiles[l]->getNumber());
		tiles[ladderRandom] = new LadderTile(ladderRandom);
	}
}

Board::~Board() { }

string Board::toString() {
	string msg = "";
	
	for (int t = 0; t < nTiles; t++) {
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
	tiles[prevPos]->setType("N");
	tiles[newPos]->setType(type);
}

int Board::getNumberTiles() { return nTiles; }