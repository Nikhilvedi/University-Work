//---------------------------------------------------------------------------
//Program: Maze Game BASIC for Task 1c – Group Assignment, Group 1s
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
const char QUIT		('Q');		//to end the game
const char CHEAT	('C');		//Activate Cheat Mode

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

	void initialiseLevel1( char g[][ SIZEX+1], char m[][ SIZEX+1],  Item& mouse,
		Apple apple[amountOfApples], Item basket[amountOfBaskets],  Item cheese[amountOfCheese], 
							string& nameOfPlayer, int& amountOfCharacters);
	void paintGame( const char g[][ SIZEX+1], string& mess, string nameOfPlayer, 
		int& P1moveCounter, int& P1appleCounter, int& P1cheeseCounter, int& amountOfCharacters);
	bool wantsToQuit( int key);
	bool cheat (int key);
	bool isArrowKey( int& k);
	bool isSkipKey( int& k);
	bool gameFinished(int P1cheeseCounter, int P1appleCounter, int& k,int P1moveCounter,string nameOfPlayer);
	int getKeyPress();
	void endProgram();

//---------------------------------------------------------------------------
//----- Local Variable Declarations
//---------------------------------------------------------------------------
	char grid[ SIZEY+1][ SIZEX+1];								//grid for display
	char maze[ SIZEY+1][ SIZEX+1];								//structure of the maze
	bool checkedApple( false);									//checks if apple is in basket
	int amountOfCharacters;										//reference needed for most multiplayer options
	Item mouse = { (SIZEX/2) + 1, (SIZEY/2) + 1, MOUSE}; 		//mouse's position and symbol
	string message( "LET'S START...");							//current message to player
	string nameOfPlayer;										//players name (player one in multiplayer option)
	string playerName;
	int P1moveCounter (0), P1appleCounter (0), applesStillToFind (6), P1cheeseCounter (0); 
	//Integers needed from both Singleplayer and Multiplayer counters & turn counters
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
	
	int key = getKeyPress();						//Gets which key has been pressed
	
			amountOfCharacters = 1;					//Sets amount of characters to 1 (for future reference)
			string getNameOfPlayer(int P1moveCounter,int P1appleCounter);				//Call function to get name
			nameOfPlayer = getNameOfPlayer(P1moveCounter,P1appleCounter);		//Assign name to nameOfPlayer variable
