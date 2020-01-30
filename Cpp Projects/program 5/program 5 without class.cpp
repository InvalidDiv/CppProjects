/* 
   ------------------------------------------------
   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Div Patel, Jose Perez
   Lab: Tues 5pm
   System:  Dev C++ windows
   ------------------------------------------------
*/
   
/* ------------------------------------------------
   reedProg5.cpp
 
   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Dale Reed
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   55 Execution points
        2 Displays header info and instructions on screen when run
        3 Displays the board (Since I'm giving you all the code for this...)
        5 Allows selecting default values (robot 2 to square M), random values, or user-selected values.
       15 Allows making moves, displaying move numbers.  Input can be upper or lower case, and can have spaces or not.
       20 Robots stop at walls and don't run over each other
        5 Game stops and message is given when goal robot makes it to the goal square.
        5 If some robot besides robot 2 goes to the destination square (square M in this case), the destination square should change to show the robot there. When this robot moves away, the square should go back to displaying the letter that was there previously (M in our case.)

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
         5 Meaningful identifier names
         5 Comments: Has header and this rubric.  Has comments on each block of code
        20 Appropriate data and control structures. Is implemented using classes.
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

/* ------------------------------------------------
   reedProg5.cpp
 
   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Dale Reed
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   55 Execution points
        2 Displays header info and instructions on screen when run
        3 Displays the board (Since I'm giving you all the code for this...)
        5 Allows selecting default values (robot 2 to square M), random values, or user-selected values.
       15 Allows making moves, displaying move numbers.  Input can be upper or lower case, and can have spaces or not.
       20 Robots stop at walls and don't run over each other
        5 Game stops and message is given when goal robot makes it to the goal square.
        5 If some robot besides robot 2 goes to the destination square (square M in this case), the destination square should change to show the robot there. When this robot moves away, the square should go back to displaying the letter that was there previously (M in our case.)

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
         5 Meaningful identifier names
         5 Comments: Has header and this rubric.  Has comments on each block of code
        20 Appropriate data and control structures. Is implemented using classes.
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>
#include <cstring>      // for getline
#include <cstdlib>      // for the system command
#include <cctype>       // For the letter checking functions, e.g. toupper( )
#include <fstream>      // For file input and output
#include <time.h>		//for randomizing srand each time code runs

using namespace std;


// Global data structure for board
const int BOARD_EDGE = 16;
const int BOARD_SIZE = BOARD_EDGE * BOARD_EDGE;
const int NUMBER_OF_ROBOTS = 4;

// declare constants to later use instead of numbers to select values from theBoard
const int NUMBER_OF_ELEMENTS = 5;   // Number of elements for each piece, enumerated below
const int PIECE = 0;    // to reference the character, such as in: theBoard[ i][ PIECE]
const int LEFT = 1;     // to reference the left wall character, such as in: theBoard[ i][ LEFT]
const int ABOVE = 2;    // to reference the above wall character, such as in: theBoard[ i][ ABOVE]
const int RIGHT = 3;    // to reference the right wall character, such as in: theBoard[ i][ RIGHT]
const int BELOW = 4;    // to reference the below wall character, such as in: theBoard[ i][ BELOW]

const int move_up = -16;		//moves robot one up
const int move_down = 16;		//moves robot one down
const int move_left = -1;		//moves robot one left
const int move_right = 1;		//moves robot one right

class Board{
	//-------------------------------------------------------------------------------------
	// createBoard() - Create the board, initializing all the display characters
	//
	void createBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
	{
	    for( int i=0; i<BOARD_SIZE; i++) {
	        theBoard[ i][ PIECE]= '.';    // Set each playing piece default
	        // set the default wall values to be blank
	        theBoard[ i][ LEFT]= ' ';
	        theBoard[ i][ ABOVE]= ' ';
	        theBoard[ i][ RIGHT]= ' ';
	        theBoard[ i][ BELOW]=  ' ';
	        
	        // reset the edge pieces
	        // reset the left wall if piece is on left edge
	        if( (i % BOARD_EDGE) == 0) {
	            theBoard[ i][ LEFT]= '|';
	        }
	        // reset the above wall if piece is on top edge
	        if( i < BOARD_EDGE) {
	            theBoard[ i][ ABOVE]= '-';
	        }
	        // reset the right wall if piece is on right edge
	        if( ((i+1) % BOARD_EDGE) == 0) {
	            theBoard[ i][ RIGHT]= '|';
	        }
	        // reset the below wall if piece is on bottom edge
	        if( i >= (BOARD_SIZE - BOARD_EDGE) ) {
	            theBoard[ i][ BELOW]= '-';
	        }
	    }//end for( int i...
	    
	}//end createBoard()
	
	
	//-------------------------------------------------------------------------------------
	// readFromFileAndModifyBoard() - Read from data file, updating board accordingly
	//
	void readFromFileAndModifyBoard(
	        char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS],
	        int theRobots[ ],
	        int &numberOfDestinationPieces)
	{
	    int numberOfSpecialSquares;  // Read from file, denotes number of pieces with some kind of wall
	    string inputLine;            // Input line from file
	    int pieceNumber;             // pieceNumber for each square defined in data file
	    char c;
	    
	    ifstream inStream;           // declare an input file stream
	    inStream.open("board.txt");  // Open input file, associating the actual file name with "inStream"
	    if ( inStream.fail() ) {
	        cout << "Input file opening failed.  Exiting...\n\n";
	        exit(-1);
	    }
	    
	    // Read from file one line at a time.  First read the top three data file lines which are documentation.
	    getline( inStream, inputLine);
	    getline( inStream, inputLine);
	    getline( inStream, inputLine);
	    
	    inStream >> numberOfDestinationPieces;      // read how many destination pieces there are
	    inStream >> numberOfSpecialSquares;         // number of square with walls around them somewhere
	    inStream.get( c);                           // Get rid of return character at end of current line
	                                                // to get ready for reading a line at a time below
	    
	    // process the special squares, updating the board
	    for( int i=0; i<numberOfSpecialSquares; i++) {
	        getline( inStream, inputLine);
	        char *pInputLine = &inputLine[0];
	        // Extract the piece number from the input line array
	        sscanf( pInputLine, "%d", &pieceNumber);
	        // Advance the inputLine pointer to the space after the number
	        pInputLine = strchr( pInputLine, ' ');
	
	        // Read the information on whether or not there is each of the potential 4 walls.
	        // The four values read correspond in order to the pieces on all four sides,
	        // which are defined as global constants for the values LEFT=1, ABOVE=2, RIGHT=3, BELOW=4
	        for( int position=1; position<=4; position++) {
	            pInputLine++;   // advance to next character to be read
	            sscanf( pInputLine, " %c", &c);         // Read the next potential wall character
	            // Convert it to a blank if it was '0'.  '0' was left in input file to make it easier to read.
	            if( c=='0') {
	                c = ' ';
	            }
	            theBoard[ pieceNumber][ position] = c;
	        }
	        pInputLine++;
	
	        // See if there is a piece letter still to be read on this input line.
	        // Do this by finding the end of the line, and seeing the length of the string
	        // after that.
	        // An inputline sample for piece 18 would be:
	        // 18 00|- A
	        if( strlen( pInputLine) > 0) {
	            sscanf( pInputLine, " %c", &theBoard[ pieceNumber][ PIECE]);
	        }
	
	    }//end for( int i...
	    
	    // At the end of the data file read the information on the location of the robots, updating the board.
	    char junk[80];           // used to read and discard input file information
	    // Loop starts counting from 1 (rather than 0), since we ignore the 0th position
	    // of the robots array, so that robot numbers correspond to what is shown
	    // on the board.
	    for( int i=1; i<=NUMBER_OF_ROBOTS; i++) {
	        inStream >> theRobots[ i];
	        inStream.getline( junk, '\n');    // discard rest of line, which is color information, if using graphics
	        // set robot on board, converting the integer value to a character
	        theBoard[ theRobots[ i]][ PIECE] = (char)('0'+i);     // record the robot number in place on board
	    }
	    
	    inStream.close();         // close the input file stream
	}//end readFromFileAndModifyBoard()
	
	
	//-------------------------------------------------------------------------------------
	// Display the Board
	//
	void displayTheBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
	{
	    // display the top edge
	    cout << "  ---------------------------------------------------------------- " << endl;
	    
	    // display the "body" of the board
	    for( int i=0; i<BOARD_SIZE; i++) {
	        // Figure out what character should be displayed to the left.  It will
	        // be a wall if the current spot has a left wall, or if the spot to the
	        // left has a right wall.
	        
	        char leftCharacter = theBoard[ i][ LEFT];   // set left display char
	        // See if the piece to the left has a right wall.  Don't do this for the
	        // first piece on the board, since it has no left neighbor.
	        if ( (i>0) && (theBoard[ i-1][ RIGHT] != ' ')) {
	            leftCharacter = theBoard[ i-1][ RIGHT];
	        }
	        cout << " " << leftCharacter << " " << theBoard[ i][ PIECE];
	        // see if we're at the end of a row
	        if( ((i+1) % BOARD_EDGE) == 0) {
	            // we are at the end of a row, so display right wall and go to next line
	            cout << "  " << theBoard[ i][ RIGHT] << endl;
	            // Now display any walls immediately below the line of pieces just displayed
	            // Backup our index counter j to the beginning of this line again, to find any
	            // walls displayed below this line.  Don't do it for the bottom row though.
	            if( i < BOARD_SIZE - BOARD_EDGE) {
	            
	                cout << " |";       // display the left boundary
	                for( int j=i-BOARD_EDGE+1; j<(i+1); j++) {
	                    // Set the character to be displayed.  This is a wall if the
	                    // current spot has a wall below, or if the spot below has a wall
	                    // above.
	                    char belowCharacter = theBoard[ j][ BELOW];
	                    // Only check the square below if we're NOT on the bottom row
	                    if ( (j<(BOARD_SIZE - BOARD_EDGE)) &&      // verify not on bottom row
	                        (theBoard[ j+16][ ABOVE] != ' ')) {    // piece below has wall above
	                        belowCharacter = theBoard[ j+16][ ABOVE];
	                    }
	                    for( int i=0; i<3; i++) {
	                       cout << belowCharacter;        // display the character
	                    }
	                    // display extra spaces, if we're not at the end of a row
	                    if( ((j+1) % BOARD_EDGE) != 0) {
	                        cout << " ";
	                    }
	                }//end for( int j...
	                cout << " |" << endl;       // display the right boundary
	            }//end if( i< BOARD_SIZE...
	
	        }//end if( ((i+1...
	        
	    }//end for( int i=0;...
	    
	    // display the bottom edge
	    cout << "  ---------------------------------------------------------------- " << endl;
	    cout << endl;
	}//end displayTheBoard()
	
	private:
		int numberOfSpecialSquares;  // Read from file, denotes number of pieces with some kind of wall
	    string inputLine;            // Input line from file
	    int pieceNumber;             // pieceNumber for each square defined in data file
	    char c;
		char junk[80];
		
};
//-------------------------------------------------------------------------------------
void displayIdentifyingInformationAndInstructions()
{
    // Display identifying information
    cout << "Author: Dale Reed                    " << endl
         << "Program 5: RicoRobots in C++         " << endl
         << "TA: Billie Joe Armstrong, T 6:00 AM  " << endl
         << "March 22, 2018                       " << endl;

    // Display Instructions
    cout << "Welcome to Ricochet Robots                                     " << endl
         << "(\'Ricochet Robot\' is a registered trademark of Hans im Glück " << endl
         << "Munich, Germany, 1999. The game was created by Alex Randolph.) " << endl
         << endl
         << "The object of the game is to get the designated numbered robot " << endl
         << "to the indicated letter position.                              " << endl
         << "The numbered squares are all robots.  They unfortunately have  " << endl
         << "no brakes, and so will continue in whatever direction they are " << endl
         << "moving until they encountar an obstacle.                       " << endl
         << "For each move enter the robot number and the desired direction." << endl
         << "For instance entering                                          " << endl
         << "   1 U " << endl
         << "would move the #1 robot up as far as it can go.                " << endl
         << "The first letter of input is the robot number (1 - 4),         " << endl
         << "and the second letter is the direction:                        " << endl
         << "  (L=left, U=up, R=right, D=down)                              " << endl
         << "Enter x to exit.  Have fun!                                    " << endl
         <<  endl;
}//end displayIdentifyingInformationAndInstructions()



void selectGame(int *theRobot, char *finalLetter,  char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS], int numberOfDestinationPieces)
{
	srand(time(NULL));
	
	cout << "Enter 'r' for random robot and goal, 'd' for default or 's' to select: ";
	char input;
	cin >> input;
	cout << endl;
	
	if(input == 'r' || input == 'R')
	{	//we randomize the goals
		char goals[26] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};	//all possible goals
		int random = rand() % (numberOfDestinationPieces+1);
		*finalLetter = goals[random]; //sets goal
		
		random = rand() % 4;
		*theRobot = random+1;
		
	}else if(input == 'd' || input == 'D')
	{
		//remains default
	}else if(input == 's')
	{
		cout << endl << endl;
		
		Board::displayTheBoard(theBoard);
		
		//ask for particular inputs
		cout << "pls enter the particular robot and the goal destination repectively: ";
		
		int inputInt;
		cin >> inputInt;
		char inputChar;
		cin >> inputChar;
		inputChar = toupper(inputChar);
		if((inputInt > 0 && inputInt < 5 )&& (inputChar>64 && inputChar <118))
		{
			*theRobot = inputInt;
			*finalLetter = inputChar;
		}else
		{
			cout << " wrong inputs, using defaults. input 'x' in next input to exit" << endl;
		}
		cout << endl;
	}else
	{
		cout << "Wrong Input, game will continue with default settings" << endl;
	}
	
}

void removeOtherLetters(char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS], char goalLetter)
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		if(isalpha(theBoard[i][PIECE])&&(theBoard[i][PIECE]!=goalLetter))
		{
				theBoard[i][PIECE] = '.';
		}
	}
}

int index(char destinationLetter, char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		if(theBoard[i][PIECE] == destinationLetter)
		{
			return i;
		}
	}
	return -1;
}

void move(int robot, char move, int theRobots[], char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS], char destinationLetter, int destinationIndex)
{
	//       PIECE   LEFT ABOVE RIGHT BELOW
    //      ---0---  --1-  --2-  --3-  --4-
    //    0    .       |     _
    //    1    .             _
    //   ...
    //   255   .                   |     _
	move = toupper(move); // make input upper case
	int robotIndex = theRobots[ robot];
	
	if (move == 'U')
	{
		// check criteria before moving
		while(	(theBoard[robotIndex][ABOVE] != '-') 
				&& (theBoard[robotIndex-16][BELOW] != '-') 
				&& (robotIndex > 15) // so it does not go below piece 0
				&& (theBoard[robotIndex - 16][PIECE] == '.' || theBoard[robotIndex - 16][PIECE] == destinationLetter))
		{
		    theBoard[ robotIndex][ PIECE] = '.';         // blank out where we're coming FROM
		    theRobots[ robot] = robotIndex - 16;     // Reset robot position index to the square above
		    robotIndex = theRobots[ robot];          // Get the new stored value reflecting the new position
		    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
		    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
		    // character '2'.
		    theBoard[ robotIndex][ PIECE] = '0'+robot;
		}
	}
	else if (move == 'D')
	{
		// check criteria before moving
		while(	(theBoard[robotIndex][BELOW] != '-') 
				&& (theBoard[robotIndex + 16][ABOVE] != '-') 
				&& (robotIndex < 240) // so it does not go past piece 255
				&& (theBoard[robotIndex + 16][PIECE] == '.' || theBoard[robotIndex + 16][PIECE] == destinationLetter))
		{
		    theBoard[ robotIndex][ PIECE] = '.';         // blank out where we're coming FROM
		    theRobots[ robot] = robotIndex + 16;     // Reset robot position index to the square above
		    robotIndex = theRobots[ robot];          // Get the new stored value reflecting the new position
		    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
		    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
		    // character '2'.
		    theBoard[ robotIndex][ PIECE] = '0'+robot;
		}
	}
	else if (move == 'L')
	{
		// check criteria before moving
		while(	(theBoard[robotIndex][LEFT] != '|') 
				&& (theBoard[robotIndex - 1][RIGHT] != '|') 
				&& ((robotIndex % 16) > 0) // so it does not go past leftmost position in row
				&& (theBoard[robotIndex - 1][PIECE] == '.' || theBoard[robotIndex - 1][PIECE] == destinationLetter))
		{
		    theBoard[ robotIndex][ PIECE] = '.';         // blank out where we're coming FROM
		    theRobots[ robot] = robotIndex - 1;     // Reset robot position index to the square above
		    robotIndex = theRobots[ robot];          // Get the new stored value reflecting the new position
		    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
		    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
		    // character '2'.
		    theBoard[ robotIndex][ PIECE] = '0'+robot;
		}
	}
	else if (move == 'R')
	{
		// check criteria before moving
		while(	(theBoard[robotIndex][RIGHT] != '|') 
				&& (theBoard[robotIndex + 1][LEFT] != '|') 
				&& ((robotIndex % 16) != 15) // so it does not go past rightmost position in row
				&& (theBoard[robotIndex + 1][PIECE] == '.' || theBoard[robotIndex + 1][PIECE] == destinationLetter))
		{
		    theBoard[ robotIndex][ PIECE] = '.';         // blank out where we're coming FROM
		    theRobots[ robot] = robotIndex + 1;     // Reset robot position index to the square above
		    robotIndex = theRobots[ robot];          // Get the new stored value reflecting the new position
		    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
		    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
		    // character '2'.
		    theBoard[ robotIndex][ PIECE] = '0'+robot;
		}
	}
	if(theBoard[destinationIndex][PIECE]=='.')
	{
		theBoard[destinationIndex][PIECE]= destinationLetter;
	}
}

bool checkIfWin(int destination, int robot)		//checks if reached the destination
{
	if(robot == destination)
		return true;
	
	return false;
}


//-------------------------------------------------------------------------------------
// main() - main part of program, that drives everything else
//
int main()
{
    // theBoard itself is represented by a one-dimensional array.
    // The other entries are used to keep track of walls.  Each row
    // in theBoard array will contain the character to be displayed,
    // followed by any "walls" to be displayed around the displayed
    // character.  For instance the first couple of entries are be:
    //
    //       PIECE   LEFT ABOVE RIGHT BELOW
    //      ---0---  --1-  --2-  --3-  --4-
    //    0    .       |     _
    //    1    .             _
    //   ...
    //   255   .                   |     _
    //
    char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS];
    // Declare the 4 robots, which will store the board position of where they are found
    // Robots are displayed using values 1-4.  We declare 5 robots, though we will never use
    // the 0th robot in the array, so that we can use the robot digit itself as the index.
    int theRobots[ NUMBER_OF_ROBOTS + 1] = {0,0,0,0,0};

    int goalRobot ;                  // the robot that needs to reach the goal
    char destinationLetter ;         // the goal letter
    int numberOfDestinationPieces;  // Number of destination pieces.  Value
                                    //    comes from the data file.
    
    displayIdentifyingInformationAndInstructions();
    createBoard( theBoard);   // create the board, initializing all pieces to their default settings
    readFromFileAndModifyBoard( theBoard, theRobots, numberOfDestinationPieces); // read from the datafile, updating board
    
    
    //default goal values
    goalRobot = 2;
    destinationLetter = 'M';
    
    selectGame(&goalRobot, &destinationLetter, theBoard, numberOfDestinationPieces);
    
    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
    
    removeOtherLetters(theBoard, destinationLetter);
    int indexOfDestination = index(destinationLetter, theBoard);
    int moveCounter = 0;
    
    char input;
    int inputInt;
    char inputChar;
    
    while(checkIfWin(indexOfDestination, theRobots[goalRobot])!=true)
	{
		moveCounter++;
	    for(int i = 0; i < 15; i ++)
	    {
	    	cout << endl;		//pushes code up
		}
		
		displayTheBoard( theBoard);
	    
	    cout << moveCounter << ". Please enter the robot to move and the direction (e.g. 2 r): ";	//takes input
	    cin >> input;
	    input = toupper(input);
	    
	    if(input=='X')		//exit command
	    {	cout << endl;
			break;
		}
		else if((input> 48 && input < 53 ))		//for numerical value
		{
			inputInt = int(input)-48;		//converts the value into int
			cin >> inputChar;
			inputChar = toupper(inputChar);
			cout << endl;
			
			if( inputChar == 'U' || inputChar == 'D'|| inputChar == 'L' || inputChar == 'R')
			{
				move( inputInt, inputChar, theRobots, theBoard, destinationLetter, indexOfDestination);		//makes moves
			}
			else
			{
				cout << "Wrong input pls try again" << endl;		//error comment
				--moveCounter;
				continue;
			}
		}
		else
		{
				cout << "Wrong input pls try again" << endl;
				--moveCounter;
				continue;
		}
		   	
	}
    
    if(input == 'X')
    {
    	cout << " Thank you for playing." << endl;
    	
	}
	else
	{
		displayTheBoard(theBoard);
		cout << "Congratulations, you finished the game in " << moveCounter << " moves." << endl;
	}
    
  return 0;  
}//end main()

