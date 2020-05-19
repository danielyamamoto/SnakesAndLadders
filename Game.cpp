#include "Game.h"

Game::Game() {
	playersTurn = 0;
	isGameover = false;

	for (int i = 0; i < PLAYERS; i++) {
		string name;
		cout << "What's the name of the player: ";
		getline(cin, name);
		players[i] = new Player(name);
	}
}

Game::~Game() { }

void Game::Start() {
	Updated();
	Close();
}

void Game::Updated() {
	while (!isGameover) {
		cout << "Is the turn of " + players[playersTurn]->getName() << endl;
		Move();
		board->setPlayer(players[playersTurn]->getPrevPos(), players[playersTurn]->getPos() - 1, to_string(playersTurn + 1));
		cout << board->toString() << endl;
		CheckGameOver();
		WhoPlayerIsPlaying();
		system("CLS");
	}
}

void Game::Close() {
	cout << "GAMEOVER!" << endl;
	cout << players[playersTurn]->getName() + " is the winner!" << endl;
	system("PAUSE");
}

void Game::Move() {
	int tempMove = dice->getRoll();
	cout << "Player actual box: " +  to_string(players[playersTurn]->getPos()) << endl;
	cout << "Dice: " + to_string(tempMove) << endl;
	int tempPosPlayer = players[playersTurn]->getPos();
	tempPosPlayer += tempMove;
	
	if (tempPosPlayer >= TILES) {
		tempPosPlayer = TILES;
		players[playersTurn]->setPos(tempPosPlayer); 
	}
	else {
		if (board->getTile(tempPosPlayer) == "S") {
			players[playersTurn]->setPos(tempPosPlayer - PENALTY);
			cout << "You found a snake, you return " + to_string(PENALTY) + " squares" << endl;
		}
		else if (board->getTile(tempPosPlayer) == "L") {
			players[playersTurn]->setPos(tempPosPlayer + REWARD);
			cout << "You found a ladder, you advance " + to_string(REWARD) + " boxes" << endl;
		}
		else { 	
			players[playersTurn]->setPos(tempPosPlayer); 
		}
	}

	cout << "Player new box: " + to_string(players[playersTurn]->getPos()) << endl;
}

void Game::CheckGameOver() {
	if (players[playersTurn]->getPos() >= TILES)
		isGameover = true;
	else
		Continue();
}

void Game::Continue() {
	string temp;
	do {
		cout << "Press C to continue next turn or E to end the game: " << endl;
		getline(cin, temp);
		if (temp == "E")
			exit(0);
	} while (temp != "C");
}

void Game::WhoPlayerIsPlaying() {
	if (players[playersTurn]->getPos() < TILES) {
		if (playersTurn >= PLAYERS - 1)
			playersTurn = 0;
		else
			playersTurn++;
	}
}