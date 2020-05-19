#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef TILE
#define TILE

class Tile {
private:
	int number;
	string type;

public:
	Tile();
	Tile(int _number, string _type);
	~Tile();

	string toString();
	int getNumber();
	string getType();

	void setNumber(int _n);
	void setType(string _t);
};

#endif // !TILE