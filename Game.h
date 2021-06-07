#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Dice.h"

using namespace std;

#ifndef GAME
#define GAME

class Game {
private:
	Board* board;
	Dice* dice = new Dice();
	vector<Player*>players;

	int reward;
	int penalty;
	int nPlayers;
	int maxTurns;
	string gameType;

	int playersTurn;
	int totalTurns;
	bool isGameover;

	void Updated();
	void Close();

	void Move();
	void CheckGameOver();
	void Continue();
	void CheckPlayersTurns();

public:
	Game(int _nTiles, int _nSnakes, int _nLadders, int _penalty, int _reward, int _nPlayers, int _maxTurns, string _gameType);
	~Game();

	void Start();
};

#endif // !GAME