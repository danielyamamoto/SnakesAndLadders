#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

using namespace std;

int main() {
	srand(time(NULL));
	cout << "WELCOME TO SNAKES AND LADDERS GAME" << endl;
	Game* g = new Game();
	g->Start();
	cout << "Thanks for playing!!!" << endl;
	return 0;
}