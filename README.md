README
Project: SnakeAndLadders GAME
Programming Language: C++
By: Daniel Yamamoto.
Date: 19/05/2020

This code was made in VisualStudio 2019 and it is fully functional!

Build in x64, according to VisualStudio 2019.

Everything is used as a pointers or so I think.
There is not a text files. That was optional.

There are 5 classes with headers and sources, and the main:
*Main is named SnakeAndLadders only contain the class Game.

Every class has a constructor and destructor, private and public variables and the #define of themselves. 

1.- Tile class
	I used to create objects that will contain data like type, position, get and set of the variables.

2.- Board class contain array of Tiles
	I created the board with SNAKES and LADDERS and the other boxes in the constructor with the array of tiles.
	Every tile in the array has this own variables and methods that I can access with the array. Also, there is
	a method to set a special tile, the player.
	
	I have to say that I created the class with the option to create a bigger board, snakes or ladders. 
	If you want to do that only need to change the values of the #defines in the header.
	
3.- Dice class
	Only has one method that returns a random number between 1 and 6.

4.- Player class
	This class will be the special tile for the board and has a variables like name, position and previous position,
	also there are methods of get and set of the variables.

5.- Game class contain array of players, one board and a dice.
	Here, It will be the logical system of the game. 
	
	Like in the board class, you can change the #defines to modify the values of number of players, max turns of the game,
	the reward or penalty for falling into the box of a snake o ladder.
	
	I created in the constructor the array of players because you can introduce your name like a string and the game will
	call you with the name you want it. Of course, it is necessary to create the board, array of players and the dice. 
	On the other hand, there are variables for total turns of the game, actual player turn and gameover.
	
	There is a while cycle in a method that will be running the game until the gameover variable is true or total turns 
	is greater than total max turns.