//---------------------------------------------------------------------------
//Program: Maze Game ADVANCED (scoreboard, twoplayer) for Task 1c – Group Assignment, Group 1s
//Author: Nikhil Vedi, Bradley Worthington, Devon White 
//Last updated:  May 5th
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//----- include libraries
//---------------------------------------------------------------------------

//include standard libraries
#include <iostream>		//for output and input: cout <<, cin >>
#include <iomanip> 		//for output manipulators
#include <conio.h> 		//for getch()
#include <string>		//for string
#include <fstream>		//for reading and outputting data

using namespace std;

//include our own libraries
#include "ConsoleUtils.h"	//for Clrscr, Gotoxy, etc.
#include "TimeUtils.h"		//for system time ect. 

//---------------------------------------------------------------------------
//----- define constants
//---------------------------------------------------------------------------

//defining the size of the grid
const int  SIZEY   (11);		//vertical dimension
const int  SIZEX   (19);    	//horizontal dimension
const int amountOfApples (6);
const int amountOfCheese (6);
const int amountOfBaskets (6);

//defining symbols used for display of the grid & content
const char MOUSE   ('@');   	//player 1 mouse
const char MOUSE2  ('~');		//player 2 mouse
const char TUNNEL  (' ');    	//tunnel
const char WALL    ('#');    	//border
const char BASKET  ('+');		//basket
const char APPLE   ('O');		//apple
const char CHEESE  ('*');		//Tasty Cheese
//general controls
const int  SKIP		(' ');
//player 1 keys
const int  PONEUP      (72);		//up arrow
const int  PONEDOWN    (80); 		//down arrow
const int  PONERIGHT   (77);		//right arrow
const int  PONELEFT    (75);		//left arrow
//player 2 keys
const int  PTWOUP      ('W');		//up arrow
const int  PTWODOWN    ('S'); 		//down arrow
const int  PTWORIGHT   ('D');		//right arrow
const int  PTWOLEFT    ('A');		//left arrow
//defining the other command letters
const char QUIT		   ('Q');	//to end the game
const char CHEAT	   ('C');	//Activate Cheat Mode
const char LEADERBOARD ('L');	//Show leaderboard

struct Item {
	int x, y;
	const char symbol;
};

struct Apple {
	int x, y;
	const char symbol;
	bool inbasket;
};

//---------------------------------------------------------------------------
//----- run game
//---------------------------------------------------------------------------

