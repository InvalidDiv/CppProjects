/*
Program Name : Toothpicks Puzzle
Class : CS 141
Author Name : Div Patel
Lab : Tuesday 5pm
System : C++ Windows 10, Dev C++(v 5.11)
*/

/* ------------------------------------------------
   prog1toothpicks.cpp
 
   Program #1: Toothpicks: Puzzle to equalize the number of toothpicks in three stacks.
   Class: CS 141
   Author: Dale Reed
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   50 Execution points
         5 Displays header info on screen when run
         5 Displays instructions
         5 Output is formatted as shown in sample output
         3 Handles both upper and lower case input
         5 Input can be adjacent or have spaces between them
        15 Makes moves correctly
        10 Handles the specified error conditions
         2 Gives appropriate end of program messages

   50 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header.  Comments on each block of code
        10 Appropriate data and control structures
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
	//Displaying header info
	cout << "Program Name : Toothpicks Puzzle" << endl; //Program Name
	cout << "Class : CS 141" << endl; // Class name
	cout << "Author Name : Div Patel" << endl; // Students Name : NET ID : dpate234@uic.edu
	cout << "Lab : Tuesday 5pm" << endl; // Lab Class Time
	cout << "System : C++ Windows 10, Dev C++(v 5.11)" << endl; //System and software used
	
	//Displaying the game instructions, taken from : https://sites.google.com/site/uiccs141/programs/prog-1-toothpicks
	cout << "Welcome to the Toothpick Puzzle, where the goal is to get an equal" << endl << "number of toothpicks in each stack, in three moves." << endl << endl;
	cout << "                 Stack:   A   B   C" << endl;
	cout << "  Number of Toothpicks:  11   7   6" << endl << endl;
	cout << "A move consists of moving toothpicks from one stack to a second stack," << endl;
	cout << "where the number of toothpicks moved is exactly the number that is in the" << endl;
	cout << "destination stack.  In other words, to move from stack B (7 toothpicks)" << endl;
	cout << "to stack C (6) as shown above, we would move 6 from B to C, leaving us" << endl;
	cout << "with 1 in B and 12 in stack C." << endl << endl;
	
	//start of the game
	cout << "Here we go..." << endl << endl;
	
	//initial stack count
	cout << "                 Stack:   A   B   C" << endl;
	cout << "  Number of Toothpicks:  11   7   6" << endl << endl;
	
	//initializing the needed variables to store the characters provided.
	char first, second;
	
	int A = 11; //first stack
	int B = 7;  //second stack
	int C = 6;  //third stack
	
			
	//for loop which takes input three times, displaying the changes each time along with it.
	for(int i = 1; i <= 3; i++)
	{
		//gives prompt for input for each step
		cout << i << ". Enter FROM and TO stack letters: ";
		
		cin >> first >> second; //takes input
		
		
		//If the first input was A or a
		if((first=='A')||(first=='a'))
		{
			//if the second input was B or b
			if((second=='B')||(second=='b'))
			{
				if(A>B)
				{	
					//transfers the toothpicks to other stack
					A = A - B;
					B = B * 2;					
				}
				else
				{
					//resets step count
					i = i - 1;
					//error message displayed
					cout << "error, A has less than or same amount of toothpicks as B" << endl;
				}
				
			}
			else
			{
				//if the second input was C or c
				if((second=='C')||(second=='c'))
				{
					if(A>C)
					{
						//transfers the toothpicks to other stack
						A = A - C;
						C = C * 2;
					}
					else
					{
						//resets step count
						i = i - 1;
						//error message displayed
						cout << "error, A has less than or same amount of toothpicks as C" << endl;
					}
				}
				else
				{
					//resets step count
					i = i - 1;
					//if the second input doesn't follow the rules
					cout << "wrong second input" <<endl;
				}
			}
		}
		else
		{
			
			//If the first input was B or b
			if((first=='B')||(first=='b'))
			{
				//if the second input was A or a
				if((second=='A')||(second=='a'))
				{
					//transfers the toothpicks to other stack
					if(B>A)
					{
						B = B - A;
						A = A * 2;					
					}
					else
					{
						//resets step count
						i = i - 1;
						//error message displayed
						cout << "error, B has less than or same amount of toothpicks as A" << endl;
					}
					
				}
				else
				{
					//if the second input was C or c
					if((second=='C')||(second=='c'))
					{
						//transfers the toothpicks to other stack
						if(B>C)
						{
							B = B - C;
							C = C * 2;
						}
						else
						{
							//resets step count
							i = i - 1;
							//error message displayed
							cout << "error, B has less than or same amount of toothpicks as C" << endl;
						}
					}
					else
					{
						//resets step count
						i = i - 1;
						//if the second input doesn't follow the rules
						cout << "wrong second input" <<endl;
					}
				}
			}
			else
			{
				//if first input was C or c
				if((first=='C')||(first=='c'))
				{
					//if the second input was A or a
					if((second=='A')||(second=='a'))
					{
						//transfers the toothpicks to other stack
						if(C>A)
						{
							C = C - A;
							A = A * 2;					
						}
						else
						{
							//resets step count
							i = i - 1;
							//error message displayed
							cout << "error, C has less than or same amount of toothpicks as A" << endl;
						}
						
					}
					else
					{
						//if the second input was B or b
						if((second=='B')||(second=='b'))
						{
							//transfers the toothpicks to other stack
							if(C>B)
							{
								C = C - B;
								B = B * 2;
							}
							else
							{
								//resets step count
								i = i - 1;
								//error message displayed
								cout << "error, C has less than or same amount of toothpicks as B" << endl;
							}
						}
						else
						{
							//resets step count
							i = i - 1;
							//if the second input doesn't follow the rules
							cout << "wrong second input" <<endl;
						}
					}
				}
				else
				{
					//resets step count
					i = i - 1;
					cout << "wrong input " << endl;
				}
			}
			
		}
		
		//changes to stack displayed
		cout << "                  Stack:   A   B   C" << endl;
		cout << "   Number of Toothpicks:  " << A << "   " << B << "   " << C << endl << endl;
		
		//END OF FOR LOOP
	}
	
	
	// Checks if the steps taken by user lead to the correct solution
	if(A==B&&A==C)
	{
		//condition satisfied
		cout << "                        Congratulations!  You did it!  Great job!" << endl;
	}
	else
	{
		//stacks not equal
		cout << "                         Nope, sorry, that's not it.  Try again." << endl;
	}
	
	return 0;	
	//END OF CODE
	
}

