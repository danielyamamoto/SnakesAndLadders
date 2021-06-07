#include "LadderTile.h"

LadderTile::LadderTile(int _n) : Tile(_n) {	}

LadderTile::~LadderTile() { }

string LadderTile::getType() { return "L"; }