int main()
{
//---------------------------------------------------------------------------
//----- Function Declarations
//---------------------------------------------------------------------------

	void initialiseLevel1( char g[][ SIZEX+1], char m[][ SIZEX+1],  Item& mouse, Item& mouse2, Apple apple[amountOfApples], Item basket[amountOfBaskets],  Item cheese[amountOfCheese], 
							string& nameOfPlayer, string& nameOfPlayer2, int& amountOfCharacters);
	void paintGame( const char g[][ SIZEX+1], string& mess, string nameOfPlayer, string nameOfPlayer2, int& P1moveCounter, int& P2moveCounter, int& P1appleCounter, int& P2appleCounter, 
					 int& P1cheeseCounter, int& P2cheeseCounter, int& amountOfCharacters, int& turnCounter,int key);
	bool wantsToQuit( int key);
	bool cheat (int key);
	bool isArrowKey( int& k);
	bool isWSADKey( int k);
	bool isSkipKey( int& k);
	bool gameFinished(int P1cheeseCounter, int P2cheeseCounter, int P1appleCounter, int P2appleCounter, int& k,int P1moveCounter,string nameOfPlayer);
	int getKeyPress();
	void endProgram();
	int bestScores[6];
	string topScorersNames[6];
	bool Leaderboard(int key);
	void Leaderboard(int bestScores[], string topScoresNames[]);
	void initialiseMainLboard(int topScores[], string topScorersNames[]);
	initialiseMainLboard(bestScores, topScorersNames);
	

//---------------------------------------------------------------------------
//----- Local Variable Declarations
//---------------------------------------------------------------------------
	char grid[ SIZEY+1][ SIZEX+1];								//grid for display
	char maze[ SIZEY+1][ SIZEX+1];								//structure of the maze
	bool checkedApple( false);									//checks if apple is in basket
	int amountOfCharacters;										//reference needed for most multiplayer options
	Item mouse = { (SIZEX/2) + 1, (SIZEY/2) + 1, MOUSE}; 		//mouse's position and symbol
	Item mouse2 = { (SIZEX/2) + 1, (SIZEY/2) + 1, MOUSE}; 		//mouse's position and symbol
	string message( "LET'S START...");							//current message to player
	string nameOfPlayer;										//players name (player one in multiplayer option)
	string nameOfPlayer2;										//player twos name in multiplayer option
	string playerName;
	int P1moveCounter (0), P2moveCounter(0), P1appleCounter (0), P2appleCounter(0), applesStillToFind (6), P1cheeseCounter (0), P2cheeseCounter (0), turnCounter ( 1); //Integers needed from both Singleplayer and Multiplayer counters & turn counters
	int level (1);
	//level 1 items
	Item basket[amountOfBaskets] = {{17, 7, BASKET}	 ,		//Initial basket locations
									{17, 8, BASKET}	 ,
									{17, 9, BASKET}	 ,
									{18, 7, BASKET}	 ,
									{18, 8, BASKET}	 ,
								    {18, 9, BASKET}} ;
	Apple apple[amountOfApples]	= {{3, 8, APPLE, false},			//Initial apple locations
								  {6, 3, APPLE, false},
							   	  {6, 5, APPLE, false},
								  {8, 4, APPLE, false},
								  {8, 5, APPLE, false},
								  {6, 8, APPLE, false}};
	Item cheese[amountOfCheese] = { { 0, 0, CHEESE} ,		//Initial cheese locations (null)
							    	{ 0, 0, CHEESE} ,
									{ 0, 0, CHEESE} ,
									{ 0, 0, CHEESE} ,
									{ 0, 0, CHEESE} ,
									{ 0, 0, CHEESE} };

	
//---------------------------------------------------------------------------
//----- Start Screen
//---------------------------------------------------------------------------
	Gotoxy(screenWidth()/2, screenHeight()/2);		//Moves next output to middle of screen
	SelectTextColour(clBlack);						//Menu select screen is white background with black text
	SelectBackColour(clWhite);
	cout << "1 OR 2 PLAYERS?";						//Outputs whether there are one or two players
	int key = getKeyPress();						//Gets which key has been pressed
	while(1)										//While this is true (The if statements will break this loop)
	{
		if( key == '1')								//If key pressed is 1 (Singleplayer)
		{
			amountOfCharacters = 1;					//Sets amount of characters to 1 (for future reference)
			string getNameOfPlayer(int P1moveCounter,int P1appleCounter);				//Call function to get name
			nameOfPlayer = getNameOfPlayer(P1moveCounter,P1appleCounter);		//Assign name to nameOfPlayer variable
			break;
		}
		else if( key == '2')						//If key pressed is 2 (Multiplayer)
		{
			amountOfCharacters = 2;					//Sets amount of characters to 2 (for future reference)
			string getNameOfPlayer1();				//Call function to get name (P1)
			nameOfPlayer = getNameOfPlayer1();		//Assign name to nameOfPlayer variable
			string getNameOfPlayer2();				//Call function to get name (P2)
			nameOfPlayer2 = getNameOfPlayer2();		//Assign P2 name to nameOfPlayer2 variable
			break;
		}
		else
			key = getKeyPress();					//If neither of these keys are pressed, it asks for another key and will not break the loop
	}

//---------------------------------------------------------------------------
//----- Action
//---------------------------------------------------------------------------
	Clrscr();				//Removes the start screen
	void moveMouse( char g[][ SIZEX+1], Item& m, int key, string& mess, Apple apple[amountOfApples], int& P1moveCounter, Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters, int& P1appleCounter, int& P1cheeseCounter, int& turnCounter, bool checkedApple);	//Initialises the move mouse function
	void moveMouse2( char g[][ SIZEX+1], Item& m2, int key, string& mess, Apple apple[amountOfApples], int& P2moveCounter, Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters, int& P2appleCounter,  int& P2cheeseCounter, int& turnCounter, bool checkedApple);	//Initiliases the move mouse 2 (Multiplayer) function
	void updateGrid( char g[][ SIZEX+1], const char m[][ SIZEX+1], Item mouse, Item mouse2, Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters);																											//Updates the grid with new coordinates and parameters

	void applePushFromBasket (Apple apple[amountOfApples], const char g[][ SIZEX+1], int ax, int ay, int dx, int dy, int& appleCounter, int& applesStillToFind, bool checkedApple);
	initialiseLevel1( grid, maze, mouse, mouse2, apple, basket, cheese, nameOfPlayer, nameOfPlayer2, amountOfCharacters);								//initialise grid (incl. walls & mouse)
	paintGame(grid, message, nameOfPlayer, nameOfPlayer2, P1moveCounter, P2moveCounter, P1appleCounter, P2appleCounter, 
		P1cheeseCounter, P2cheeseCounter, amountOfCharacters, turnCounter, key);	
																																						//display game info, modified grid & messages
	key = NULL;																																			//Nullifies the key pressed so it can't do anything (IE, if Q was pressed before, it may quit the game involuntarily)
	while (! gameFinished( P1cheeseCounter, P2cheeseCounter, P1appleCounter, P2appleCounter, key, P1moveCounter, nameOfPlayer) )														//while user does not want to quit or the game has not finished
	{
		key = getKeyPress(); 																															//display menu & read in next option
		//Singleplayer
		if (amountOfCharacters == 1)
		{
			if( isArrowKey( key))	//If the arrow key is pressed
			{
				int dx( 0), dy( 0);																																								//Sets fresh DX and DY integer values
				moveMouse( grid, mouse, key, message, apple, P1moveCounter, basket, cheese, amountOfCharacters, P1appleCounter, P1cheeseCounter, turnCounter, checkedApple);	//move mouse in that direction
				updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters);																								//Updates grid with new coordinates and parameters
				paintGame( grid, message, nameOfPlayer, nameOfPlayer2, P1moveCounter, P2moveCounter, P1appleCounter, P2appleCounter, 
					P1cheeseCounter, P2cheeseCounter, amountOfCharacters, turnCounter, key);	//Paints the score and grid etc.
			}
			
			}
		//Multiplayer
		else
		{
			if( isArrowKey( key) && turnCounter == 1)	//If BOTH arrow key is down and it is player ones turn
			{
				int dx( 0), dy( 0);																																								//Sets fresh DX and DY integer values for P1
				moveMouse( grid, mouse, key, message, apple, P1moveCounter, basket, cheese, amountOfCharacters, P1appleCounter, P1cheeseCounter, turnCounter, checkedApple);	//move mouse in that direction
				updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters);																								//Updates grid with new coordinates and parameters
			}
			else if( isWSADKey( key) && turnCounter == 2)	//If BOTH a WSAD key is down and it is player twos turn
			{
				int dx( 0), dy( 0);							//sets fresh DX and DY integers values for P2
				moveMouse2( grid, mouse2, key, message, apple, P2moveCounter, basket, cheese, amountOfCharacters, P2appleCounter, P2cheeseCounter, turnCounter, checkedApple);	//move mouse2 in that direction
				updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters);																									//Updates grid with new coordinates and parameters
			}
		}
		paintGame( grid, message, nameOfPlayer, nameOfPlayer2, P1moveCounter, P2moveCounter, P1appleCounter, P2appleCounter, P1cheeseCounter, 
			P2cheeseCounter, amountOfCharacters, turnCounter, key);
		
		if (cheat ( key))
			{ 
				
				if (amountOfCharacters == 1)
				{
					Gotoxy(20,16);
					P1cheeseCounter = 6;
					applesStillToFind = 1;
					cout << " PLAYER CHEATED!";
					P1moveCounter = 999;
					P1appleCounter = 5;
					for ( int i(0); i < amountOfApples; ++i) //Move Apples to new locations
						{
							switch(i)
							{
							case 0: 
								apple[i].x = 17;
								apple[i].y = 7;
								break;
							case 1: 
								apple[i].x = 16;
								apple[i].y = 8;
								break;
							case 2: 
								apple[i].x = 17;
								apple[i].y = 9;
								break;
							case 3: 
								apple[i].x = 18;
								apple[i].y = 7;
								break;
							case 4: 
								apple[i].x = 18;
								apple[i].y = 8;
								break;
							case 5: 
								apple[i].x = 18;
								apple[i].y = 9;
								break;
							}
							for ( int i(0); i < amountOfCheese; ++i) //Move Cheese to new locations
							{
							switch(i)
								{
							case 0: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
							case 1: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
							case 2: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
							case 3: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
							case 4: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
							case 5: 
								cheese[i].x = NULL;
								cheese[i].y = NULL;
								break;
								}
							}
							mouse.x = 15;  //Set Mouse x Position
							mouse.y = 8;   //Set Mouse y Position
						}
					updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters);			//Updates grid with new coordinates and parameters
					paintGame( grid, message, nameOfPlayer, nameOfPlayer2, P1moveCounter, P2moveCounter, P1appleCounter, P2appleCounter, 
						P1cheeseCounter, P2cheeseCounter, amountOfCharacters, turnCounter, key); //Paints the score and grid etc.
				}
				else //If the game is multiplayer
				{
					Gotoxy (40, 20); 
					cout << " CANNOT CHEAT IN MULTIPLAYER!";		//Display to player that they cannot cheat in a multiplayer game
				}
				updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters); //Updates grid with new coordinates and parameters
			}
		if (amountOfCharacters == 1,2)
				{
					if (Leaderboard(key))
				{
				Leaderboard(bestScores, topScorersNames);
				}
				}
		}
