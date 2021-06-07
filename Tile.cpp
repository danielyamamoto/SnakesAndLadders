#include "Tile.h"

Tile::Tile() { number = 0; }

Tile::Tile(int _number) { number = _number; }

Tile::~Tile() { }

string Tile::toString() { return getType(); }

int Tile::getNumber() { return number; }

string Tile::getType() { return type; }

void Tile::setNumber(int _n) { number = _n; }

void Tile::setType(string _type) { type = _type; }