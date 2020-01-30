/*
	Program #3: Newton game to get 5 in a row.
   			    Players alternate placing a piece or
                rotating a column.

	Class : CS 141
	Author Name : Div Patel
	Lab : Tuesday 5pm
	System : C++ Windows 10, Dev C++(v 5.11)
*/
/* ------------------------------------------------
   reedProg3.cpp
 
   Program #3: Newton game to get 5 in a row.
               Players alternate placing a piece or
               rotating a column.

   Class: CS 141
   Author: Dale Reed
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   50 Execution points
         2 Displays header info and instructions on screen when run
         5 Move number and character-to-move update correctly
         3 Handles upper and lower-case user input, spaces between inputs, and 'X' to exit
         5 Does error checking of user input for valid input and space in column
        10 Handles 'R' to rotate a column
        10 Correctly places pieces on board
        15 Detects a win of 5 in a row, and gives the corresponding ending message

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header and this rubric.  Has comments on each block of code
        10 Appropriate data and control structures 
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/



#include <cstdlib>
#include <iostream>
using namespace std;

//GLOBAL VARIABLES



char userInput = '\0';		//Will store user input to make inferences

const char UserOne = 'X';
const char UserTwo = 'O';
int moveCount = 0;			//Counts which move is it

void gameIntro(){			//ADDS GAME INFO IN THE BEGINNING

	cout << "Author Name : Div Patel" 
		<< endl << "Class : CS 141" 
		<< endl << "Program #3: Newton game Extra Credit" 
		<< endl << "C++ Windows 10, Dev C++(v 5.11)" << endl << endl << endl;
	
	cout << "Welcome to the game of Newton, where you try to be the first" << endl
		<< "to get 5 in a row either vertically, horizontally or diagonally." << endl
		<< "Two players alternate making moves.  On each turn you may enter" << endl
		<< "the column number where your piece will be placed, where that" << endl
		<< "piece is inserted from the top and slides down as far as it can" << endl
		<< "go in that column.  You may also enter 'r' to rotate a piece out" << endl
		<< "of the bottom of a column to be dropped back in at the top of" << endl
		<< "that column.  Enter 'x' to exit." <<endl << endl << endl;
}

void drawTable(char *p_table){		//DRAWS TABLE WHENEVER CALLED
	cout << " 1   2   3   4   5" << endl << "--- --- --- --- ---" << endl;
	
	for(int i = 0; i < 8; i++)
	{	
		cout << " ";
		
		for(int j = 0; j < 5; j++)
		{
			cout<<*p_table<<"   ";
			p_table++;
		}
		
		cout << endl;
	}
	cout << "--- --- --- --- ---" << endl << " 1   2   3   4   5" << endl;
}

void takeInput(){			//TAKES INPUT
	moveCount++;				//COUNTS WHOSE MOVE IT IS
	cout << endl;
	cout << moveCount << ". Enter column number to place O or 'r' to rotate: " ;
	cin >> userInput;			//Input taken
	cout << endl;
	if((userInput < 49 || userInput > 53)&&(userInput != 'r'&&userInput != 'R'&&userInput != 'x'&&userInput != 'X'))		//FOLLOWS ASCII TABLE to only accept correct inputs.
	{
		moveCount--;
		cout << "*** Invalid input.  Please retry..." << endl;
		takeInput();
	}
	
}

int assignColumn(char userInput){			//Assigns column number in which we bring change. helps to keep track of 3 different arrays I am using
	if(userInput=='1'){
		return 0;
	}else if(userInput=='2'){
		return 1;
	}else if(userInput=='3'){
		return 2;
	}else if(userInput=='4'){
		return 3;
	}
	return 4;
}

void addInput(char *p_column, bool userOneMoves){
	if(userOneMoves==true)				//Adds input according to whose turn is it
	{
		*p_column = 'X';
	}else
	{
		*p_column = 'O';
	}
}

bool checkWin(char *p_table){				//Checks winning condition and breaks the loop if true
	char tempTable[8][5];				//temporary array taken from the pointer
	
	int	OneCombo = 0;
	int OneComboVert = 0;
	int OneComboHori = 0;
	int OneComboDiagOne = 0;
	int OneComboDiagTwo = 0;			//Counts the combo ( 5 lineup) of Xs
	
	int TwoCombo = 0;
	int TwoComboVert = 0;		
	int TwoComboHori = 0;	
	int TwoComboDiagOne = 0;			//Counts the combo ( 5 lineup) of Os			THIS IS DONE TO PREVENT AN ERROR WHEN THERE IS A TIE i.e. both sides have a 5 lineup
	int TwoComboDiagTwo = 0;
	
	for(int i = 0; i < 8; i++)
	{	
		for(int j = 0; j < 5; j++)					//CREATES THE TEMP TABLE
		{
			tempTable[i][j] = *p_table;
			p_table++;
		}
	}
	
	
		
		//For vertical
		//FOR PLAYER ONE
		for(int i = 3; i >= 0; i--)
		{
			for(int j = 0; j < 5; j++)
			{
				if(tempTable[i][j]=='X'&&tempTable[i+1][j]=='X'&&tempTable[i+2][j]=='X'&&tempTable[i+3][j]=='X'&&tempTable[i+4][j]=='X')
				{
					OneComboVert++;				
				}
			}
		}					
						
		//FOR HORIZONTAL
			
		//For player one
		for(int i = 7; i >= 0; i--)
			{ int j = 0;
				if(tempTable[i][j]=='X'&&tempTable[i][j+1]=='X'&&tempTable[i][j+2]=='X'&&tempTable[i][j+3]=='X'&&tempTable[i][j+4]=='X'){
					OneComboHori++;
				}
		}

		
		//FOR DIAGONAL top left to bottom right
		
		//for player one
		for(int i = 0; i < 4; i++){
			int j = 0;
			if(tempTable[i][j]=='X'&&tempTable[i+1][j+1]=='X'&&tempTable[i+2][j+2]=='X'&&tempTable[i+3][j+3]=='X'&&tempTable[i+4][j+4]=='X')
			{
				OneComboDiagOne++;
			}
		}
		
		//for diagonal top right to bottom left
		//for player one
		for(int i = 0; i < 4; i++){
			int j = 4;
			if(tempTable[i][j]=='X'&&tempTable[i+1][j-1]=='X'&&tempTable[i+2][j-2]=='X'&&tempTable[i+3][j-3]=='X'&&tempTable[i+4][j-4]=='X')
			{
				OneComboDiagTwo++;
			}
		}
	
		
		
		//FOR PLAYER TWO
	
		for(int i = 3; i >= 0; i--)
		{	
			for(int j = 0; j < 5; j++)
			{
				if(tempTable[i][j]=='O'&&tempTable[i+1][j]=='O'&&tempTable[i+2][j]=='O'&&tempTable[i+3][j]=='O'&&tempTable[i+4][j]=='O')
				{
					TwoComboVert++;				
				}
			}
		}
		
		//horizontal
		for(int i = 7; i >= 0; i--)
		{ int j = 0;
			if(tempTable[i][j]=='O'&&tempTable[i][j+1]=='O'&&tempTable[i][j+2]=='O'&&tempTable[i][j+3]=='O'&&tempTable[i][j+4]=='O'){
				TwoComboHori++;
			}
		}
	
		//diagonal
		for(int i = 0; i < 4; i++){
			int j = 0;
			if(tempTable[i][j]=='O'&&tempTable[i+1][j+1]=='O'&&tempTable[i+2][j+2]=='O'&&tempTable[i+3][j+3]=='O'&&tempTable[i+4][j+4]=='O')
			{
				TwoComboDiagOne++;
			}
			
		}	
		
		for(int i = 0; i < 4; i++){
			int j = 4;
			if(tempTable[i][j]=='O'&&tempTable[i+1][j-1]=='O'&&tempTable[i+2][j-2]=='O'&&tempTable[i+3][j-3]=='O'&&tempTable[i+4][j-4]=='O')
			{
				TwoComboDiagTwo++;
			}
			
		}
	
	OneCombo = OneComboHori + OneComboVert + OneComboDiagOne + OneComboDiagTwo;
	TwoCombo = TwoComboHori + TwoComboVert + TwoComboDiagOne + TwoComboDiagTwo;
	
	if(OneCombo!=0&&TwoCombo!=0)
	{
		if(OneComboVert > TwoComboVert)
		{
			cout << " PLAYER ONE WINS" << endl;
			return true;
		}else if(OneComboHori > TwoComboHori){
			cout << " PLAYER ONE WINS" << endl;
			return true;
		}else if(OneComboDiagOne > TwoComboDiagOne){
			cout << " PLAYER ONE WINS" << endl;
			return true;
		}else if(OneComboVert < TwoComboVert){
			cout << "PLAYER TWO WINS" << endl;
			return true;
		}else if(OneComboHori < TwoComboHori){
			cout << "PLAYER TWO WINS" << endl;
			return true;
		}else if(OneComboDiagOne < TwoComboDiagOne){
			cout << "PLAYER TWO WINS" << endl;
			return true;
		}else
		{
			cout << "TIE" << endl;
			return true;
		}
		
	}else if(OneCombo!=0){
		cout << " PLAYER ONE WINS" << endl;
		return true;
	}else if(TwoCombo!=0){
		cout << "PLAYER TWO WINS" << endl;
		return true;
	}
		
	
	return false;
}

bool userOneMove(){					//SEES WHOSE TURN IS IT TO MOVE
	if(moveCount%2==1)
	{
		return true;
	}
	return false;
}


int main()
{	int Column;			//used to intake the column number
	char tempChar;		// used while rotating the column
	
	int rotatingVar; 		// both variables are used as a way to know uptill which point should we rotate
	int secondRotVar = 7;
	int counter[5] = {7,7,7,7,7};		//initial array which counts the position available for a new input
	char rotate = '\0';			//which row to rotate
	
	char table[8][5] = 		//initialize the game table
	{
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},	
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},
		{'.','.','.','.','.'},
		};

	char *p_column[5] = {&table[counter[0]][0], &table[counter[1]][1], &table[counter[2]][2], &table[counter[3]][3], &table[counter[4]][4]}; //Pointer to keep track of number of Xs or Os in the table

	gameIntro();
	int loopCounter = 0;			//for the while loop to keep the code running
	while(loopCounter < 1){
		loopCounter++;
			
		drawTable(&table[0][0]);		//draw table
		takeInput();
		if(userInput != 'r'&&userInput != 'R'&&userInput != 'x'&&userInput != 'X')		//inputs X or O if the input is from 1-5
		{
			Column = assignColumn(userInput);		//get the column number using the function
			if(counter[Column] < 0)					//Checks to see if the column has space or not
			{
				cout << "*** Sorry, that column is already full.  Please choose another." << endl;
				moveCount--;			//to restart asking the question
			}else{
			
					addInput(p_column[Column], userOneMove());		//adds the particular character to the particular column using a pointer and the bool funtion
					counter[Column]--;		// moves the count up one row to the next available spot
					p_column[Column] = &table[counter[Column]][Column];		//moves the pointer up
				}
				
		}else if(userInput =='r'||userInput=='R')
			{
				cin >> rotate;		//takes in the column to rotate
				Column = assignColumn(rotate);	//column assigned				
				tempChar = table[7][Column];	//lowest character taken in the temp file
				rotatingVar = counter[Column] + 1; //highest available character's position is stored
				
				while(rotatingVar < secondRotVar)
				{
					table[secondRotVar][Column] = table[secondRotVar-1][Column];	//takes one higher character and copies it down
					secondRotVar--;		//moves the lower counter up
				}
				table[rotatingVar][Column] = tempChar;		//places the lowest character on top
				secondRotVar = 7;
				
			}else if(userInput=='x'||userInput=='X')
			{
				break;	//breaks the loop if exit is asked.
			}
		
		
		
		if(checkWin(&table[0][0])){		//checks for win
			break;
		}else{
			loopCounter--;		//if not resets loopCounter and the question is asked again
		}
		
		
	}
		drawTable(&table[0][0]);
		
		cout << "------------------------------------------THANKS FOR PLAYING!------------------------------------------" << endl;		//end game statement
		
	return 0;
}

//--------------------------END OF CODE-----------------------------------------------------------

