endProgram();		//display final message
return 0;			//ends program
} 

//---------------------------------------------------------------------------
//----- Player Names
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//----- Get Player Name
//---------------------------------------------------------------------------
string getNameOfPlayer(int P1moveCounter,int P1appleCounter)	//Function to get player 1 name (Singleplayer)
{
	Clrscr();									//clears the screen for the player
	string playerName;							//initialises a string for the player name
	Gotoxy(screenWidth()/2, screenHeight()/2);	//Goes to middle of screen
	SelectTextColour(clBlack);					//Sets the text colour to Black
	SelectBackColour(clWhite);					//Sets background colour to White
	cout << "ENTER PLAYER NAME:";				//Outputs player to enter name
	SelectTextColour(clWhite);					//Sets text colour to White
	SelectBackColour(clBlack);					//Sets background colour to Black
	cin >> playerName;							//space where player enters name
	return playerName;							//Returns the player name so it can be used as the string
}

//---------------------------------------------------------------------------
//----- Get Player 1 Name
//---------------------------------------------------------------------------
string getNameOfPlayer1()						//Function to get player name
{
	Clrscr();
	string playerName;
	Gotoxy(screenWidth()/2-12, screenHeight()/2);
	SelectTextColour(clBlack);
	SelectBackColour(clWhite);
	cout << "ENTER PLAYER 1 NAME:";
	SelectTextColour(clBlue);
	SelectBackColour(clBlack);
	cin >> playerName;
	return playerName;
}

//---------------------------------------------------------------------------
//----- Get Player 2 Name
//---------------------------------------------------------------------------
string getNameOfPlayer2()						//Function to get player name
{
	Clrscr();
	string player2Name;
	Gotoxy(screenWidth()/2-12, screenHeight()/2);
	SelectTextColour(clBlack);
	SelectBackColour(clWhite);
	cout << "ENTER PLAYER 2 NAME:";
	SelectTextColour(clRed);
	SelectBackColour(clBlack);
	cin >> player2Name;
	return player2Name;
}

