#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef TILE
#define TILE

class Tile {
private:
	friend class Board;
	int number;
	string type = "N";
	void setType(string _type);

public:
	Tile();
	Tile(int _number);
	~Tile();

	string toString();
	int getNumber();
	virtual string getType();
	void setNumber(int _n);
};

#endif // !TILE