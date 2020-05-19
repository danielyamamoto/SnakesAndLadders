#include "Player.h"

Player::Player() { 
	name = "???"; 
	pos = 1; 
}

Player::Player(string _name) {
	name = _name; 
	pos = 1;
}

Player::~Player() { }

string Player::getName() { return name; }

int Player::getPos() { return pos; }

int Player::getPrevPos() { return prevPos; }

void Player::setPos(int _pos) { 
	prevPos = pos;
	pos = _pos;
	
	if (pos < 1)
		pos = 1;
}