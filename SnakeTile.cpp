#include "SnakeTile.h"

SnakeTile::SnakeTile(int _n) : Tile(_n) { }

SnakeTile::~SnakeTile() { }

string SnakeTile::getType() { return "S"; }