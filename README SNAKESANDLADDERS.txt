README
Project: SnakeAndLadders GAME
Programming Language: C++
By: Daniel Yamamoto.
Date: 02/06/2020

This code was made in VisualStudio 2019 and it is fully functional!

Build in x64, according to VisualStudio 2019.

Everything is used as a pointers or so I think.
There is not a text files. That was optional.

There are 8 classes with headers and sources, and the main:
*Main is named SnakeAndLadders only contain the class Game.

Every class has a constructor and destructor, private and public variables and the #define of themselves. 

1.- Tile class
	I used to create objects that will contain data like type, position, get and set of the variables.

2.- SnakeTile Class
	Is a child class of Tile and has one fuction overwritten.

3.- LadderTile Class
	Is a child class of Tile and has one fuction overwritten.

4.- Board class contain array of Tiles
	I created the board with SNAKES and LADDERS and the other boxes in the constructor with a vector of tiles, 
	adding type of Tiles like snake and ladder. Every tile in the vector has this own variables and methods that I can access. 
	

	Also, there is a method to set a special tile, the player.
	
5.- Dice class
	Only has one method that returns a random number between 1 and 6.

6.- Turn Class
	Only has the actual turn in the game. Use a overload operator << to print the turn.

7.- Player class
	This class will be the special tile for the board and has a variables like name, position and previous position,
	also there are methods of get and set of the variables.

8.- Game class contain a vector of players, one board and a dice.
	Here, It will be the logical system of the game. 
	
	I created in the constructor the vector of players because it's dynamic now! You can introduce your name like a string and the game will
	call you with the name you want it. Of course, it is necessary to create the board, vector of players and the dice. 
	On the other hand, there are variables for total turns of the game, actual player turn and gameover.

	Also when you create your constructor, you will need how many tiles, snake tiles, ladder tiles, rewards, penalties, players,
	turns and type of the game.
	
	There is a while cycle in a method that will be running the game until the gameover variable is true or total turns 
	is greater than total max turns.