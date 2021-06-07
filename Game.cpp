#include "Game.h"

Game::Game(int _nTiles, int _nSnakes, int _nLadders, int _penalty, int _reward, int _nPlayers, int _maxTurns, string _gameType) {
	board = new Board(_nTiles, _nSnakes, _nLadders);
	
	reward = _reward;
	penalty = _penalty;
	nPlayers = _nPlayers;
	maxTurns = _maxTurns;
	gameType = _gameType;

	playersTurn = 0;
	isGameover = false;

	for (int i = 0; i < nPlayers; i++) {
		string name;
		cout << "What's the name of the player: ";
		cin >> name;
		players.push_back(new Player(name));
	}
}

Game::~Game() { }

void Game::Start() {
	Updated();
	Close();
}

void Game::Updated() {
	if (gameType == "A") {
		cout << "The simulation will run automatically" << endl;
		while (!isGameover && turn->getTotalTurns() <= maxTurns) {
			cout << "There are only #" + to_string(maxTurns) + " turns" << endl;
			cout << turn;
			cout << "Is the turn of Player #" + to_string(playersTurn+1) + " " + players[playersTurn]->getName() << endl;
			Move();
			board->setPlayer(players[playersTurn]->getPrevPos() - 1, players[playersTurn]->getPos() - 1, to_string(playersTurn + 1));
			board->toString();
			CheckGameOver();
			CheckPlayersTurns();
			system("CLS");
		}
	}
	else {
		cout << "The simulation will run manually " << endl;
		while (!isGameover) {
			cout << turn;
			cout << "Is the turn of Player #" + to_string(playersTurn + 1) + " " + players[playersTurn]->getName() << endl;
			Move();
			board->setPlayer(players[playersTurn]->getPrevPos() - 1, players[playersTurn]->getPos() - 1, to_string(playersTurn + 1));
			board->toString();
			CheckGameOver();
			CheckPlayersTurns();
			system("CLS");
		}
	}
}

void Game::Close() {
	cout << "GAMEOVER!" << endl;
	if (turn->getTotalTurns() >= maxTurns && gameType == "A")
		cout << "The  maximum  number  of  turns has  been reached..." << endl;
	else 
		cout << players[playersTurn]->getName() + " is the winner!" << endl;
	system("PAUSE");
}

void Game::Move() {
	int tempMove = dice->getRoll();
	cout << "Player actual box: " +  to_string(players[playersTurn]->getPos()) << endl;
	cout << "Dice: " + to_string(tempMove) << endl;
	int tempPosPlayer = players[playersTurn]->getPos();
	tempPosPlayer += tempMove;
	
	if (tempPosPlayer >= board->getNumberTiles()) {
		tempPosPlayer = board->getNumberTiles();
	}
	else {
		if (board->getTile(tempPosPlayer) == "S") {
			tempPosPlayer -= penalty;
			cout << "You found a snake, you return " + to_string(penalty) + " squares" << endl;
		}
		else if (board->getTile(tempPosPlayer) == "L") {
			tempPosPlayer += reward;
			cout << "You found a ladder, you advance " + to_string(reward) + " boxes" << endl;
		}
	}
	players[playersTurn]->setPos(tempPosPlayer); 
	cout << "Player new box: " + to_string(players[playersTurn]->getPos()) << endl;
}

void Game::CheckGameOver() {
	if (players[playersTurn]->getPos() >= board->getNumberTiles())
		isGameover = true;
	else
		Continue();
}

void Game::Continue() {
	string temp;
	do {
		cout << "Press C to continue next turn or E to end the game: " << endl;
		cin >> temp;
		if (temp == "E")
			exit(0);
	} while (temp != "C");
}

void Game::CheckPlayersTurns() {
	turn->AddTurn();
	if (players[playersTurn]->getPos() < board->getNumberTiles())
		if (playersTurn >= nPlayers - 1)
			playersTurn = 0;
		else
			playersTurn++;
}