#include "Tile.h"

Tile::Tile() {
	number = 0;
	type = "?";
}

Tile::Tile(int _number, string _type) {
	number = _number;
	type = _type;
}

Tile::~Tile() { }

string Tile::toString() { return type; }

int Tile::getNumber() { return number; }

string Tile::getType() { return type; }

void Tile::setNumber(int _n) { number = _n; }

void Tile::setType(string _t) { type = _t; }