//---------------------------------------------------------------------------
//----- initialise game state
//---------------------------------------------------------------------------
void initialiseLevel1( char grid[][ SIZEX+1], char maze[][ SIZEX+1], Item& mouse, Item& mouse2, Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					  string& nameOfPlayer, string& nameOfPlayer2, int& amountOfCharacters)
{	//initialise grid & place mouse in middle
	void setLevel1MazeStructure( char g[][ SIZEX+1]);	//Sets maze structure for the first level
	void setLevel1MouseCoordinates( Item& mouse, Item& mouse2, int& amountOfCharacters);	//Sets the mouse coordinates for the first level
	void updateGrid( char g[][ SIZEX+1], const char m[][ SIZEX+1], Item mouse, Item mouse2, Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters);			//Updates grid with new coordinates and parameters
	void randomiseCheese( Item cheese[], char grid[][ SIZEX + 1]);	//Randomises location of cheese.

	setLevel1MazeStructure( maze);															//initialise maze
	setLevel1MouseCoordinates( mouse, mouse2, amountOfCharacters);							//initialise mouse's position
	updateGrid( grid, maze, mouse, mouse2, apple, basket, cheese, amountOfCharacters); 		//prepare grid	
	randomiseCheese( cheese, grid);															//randomise cheese
}

//---------------------------------------------------------------------------
//----- Sets initial Maze Structure
//---------------------------------------------------------------------------
void setLevel1MazeStructure( char maze[][ SIZEX+1])
{ //set the position of the walls in the maze
	//initialise maze configuration
	char initialMaze[ SIZEY+1][ SIZEX+1] 	//local array to store the maze structure
	= { {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		{'X', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#' },
		{'X', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
		{'X', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#' },
		{'X', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{'X', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		};
	// with '#' for wall, ' ' for tunnel and 'X' for unused part of array
	//copy into maze structure
	for ( int row( 1); row <= SIZEY; ++row)	//for each row (vertically)
		for ( int col( 1); col <= SIZEX; ++col)	//for each column (horizontally)
			maze[row][col] = initialMaze[row][col];	//Set that row and column to the 'maze' character
} 

//---------------------------------------------------------------------------
//----- Sets initial Mouse Coordinates
//---------------------------------------------------------------------------
void setLevel1MouseCoordinates( Item& mouse, Item& mouse2, int& amountOfCharacters)
{ //calculate mouse's coordinates at beginning of game
	mouse.y = 9;   					//Sets mouse 1 Y coordinate
	mouse.x = 15; 					//Sets mouse 1 X coordinate
	if (amountOfCharacters == 2)	//If the game is multiplayer
	{
		mouse2.y = 7;				//Sets mouse 2 Y coordinate
		mouse2.x = 15;				//Sets mouse 2 X coordinate
	}
} 


//---------------------------------------------------------------------------
//----- Sets initial Cheese Coordinates
//---------------------------------------------------------------------------
void randomiseCheese( Item cheese[], char grid[][ SIZEX + 1])
{   //Randomises the location of cheese on the grid
	void placeCheese(char grid[][SIZEX + 1], Item cheese[]);	//initialises the function to place cheese on the grid
	srand( (unsigned)time(NULL));								//finds a random value
	int X;														//Sets an integer for the X coordinate
	int Y;														//Sets an integer for the Y coordinate
	for( int i(0); i < amountOfCheese; i++)						//Does this 6 times (1 for every cheese)
	{
		do
		{
			X = rand() % (SIZEX + 1);							//Sets the integer for X to a random coordinate on the map
			Y = rand() % (SIZEY + 1);							//Sets the integer for Y to a random coordinate on the map
		}
		while (grid[Y][X] != TUNNEL);							//While the X and Y coordinate does not equal an empty space
		cheese[i].x = X;										//Sets that cheese to that X coordinate
		cheese[i].y = Y;										//Sets that cheese to that Y coordinate
	}

	placeCheese( grid, cheese);									//Places the cheese on the grid.
}

//---------------------------------------------------------------------------
//----- Grid States/Updates
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//----- update grid state
//---------------------------------------------------------------------------
void updateGrid( char grid[][ SIZEX+1], const char maze[][ SIZEX+1], Item mouse, Item mouse2, Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
				int& amountOfCharacters)
{ //update grid configuration after each move
	void setMaze( char g[][ SIZEX+1], const char m[][ SIZEX+1]);			//resets empty maze on the grid
	void placeBasket (char g[][ SIZEX+1], Item basket[amountOfBaskets]);	//places baskets on the grid
	void placeApples( char g[][ SIZEX+1], Apple apple[amountOfApples]);		//places apples on the grid
	void placeCheese( char g[][ SIZEX+1], Item cheese[amountOfCheese]);		//places cheese on the grid
	void placeMouse( char g[][ SIZEX+1], Item mouse);						//places player 1 mouse on the grid
	void placeMouse2( char g[][ SIZEX+1], Item mouse2);						//places players 2 mouse on the grid (If Multiplayer)

	setMaze( grid, maze);	//reset the empty maze configuration into grid
	placeBasket(grid, basket);
	placeCheese( grid, cheese);
	placeMouse( grid, mouse);
	if (amountOfCharacters == 2)
		placeMouse2( grid, mouse2);
	placeApples(grid, apple);
} 

//---------------------------------------------------------------------------
//----- Set Maze
//---------------------------------------------------------------------------
void setMaze( char grid[][ SIZEX+1], const char maze[][ SIZEX+1])
{ //reset the empty/fixed maze configuration into grid
	for ( int row( 1); row <= SIZEY; ++row)	//for each row (vertically)
		for ( int col( 1); col <= SIZEX; ++col)	//for each column (horizontally)
			grid[row][col] = maze[row][col];
} 
//---------------------------------------------------------------------------
//----- Place Mouse
//---------------------------------------------------------------------------
void placeMouse( char g[][ SIZEX+1], Item m)
{ //place mouse at its new position in grid
	g[m.y][m.x] = m.symbol;
} 

//---------------------------------------------------------------------------
//----- Place Cheese
//---------------------------------------------------------------------------
void placeCheese( char g[][ SIZEX+1], Item cheese[amountOfCheese])
{	//places cheese at new position in grid.
	for ( int i(0); i<amountOfCheese; ++i)
	g[cheese[i].y][cheese[i].x] = cheese[i].symbol;
} 

//---------------------------------------------------------------------------
//----- Place Second Mouse
//---------------------------------------------------------------------------
void placeMouse2( char g[][ SIZEX+1], Item m2)
{ //place second mouse at its new position in grid (If multiplayer)
	g[m2.y][m2.x] = m2.symbol;
} 
//---------------------------------------------------------------------------
//----- Place Apples
//---------------------------------------------------------------------------
void placeApples( char g[][ SIZEX+1], Apple apple[amountOfApples])
{	//places apples at new position in grid
	for ( int i(0); i<6; ++i)
		g[apple[i].y][apple[i].x] = apple[i].symbol;
} 

//---------------------------------------------------------------------------
//----- Place Baskets
//---------------------------------------------------------------------------
void placeBasket (char g[][ SIZEX+1], Item basket [amountOfBaskets])
{   //places baskets in position of grid (These will not move but need to be used for referencing whether the apple is in the same position of the grid.)
	for (int i(0); i<6; ++i)
		g[basket[i].y][basket[i].x] = basket[i].symbol;
}

//---------------------------------------------------------------------------
//----- Can The apple be Pushed?
//---------------------------------------------------------------------------
bool canAppleBePushed (Apple apple[amountOfApples], const char g[][ SIZEX+1], int ax, int ay, int dx, int dy, int& P1appleCounter )
{   //determine when the apple van be pushed
	int current;
	for ( int i(0); i<6; ++i)
	{
		if (apple[i].x==ax && apple[i].y==ay)
		{
			current = i;
			break;
		}
	}
	switch( g[apple[current].y+dy][apple[current].x+dx])
	{			//...depending on what's on the target position in grid...
	case WALL:
		return false;
		break;
	case TUNNEL:
		apple[current].x+=dx;
		apple[current].y+=dy;
		if (apple[current].inbasket == true)
		{
			P1appleCounter--;
			apple[current].inbasket = false;
		}
		return true;
		break;
	case BASKET:
		apple[current].x+=dx;
		apple[current].y+=dy;
		if (apple[current].inbasket == false)
		{
			P1appleCounter++;
			apple[current].inbasket = true;
		}
		return true;
		break;
	case CHEESE:
		apple[current].x+=dx;
		apple[current].y+=dy;
		if (apple[current].inbasket == true)
		{
			P1appleCounter--;
			apple[current].inbasket = false;
		}
		return true;
		break;
	}	
	return false;
}

//---------------------------------------------------------------------------
//----- move player 1
//---------------------------------------------------------------------------
void moveMouse( char g[][ SIZEX+1], Item& m, int key, string& mess, Apple apple[amountOfApples], int& P1moveCounter, Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
			   int& amountOfCharacters, int& P1appleCounter, int& P1cheeseCounter, int& turnCounter, bool checkedApple)
{ //move mouse in required direction
	void setP1KeyDirection( int k, int& dx, int& dy );
	//calculate direction of movement required by key - if any
	int dx(0), dy(0);
	setP1KeyDirection( key, dx, dy ); 	//find direction indicated by key
	//check new target position in grid & update mouse coordinates if move is possible
	switch( g[m.y+dy][m.x+dx])
	{			//...depending on what's on the target position in grid...
		case TUNNEL:		//can move
			m.y += dy;		//go in that Y direction
			m.x += dx;		//go in that X direction
			++P1moveCounter;
			turnCounter = 2;
			break;
		case WALL:  		//hit a wall & stay there
			cout << '\a';	//beep the alarm
			mess = "CANNOT GO THERE!";
			break;
		case BASKET:
			m.y += dy;		//go in that Y direction
			m.x += dx;		//go in that X direction
			++P1moveCounter;
			turnCounter = 2;
			break;
		case CHEESE:					//Eating cheese
			for(int i = 0; i < 6; i++)
			{
				if ((cheese[i].x == (m.x + dx) && cheese[i].y == (m.y + dy)))
				{
					cheese[i].x = NULL;
					cheese[i].y = NULL;	
				}
			}
			m.x += dx;
			m.y += dy;
			turnCounter = 2;
			++P1cheeseCounter;
			++P1moveCounter;
			cout << '\a';
			mess = "CHEESE EATEN";
			break;		
		case APPLE:
			if (canAppleBePushed(apple, g, m.x+dx, m.y+dy, dx, dy, P1appleCounter ))
			{
				m.y += dy;		//go in that Y direction
				m.x += dx;		//go in that X direction
				++P1moveCounter;  
				turnCounter = 2;
			}
		break;
	}
} 

//---------------------------------------------------------------------------
//----- move player 2
//---------------------------------------------------------------------------
void moveMouse2( char g[][ SIZEX+1], Item& m2, int key, string& mess, Apple apple[amountOfApples], int& P2moveCounter, Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
				int& amountOfCharacters, int& P2appleCounter, int& P2cheeseCounter, int& turnCounter, bool checkedApple)
{ //move mouse in required direction
	void setP2KeyDirection( int k, int& dx, int& dy );
	//calculate direction of movement required by key - if any
	int dx(0), dy(0);
	setP2KeyDirection( key, dx, dy ); 	//find direction indicated by key
	//check new target position in grid & update mouse coordinates if move is possible
	switch( g[m2.y+dy][m2.x+dx])
	{			//...depending on what's on the target position in grid...
		case TUNNEL:		//can move
			m2.y += dy;		//go in that Y direction
			m2.x += dx;		//go in that X direction
			++P2moveCounter;
			turnCounter = 1;
			break;
		case WALL:  		//hit a wall & stay there
			cout << '\a';	//beep the alarm
			mess = "CANNOT GO THERE!";
			break;
		case BASKET:
			m2.y += dy;		//go in that Y direction
			m2.x += dx;		//go in that X direction
			++P2moveCounter;
			turnCounter = 1;
			break;
		case CHEESE:				//Eating cheese
			for(int i = 0; i < 6; i++)
			{
				if (cheese[i].x == (m2.x + dx) && cheese[i].y == (m2.y + dy))
				{
					cheese[i].x = NULL;
					cheese[i].y = NULL;	
				}
			}
			m2.x += dx;
			m2.y += dy;
			++P2cheeseCounter;
			++P2moveCounter;
			turnCounter = 1;
			break;		
		case APPLE:
			if (canAppleBePushed(apple, g, m2.x+dx, m2.y+dy, dx, dy, P2appleCounter))
			{
				m2.y += dy;		//go in that Y direction
				m2.x += dx;		//go in that X direction
				++P2moveCounter;   
				turnCounter = 1;
			}
		break;
	}
} 

//---------------------------------------------------------------------------
//----- process Player 1 key
//---------------------------------------------------------------------------
void setP1KeyDirection( int key, int& dx, int& dy)
{ //
	switch( key)		//...depending on the selected key...
	{
		case PONELEFT:  	//when LEFT arrow pressed...
			if (dx -1 == APPLE)
				dx = - 1; 
			dx = -1;	//decrease the X coordinate
			dy = 0;
			break;
		case PONERIGHT: 	//when RIGHT arrow pressed...
			dx = +1;	//increase the X coordinate
			dy = 0;
			break;
		case PONEUP: 		//when UP arrow pressed...
			dx = 0;
			dy = -1;	//decrease the Y coordinate
			break;
		case PONEDOWN: 		//when DOWN arrow pressed...
			dx = 0;
			dy = +1;		//increase the Y coordinate
			break;
	}
} 

//---------------------------------------------------------------------------
//----- process Player 2 key
//---------------------------------------------------------------------------
void setP2KeyDirection( int key, int& dx, int& dy)
{ //
	switch( key)		//...depending on the selected key...
	{
		case PTWOLEFT:  	//when LEFT arrow pressed...
			if (dx -1 == APPLE)
				dx = - 1; 
			dx = -1;	//decrease the X coordinate
			dy = 0;
			break;
		case PTWORIGHT: 	//when RIGHT arrow pressed...
			dx = +1;		//increase the X coordinate
			dy = 0;
			break;
		case PTWOUP: 		//when UP arrow pressed...
			dx = 0;
			dy = -1;		//decrease the Y coordinate
			break;
		case PTWODOWN: 		//when DOWN arrow pressed...
			dx = 0;
			dy = +1;		//increase the Y coordinate
			break;
	}
} 

//---------------------------------------------------------------------------
//----- Gets key pressed
//---------------------------------------------------------------------------
int getKeyPress()
{ //get key or command selected by user
	int keyPressed;
	keyPressed = getch();				//read in the selected arrow key or command letter
	while ( keyPressed == 224) 			//ignore symbol following cursor key
 		keyPressed = getch();
	return( toupper( keyPressed));		//return it in uppercase 
} 

//---------------------------------------------------------------------------
//----- Game finishes
//---------------------------------------------------------------------------
bool gameFinished(int P1cheeseCounter, int P2cheeseCounter, int P1appleCounter, int P2appleCounter, int& key,int P1moveCounter, string nameOfPlayer)
{	//check if the user wants to quit (when key is 'Q' or 'q')
	int best;
	string bestScore;
	string bestScoreName;
	int bestScores[6];
	int tempScore = P1moveCounter;
	string tempName;
	string topScorersNames[6]; 
	if (toupper(key) == QUIT)
	{
		Gotoxy (40, 18); 
		cout << "\nAre you sure you want to quit the game? (Y/N)";		//friendly output for quiting 
		do 
		{ 
			key = getKeyPress(); 
				if ((key != 'Y') && (key != 'N'))
				cout << "\nKey not valid, try again!";
		}
		while ((key != 'Y') && (key != 'N'));
		if (toupper(key) == 'Y')
			{
			cout <<"\nThanks for playing!";
			return true;
			}
		else
		{
			key = NULL;
			return false;
		}
	}
	else if (P1cheeseCounter == 6 && P1appleCounter == 6)		//when to end
	{
		ifstream in(nameOfPlayer.c_str());
		in >> best;
		if (best > P1moveCounter)
		{
			ofstream out(nameOfPlayer.c_str(), ios::out);
			best = P1moveCounter;
			out << best;
		}
				Gotoxy( 40, 18);
				cout << "PLAYER WON!";
	
		ifstream leader("bestScores.txt", ios::in);
		for (int i = 0; i < 6; i++)
		{
			getline (leader, bestScore, '\t');
			bestScores[i] = atoi(bestScore.c_str());

			getline (leader, bestScoreName, '\n');
			topScorersNames[i] = bestScoreName;
		}
		for (int i = 0; i < 6; i++)
		{
			if (tempScore < bestScores[i])
			{
				tempScore = bestScores[i];
				tempName = topScorersNames[i];
				bestScores[i] = P1moveCounter;
				topScorersNames[i] = nameOfPlayer;
				P1moveCounter = tempScore;
				nameOfPlayer = tempName;						
			}
		}
		leader.close();
		ofstream out("bestScores.txt", ios::out);
		for (int i(0); i < 6; i++)
		{
			out << bestScores[i]  << "\t" << topScorersNames[i] << "\n";
		}
		
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------
//----- Cheat
//---------------------------------------------------------------------------
bool cheat(int key)		
{	//for cheat key
	return (toupper(key) == CHEAT);			
	cout << '\a'; cout << '\a'; cout << '\a';
} 

//---------------------------------------------------------------------------
//----- Leaderboards
//---------------------------------------------------------------------------
bool Leaderboard(int key)
{    //for Leaderboard key
	return (toupper(key) == LEADERBOARD);
}

//---------------------------------------------------------------------------
//----- Checks is arrow key is pressed
//---------------------------------------------------------------------------
bool isArrowKey( int& key)
{	//check if the key pressed is an arrow key (also accept 'K', 'M', 'H' and 'P')
	return ((key == PONELEFT) || (key == PONERIGHT) || (key == PONEUP) || ( key == PONEDOWN));
} 

//---------------------------------------------------------------------------
//----- Checks if WSAD key is pressed
//---------------------------------------------------------------------------
bool isWSADKey( int key)
{	//check if the key pressed is WSAD.
	return (toupper(key == PTWOLEFT) || (key == PTWORIGHT) || (key == PTWOUP) || ( key == PTWODOWN));
} 

//---------------------------------------------------------------------------
//----- displays
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----- display info on screen
//---------------------------------------------------------------------------
void paintGame( const char g[][ SIZEX+1], string& mess, string nameOfPlayer, string nameOfPlayer2, int& P1moveCounter, int& P2moveCounter, int& P1appleCounter, int& P2appleCounter, 
			   int& P1cheeseCounter, int& P2cheeseCounter, int& amountOfCharacters, int& turnCounter, int key )
{
	int applesStillToFind;
	applesStillToFind = amountOfApples - P1appleCounter;
	void paintGrid( const char g[][ SIZEX+1], int& amountOfCharacters);
	void paintGrid( const char g[][ SIZEX+1], int& amountOfCharacters);
	void displaySPScore ( int P1moveCounter, string nameOfPlayer, int P1appleCounter, int applesStillToFind, int P1cheeseCounter);
	void displayMPScore( int P1moveCounter, int P2moveCounter, string nameOfPlayer, string nameOfPlayer2, int P1appleCounter, int P2appleCounter, int applesStillToFind, int P1cheeseCounter, 
						int P2cheeseCounter, int turnCounter);
	//clear screen
	Clrscr();

	//display game title
	SelectTextColour( clYellow);
	Gotoxy(0, 0);
	cout << "___MOUSE AND APPLES GAME___\n";
	SelectBackColour( clWhite);
	SelectTextColour( clRed);
	Gotoxy(36, 0);
	cout << "1S: Bradley, Devon, Nikhil - FoP";  
	// display grid contents
	paintGrid( g, amountOfCharacters);

	//display menu options available
	SelectBackColour( clBlack);
	SelectTextColour( clYellow);

	Gotoxy(36, 3);
	cout << "TO MOVE USE KEYBOARD ARROWS  ";
	Gotoxy(36, 4);
	cout << "TO QUIT ENTER  'Q'           ";
	Gotoxy(36, 5);
	cout << "TO CHEAT ENTER 'C'           ";
	Gotoxy(36, 6);
	cout << "FOR LEADERBOARD ENTER 'L'    ";


	if (amountOfCharacters == 2)
	{
		displayMPScore( P1moveCounter, P2moveCounter, nameOfPlayer, nameOfPlayer2, P1appleCounter, P2appleCounter, applesStillToFind, P1cheeseCounter, P2cheeseCounter, turnCounter);
	}
	else
	{
		displaySPScore( P1moveCounter, nameOfPlayer, P1appleCounter, applesStillToFind, P1cheeseCounter);
	}
	//print auxiliary messages if any
	SelectBackColour( clBlack);
	SelectTextColour( clRed);
	Gotoxy(1, 13);
	cout << mess;	//display current message
	mess = "";		//reset message to blank

	Gotoxy(36, 1);
	SelectBackColour( clWhite);
	SelectTextColour( clRed);
	cout << GetDate() << " " << GetTime();
	SelectTextColour( clWhite);
	SelectBackColour( clBlack);
}
	
//---------------------------------------------------------------------------
//----- Display Scores
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//----- Singleplayer Scores
//---------------------------------------------------------------------------
void displaySPScore ( int P1moveCounter, string nameOfPlayer, int P1appleCounter, int applesStillToFind, int P1cheeseCounter)
{
		//setting the single player scores 
		int data (string nameOfPlayer);
		int best = data(nameOfPlayer);
		Gotoxy(36, 9);
		cout << "PLAYER NAME          :" + nameOfPlayer;
		Gotoxy(36, 10);
		cout << "BEST SCORE           :" << best;
		Gotoxy(36, 11);
		cout << "NUMBER OF MOVES      :" << P1moveCounter;
		Gotoxy(36, 12);
		cout << "APPLES COLLECTED     :" << P1appleCounter;
		Gotoxy(36, 13);
		cout << "APPLES STILL TO FIND :" << applesStillToFind;
		Gotoxy(36, 14);
		cout << "BITS OF CHEESE FOUND :" << P1cheeseCounter << "/6";
		
}

//---------------------------------------------------------------------------
//----- Multiplayer Scores
//---------------------------------------------------------------------------
void displayMPScore( int P1moveCounter, int P2moveCounter, string nameOfPlayer, string nameOfPlayer2, int P1appleCounter, int P2appleCounter, int applesStillToFind, int P1cheeseCounter, 
					int P2cheeseCounter, int turnCounter)
{
	Gotoxy(36, 7);
	switch( turnCounter)
	{
	case 1:
		{
			SelectTextColour( clBlue);
			cout << "PLAYER 1 TURN";
			break;
		}
	case 2:
		{
			SelectTextColour( clRed);
			cout << "PLAYER 2 TURN";
			break;
		}
	}										//setting the multiplayer layout
		SelectTextColour( clYellow);
		Gotoxy(36, 9);
		cout << "PLAYER 1 NAME        :";
		SelectTextColour( clBlue);
		cout << nameOfPlayer;
		Gotoxy(36, 10);
		SelectTextColour( clYellow);
		cout << "PLAYER 1 SCORE       :" << P1appleCounter;
		Gotoxy(36, 11);
		cout << "PLAYER 1 MOVES       :" << P1moveCounter;
		Gotoxy(36, 12);
		cout << "PLAYER 1 CHEESE      :" << P1cheeseCounter;

		Gotoxy(36, 14);
		cout << "PLAYER 2 NAME        :";
		SelectTextColour( clRed);
		cout << nameOfPlayer2;
		Gotoxy(36, 15);
		SelectTextColour( clYellow);
		cout << "PLAYER 2 SCORE       :" << P2appleCounter;
		Gotoxy(36, 16);
		cout << "PLAYER 2 MOVES       :" << P2moveCounter;
		Gotoxy(36, 17);
		cout << "PLAYER 1 CHEESE      :" << P2cheeseCounter;
}

//---------------------------------------------------------------------------
//----- Paint Grid
//---------------------------------------------------------------------------
void paintGrid( const char g[][ SIZEX+1], int& amountOfCharacters)
{ //display grid content on screen
	SelectBackColour( clBlack);
	SelectTextColour( clWhite);
	Gotoxy(0, 2);
	for ( int row( 1); row <= SIZEY; ++row)	//for each row (vertically)
	{
		for ( int col( 1); col <= SIZEX; ++col)	//for each column (horizontally)
		{
			switch( g[row][col])		
			{ //set the colours for individual items 
				case MOUSE:
					if (amountOfCharacters == 1)
						SelectTextColour(clWhite);
					else
						SelectTextColour(clBlue);
					break;
				case MOUSE2:
					SelectTextColour(clRed);
					break;
				case WALL: 		
					SelectTextColour(clDarkGrey);
					break;
				case APPLE: 		
					SelectTextColour(clGreen);
					break;
				case CHEESE: 	
					SelectTextColour(clYellow);
					break;
				case BASKET:
					SelectTextColour (clMagenta);
				}
			cout << g[row][col];	//output cell content
		}
		cout << endl;
	}
}

int data (string nameOfPlayer)
{
	int best;
	ifstream in(nameOfPlayer.c_str());		//read in the Name of the Player
	if (in.fail())
	{
		ofstream out(nameOfPlayer.c_str());
		if (out.fail())
			cout << "\nERROR OPENING FILE"; //condition for failuire 
		else
		{
			best = 500;						//base of new players = 500
			out << best;					//put into file 
		}
	}
	else
	{
		in >> best;							// if score is beat, put in new best 
	}
	return best;
}

void initialiseMainLboard(int bestScores[], string topScorersNames[])
{
	for (int i(0); i < 6; i++)			//for upto 6 
	{
		bestScores[i] = 500;
		topScorersNames[i] = "Anonymous";		// set initial names as annoymous 
	}

	ifstream in("bestScores.txt", ios::in);		// create file named bestscores.txt
	if (in.fail())
	{
		ofstream out("bestScores.txt", ios::out);
		if (out.fail())
			cout << "\nERROR OPENING FILE";
		else
		{
			for (int i(0); i < 6; i++)
			{
				out << bestScores[i]  << "\t" << topScorersNames[i] << "\n";	// output the names and scores 
			}
		}
	}
}

void Leaderboard(int bestScores[], string topScorersNames[])
{
	string board;
	int LeaderboardSpacing(6);
	string pointerScore;
	string pointerName;

	Clrscr();
	SelectBackColour(clBlack);
	SelectTextColour(clGreen);
	Gotoxy(20, 5);
	cout << "LEADERBOARD (PRESS ENTER TO RETURN)\n\n";		//output to player
	
	ifstream in("bestScores.txt", ios::in);
	for (int i = 0; i < 6; i++)
	{
		getline (in, pointerScore, '\t');
		bestScores[i] = atoi(pointerScore.c_str());
					
		getline (in, pointerName, '\n');
		topScorersNames[i] = pointerName;
	}
	in.close();									//close the file 
	for (int i(0); i < 6; i++)					//loop for 6 items on the leaderboard
			{
				Gotoxy(20, LeaderboardSpacing);
				cout << topScorersNames[i];
				Gotoxy(40, LeaderboardSpacing++);
				cout << bestScores[i];
			}

	int key(getKeyPress()); 	
	while (key != 13)
	{
		key = getKeyPress();
	}
}

//---------------------------------------------------------------------------
//----- Ends Program.
//---------------------------------------------------------------------------
void endProgram()
{
	SelectTextColour(clYellow);
	Gotoxy(SIZEY + 29, SIZEX); 
	system("pause");	//hold output screen until a keyboard key is hit

} 
