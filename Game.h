#pragma once
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Dice.h"

using namespace std;

#ifndef GAME
#define GAME
#define MAX_TURN 20
#define PLAYERS 2
#define REWARD 3
#define PENALTY 3

class Game {
private:
	Board* board = new Board();
	Dice* dice = new Dice();
	Player* players[PLAYERS];

	int playersTurn = 0;
	int totalTurns = 1;
	bool isGameover = false;

	void Updated();
	void Close();

	void Move();
	void CheckGameOver();
	void Continue();
	void CheckPlayersTurns();
public:
	Game();
	~Game();

	void Start();
};

#endif // !GAME