//---------------------------------------------------------------------------
//----- Action
//---------------------------------------------------------------------------
	Clrscr();				//Removes the start screen
	void moveMouse( char g[][ SIZEX+1], Item& m, int key, string& mess, Apple apple[amountOfApples],
		int& P1moveCounter, Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters, int& P1appleCounter, int& P1cheeseCounter, bool checkedApple);	
	//Initialises the move mouse function
	void updateGrid( char g[][ SIZEX+1], const char m[][ SIZEX+1], Item mouse, Apple apple[amountOfApples],
		Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					int& amountOfCharacters);			//Updates the grid with new coordinates and parameters

	void applePushFromBasket (Apple apple[amountOfApples], const char g[][ SIZEX+1], int ax, int ay,
		int dx, int dy, int& appleCounter, int& applesStillToFind, bool checkedApple);
	initialiseLevel1( grid, maze, mouse,  apple, basket, cheese, nameOfPlayer, amountOfCharacters);	//initialise grid (incl. walls & mouse)
	paintGame( grid, message, nameOfPlayer, P1moveCounter, P1appleCounter, P1cheeseCounter, amountOfCharacters);	
	//display game info, modified grid & messages
	key = NULL;			//Nullifies the key pressed so it can't do anything (IE, if Q was pressed before, it may quit the game involuntarily)
	while (! gameFinished( P1cheeseCounter, P1appleCounter, key, P1moveCounter, nameOfPlayer) )	//while user does not want to quit or the game has not finished
	{
			key = getKeyPress(); 	//display menu & read in next option
			if( isArrowKey( key))	//If the arrow key is pressed
			{
				int dx( 0), dy( 0);		//Sets fresh DX and DY integer values
				moveMouse( grid, mouse, key, message, apple, P1moveCounter, basket, cheese, amountOfCharacters,
					P1appleCounter, P1cheeseCounter, checkedApple);	//move mouse in that direction
				updateGrid( grid, maze, mouse, apple, basket, cheese, amountOfCharacters);		//Updates grid with new coordinates and parameters
				paintGame( grid, message, nameOfPlayer, P1moveCounter, P1appleCounter, P1cheeseCounter, amountOfCharacters );	//Paints the score and grid etc.
			}
		else
		{
				int dx( 0), dy( 0);	//Sets fresh DX and DY integer values for P1
				moveMouse( grid, mouse, key, message, apple, P1moveCounter, basket, cheese,
					amountOfCharacters, P1appleCounter, P1cheeseCounter, checkedApple);	//move mouse in that direction
				updateGrid( grid, maze, mouse, apple, basket, cheese, amountOfCharacters);	//Updates grid with new coordinates and parameters
		}
		paintGame( grid, message, nameOfPlayer, P1moveCounter, P1appleCounter, P1cheeseCounter, amountOfCharacters );
		
	if (cheat ( key))
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
							mouse.x = 15; //Set Mouse Position
							mouse.y = 8;
					}
				
					updateGrid( grid, maze, mouse, apple, basket, cheese, amountOfCharacters);//Updates grid with new coordinates and parameters
					paintGame( grid, message, nameOfPlayer, P1moveCounter, P1appleCounter,
						P1cheeseCounter, amountOfCharacters ); //Paints the score and grid etc.
	}
	updateGrid( grid, maze, mouse, apple, basket, cheese, amountOfCharacters);			//Updates grid with new coordinates and parameters
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
string getNameOfPlayer(int P1moveCounter,int P1appleCounter)	
	//Function to get player 1 name (Singleplayer)
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
//----- initialise game state
//---------------------------------------------------------------------------
void initialiseLevel1( char grid[][ SIZEX+1], char maze[][ SIZEX+1], Item& mouse, 
					  Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
					  string& nameOfPlayer, int& amountOfCharacters)
{	//initialise grid & place mouse in middle
	void setLevel1MazeStructure( char g[][ SIZEX+1]);	//Sets maze structure for the first level
	void setLevel1MouseCoordinates( Item& mouse, int& amountOfCharacters);	//Sets the mouse coordinates for the first level
	void updateGrid( char g[][ SIZEX+1], const char m[][ SIZEX+1], Item mouse, Apple apple[amountOfApples],
		Item basket[amountOfBaskets], Item cheese[amountOfCheese], int& amountOfCharacters); //Updates grid with new coordinates and parameters
	void randomiseCheese( Item cheese[], char grid[][ SIZEX + 1]);	//Randomises location of cheese.

	setLevel1MazeStructure( maze);	//initialise maze
	setLevel1MouseCoordinates( mouse, amountOfCharacters); //initialise mouse's position
	updateGrid( grid, maze, mouse, apple, basket, cheese, amountOfCharacters); //prepare grid	
	randomiseCheese( cheese, grid);
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
void setLevel1MouseCoordinates( Item& mouse, int& amountOfCharacters)
{ //calculate mouse's coordinates at beginning of game
	mouse.y = 9;   					//Sets mouse 1 Y coordinate
	mouse.x = 15; 					//Sets mouse 1 X coordinate

} 


//---------------------------------------------------------------------------
//----- Sets initial Cheese Coordinates
//---------------------------------------------------------------------------
void randomiseCheese( Item cheese[], char grid[][ SIZEX + 1])
{   //Randomises the location of cheese on the grid
	void placeCheese(char grid[][SIZEX + 1], Item cheese[]); //initialises the function to place cheese on the grid
	srand( (unsigned)time(NULL));							//finds a random value
	int X;												//Sets an integer for the X coordinate
	int Y;												//Sets an integer for the Y coordinate
	for( int i(0); i < amountOfCheese; i++)				//Does this 6 times (1 for every cheese)
	{
		do
		{
			X = rand() % (SIZEX + 1);					//Sets the integer for X to a random coordinate on the map
			Y = rand() % (SIZEY + 1);					//Sets the integer for Y to a random coordinate on the map
		}
		while (grid[Y][X] != TUNNEL);					//While the X and Y coordinate does not equal an empty space
		cheese[i].x = X;								//Sets that cheese to that X coordinate
		cheese[i].y = Y;								//Sets that cheese to that Y coordinate
	}

	placeCheese( grid, cheese);							//Places the cheese on the grid.
}

//---------------------------------------------------------------------------
//----- Grid States/Updates
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//----- update grid state
//---------------------------------------------------------------------------
void updateGrid( char grid[][ SIZEX+1], const char maze[][ SIZEX+1], Item mouse, Apple apple[amountOfApples], Item basket[amountOfBaskets], Item cheese[amountOfCheese], 
				int& amountOfCharacters)
{ //update grid configuration after each move
	void setMaze( char g[][ SIZEX+1], const char m[][ SIZEX+1]);		//resets empty maze on the grid
	void placeBasket (char g[][ SIZEX+1], Item basket[amountOfBaskets]);//places baskets on the grid
	void placeApples( char g[][ SIZEX+1], Apple apple[amountOfApples]);	//places apples on the grid
	void placeCheese( char g[][ SIZEX+1], Item cheese[amountOfCheese]);	//places cheese on the grid
	void placeMouse( char g[][ SIZEX+1], Item mouse);					//places player 1 mouse on the grid
	
	setMaze( grid, maze);	//reset the empty maze configuration into grid
	placeBasket(grid, basket);
	placeCheese( grid, cheese);
	placeMouse( grid, mouse);
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
{   //places baskets in position of grid 
	//(These will not move but need to be used for referencing whether the apple is in the same position of the grid.)
	for (int i(0); i<6; ++i)
		g[basket[i].y][basket[i].x] = basket[i].symbol;
}

//---------------------------------------------------------------------------
//----- Can The apple be Pushed?
//---------------------------------------------------------------------------
bool canAppleBePushed (Apple apple[amountOfApples], const char g[][ SIZEX+1],
					   int ax, int ay, int dx, int dy, int& P1appleCounter )
{   //
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
void moveMouse( char g[][ SIZEX+1], Item& m, int key, string& mess, Apple apple[amountOfApples], int& P1moveCounter, Item basket[amountOfBaskets], 
			   Item cheese[amountOfCheese],  int& amountOfCharacters, int& P1appleCounter, int& P1cheeseCounter, bool checkedApple)
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
			break;
		case WALL:  		//hit a wall & stay there
			cout << '\a';	//beep the alarm
			mess = "CANNOT GO THERE!";
			break;
		case BASKET:
			m.y += dy;		//go in that Y direction
			m.x += dx;		//go in that X direction
			++P1moveCounter;
			break;
		case CHEESE:
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
			++P1cheeseCounter;
			++P1moveCounter;
			cout << '\a';
			mess = "CHEESE EATEN";
			break;		
		case APPLE:
			if (canAppleBePushed(apple, g, m.x+dx, m.y+dy, dx, dy, P1appleCounter ))
			{
				m.y += dy;		//go in that Y direction
				m.x += dx;
				++P1moveCounter;  //go in that X direction
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
bool gameFinished(int P1cheeseCounter, int P1appleCounter, int& key,int P1moveCounter, string nameOfPlayer)
{	//check if the user wants to quit (when key is 'Q' or 'q')
	int best;
	if (toupper(key) == QUIT)
	{
		Gotoxy (40, SIZEY+3); 
		cout << "\nAre you sure you want to quit the game? (Y/N)";
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
	else if (P1cheeseCounter == 6 && P1appleCounter == 6)
	{
		ifstream in(nameOfPlayer.c_str());
		in >> best;
		if (best > P1moveCounter)
		{
			ofstream out(nameOfPlayer.c_str(), ios::out);
			best = P1moveCounter;
			out << best;
		}

		Gotoxy( 40, SIZEY + 3);
		cout << "PLAYER WON!";
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------
//----- Cheat
//---------------------------------------------------------------------------
bool cheat(int key)

{	return (toupper(key) == CHEAT);
	cout << '\a'; cout << '\a'; cout << '\a';
} 

//---------------------------------------------------------------------------
//----- Checks is arrow key is pressed
//---------------------------------------------------------------------------
bool isArrowKey( int& key)
{	//check if the key pressed is an arrow key (also accept 'K', 'M', 'H' and 'P')
	return ((key == PONELEFT) || (key == PONERIGHT) || (key == PONEUP) || ( key == PONEDOWN));
} 

//---------------------------------------------------------------------------
//----- displays
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----- display info on screen
//---------------------------------------------------------------------------
void paintGame( const char g[][ SIZEX+1], string& mess, string nameOfPlayer, int& P1moveCounter, int& P1appleCounter, 
			   int& P1cheeseCounter, int& amountOfCharacters )
{
	int applesStillToFind;
	applesStillToFind = amountOfApples - P1appleCounter;
	void paintGrid( const char g[][ SIZEX+1], int& amountOfCharacters);
	void displaySPScore ( int P1moveCounter, string nameOfPlayer, int P1appleCounter, int applesStillToFind, int P1cheeseCounter);
	
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
	
	displaySPScore( P1moveCounter, nameOfPlayer, P1appleCounter, applesStillToFind, P1cheeseCounter);

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
		int data (string nameOfPlayer);
		int best = data(nameOfPlayer);
		Gotoxy(36, 7);
		cout << "PLAYER NAME          :" + nameOfPlayer;
		Gotoxy(36, 8);
		cout << "BEST SCORE           :" << best;
		Gotoxy(36, 9);
		cout << "NUMBER OF MOVES      :" << P1moveCounter;
		Gotoxy(36, 10);
		cout << "APPLES COLLECTED     :" << P1appleCounter;
		Gotoxy(36, 11);
		cout << "APPLES STILL TO FIND :" << applesStillToFind;
		Gotoxy(36, 12);
		cout << "BITS OF CHEESE FOUND :" << P1cheeseCounter << "/6";
		
}

//---------------------------------------------------------------------------
//----- Multiplayer Scores
//---------------------------------------------------------------------------

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
			{
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
	ifstream in(nameOfPlayer.c_str());
	if (in.fail())
	{
		ofstream out(nameOfPlayer.c_str());
		if (out.fail())
			cout << "\nERROR OPENING FILE";
		else
		{
			best = 500;
			out << best;
		}
	}
	else
	{
		in >> best;
	}
	return best;
}

//---------------------------------------------------------------------------
//----- Ends Program.
//---------------------------------------------------------------------------
void endProgram()
{
	SelectTextColour(clYellow);
	Gotoxy(SIZEY + 29, SIZEX); 
	system("pause"); //hold output screen until a keyboard key is hit

} 
