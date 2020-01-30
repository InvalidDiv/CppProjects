/*
Program Name : Memory Game
Class : CS 141
Author Name : Div Patel
Lab : Tuesday 5pm
System : C++ Windows 10, Dev C++(v 5.11)
*/
/* ------------------------------------------------
   prog2memory.cpp
 
   Program #2: Memory game of guessing which X or O changed.
   Class: CS 141
   Author: Dale Reed
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   50 Execution points
         0/5 Displays header info on screen when run
         0/5 Displays instructions
         0/5 Output is formatted as shown in sample output
         0/3 Handles both upper and lower case input
         0/2 Input of 'x' in first prompt exits program
         0/5 Input can be adjacent or have spaces between them
        0/15 Displayed boards all have odd parity in rows and columns
         0/5 Repeated input of 'r' gives new valid random board each time
         0/5 Gives appropriate end of program messages - Program gives error: [Error] 'time' was not declared in this scope - SM

   45 Programming Style (Given only if program runs substantially correctly)
        4/5 Program naming convention is followed
        10/10 Meaningful identifier names
        10/10 Comments: Has header.  Comments on each block of code
        10/10 Appropriate data and control structures (-20 if using arrays or strings)
        10/10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/
//*** if your netid is reed then your program would be called prog1reed.cpp. The name of the zip file must be prog1reed.zip
//*** Please use functions for the code
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() {
    //-------------------------------------------------------------------INTRODCTION AND INITIALIZATION OF VARIABLES--------------------------------------------------------------------------
	//Game intro details print out : 
	cout << "Author: Div Patel \nClass: CS 141, Spring 2018 \nLab: Tue 5pm \nProgram: #2, Memory Game\n" << endl;
	cout << "Welcome to the memory game! " << endl << endl;
	cout << "Look away from the board and have a helper enter r" << endl << "to randomize the board until they have a random board" << endl;
	cout << "that they like.  Then you glance at it and try to" << endl << "imprint it in your mind and look away.  Your helper" << endl;
	cout << "will then select a single piece to be flipped by" << endl << "choosing its row and column.  The changed board is then" << endl;
	cout << "displayed. You then must try to guess which one it was." << endl << "Enter x to exit the program." << endl;
	cout << endl << endl;
	
	//Initialization of all char variables : p0-p5 first row, p6-p11 second...
	
	char p0,p1,p2,p3,p4,p5,p6,p7,p8,p9;
	char p10,p11,p12,p13,p14,p15,p16,p17,p18,p19;
	char p20,p21,p22,p23,p24,p25,p26,p27,p28,p29;
	char p30,p31,p32,p33,p34,p35;
	
	//initialization of int variables to collect and arrange the random int provided.
	
	int i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
	int i11,i12,i13,i14,i15,i16,i17,i18,i19,i20;
	int i21,i22,i23,i24,i25,i26,i27,i28,i29,i30,i31,i32,i33,i34,i35;
	
	srand(time(NULL));//changes strings/sets of numbers
	
	//initialization needed char and int variables needed in and out of while loop
	char input1 ='\0';
	char input2 ='\0';
	char input3 ='\0';
	char input4 ='\0';
	int loop = 0;
	int sum = 0;
	int outer = 0;
	
    //----------------------------------------------RANDOMIZING AND PRINTING THE GRID-------------------------------------------------------------------------------------------------------	
	while(outer<1)
	{//outer loop to randomize the whole grid if requested through input1 from user with 'r' or 'R'
	
	    cout << endl;
	    
		outer++;
		while(loop<1)
		{//randomize row1-3 and check odd parity
		
			loop++;
			//forming the box
			
			//row 1
			i0 = rand() % 2;
			i1 = rand() % 2;
			i2 = rand() % 2;
			i3 = rand() % 2;
			i4 = rand() % 2;
			i5 = rand() % 2;
				
			sum = i0+i1+i2+i3+i4+i5; // odd parity is taken by adding 1s and 0s; if sum is even, loop starts again if odd continues.
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//row 2
			i6 = rand() % 2;
			i7 = rand() % 2;
			i8 = rand() % 2;
			i9 = rand() % 2;
			i10 = rand() % 2;
			i11 = rand() % 2;
			
			sum = i6+i7+i8+i9+i10+i11;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//row 3
			i12 = rand() % 2;
			i13 = rand() % 2;
			i14 = rand() % 2;
			i15 = rand() % 2;
			i16 = rand() % 2;
			i17 = rand() % 2;
			
			sum = i12+i13+i14+i15+i16+i17;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
		
		}
	
	loop = 0;
	//breaking the row assignment into two parts so that less memory/workload is used when assigning the odd parity in columns.
	
	//When we check odd parity for columns, if they dont match, only the lower three are generated again. Its not much of a change but helps decrease the amount of data that has to be calculated again
		while(loop<1)
		{//generates row4-6; and checks odd parity for all columns
			loop++;
			//row 4
			i18 = rand() % 2;
			i19 = rand() % 2;
			i20 = rand() % 2;
			i21 = rand() % 2;
			i22 = rand() % 2;
			i23 = rand() % 2;
			
			sum = i18+i19+i20+i21+i22+i23;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//row 5
			i24 = rand() % 2;
			i25 = rand() % 2;
			i26 = rand() % 2;
			i27 = rand() % 2;
			i28 = rand() % 2;
			i29 = rand() % 2;
			
			sum = i24+i25+i26+i27+i28+i29;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//row 6
			i30 = rand() % 2;
			i31 = rand() % 2;
			i32 = rand() % 2;
			i33 = rand() % 2;
			i34 = rand() % 2;
			i35 = rand() % 2;
			
			sum = i30+i31+i32+i33+i34+i35;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 1
			sum = i0+i6+i12+i18+i24+i30;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 2
			sum = i1+i7+i13+i19+i25+i31;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 3
			sum = i2+i8+i14+i20+i26+i32;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 4
			sum = i3+i9+i15+i21+i27+i33;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 5
			sum = i4+i10+i16+i22+i28+i34;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
			//column 6
			sum = i5+i11+i17+i23+i29+i35;
			
			if(sum%2==0)//odd parity
				{
				loop--;
				continue;
				}
			
		}
		loop--;
		
		//CHANGES CHARACTERS, O if int is 0, X is int is 1
		if(i0==0){p0 = 'O';}else{p0 = 'X';}
	    if(i1==0){p1 = 'O';}else{p1 = 'X';}
    	if(i2==0){p2 = 'O';}else{p2 = 'X';}
	    if(i3==0){p3 = 'O';}else{p3 = 'X';}
    	if(i4==0){p4 = 'O';}else{p4 = 'X';}
    	if(i5==0){p5 = 'O';}else{p5 = 'X';}
    	if(i6==0){p6 = 'O';}else{p6 = 'X';}
    	if(i7==0){p7 = 'O';}else{p7 = 'X';}
    	if(i8==0){p8 = 'O';}else{p8 = 'X';}
    	if(i9==0){p9 = 'O';}else{p9 = 'X';}
    	if(i10==0){p10 = 'O';}else{p10 = 'X';}
    	if(i11==0){p11 = 'O';}else{p11 = 'X';}
    	if(i12==0){p12 = 'O';}else{p12 = 'X';}
    	if(i13==0){p13 = 'O';}else{p13 = 'X';}
    	if(i14==0){p14 = 'O';}else{p14 = 'X';}
    	if(i15==0){p15 = 'O';}else{p15 = 'X';}
    	if(i16==0){p16 = 'O';}else{p16 = 'X';}
    	if(i17==0){p17 = 'O';}else{p17 = 'X';}
    	if(i18==0){p18 = 'O';}else{p18 = 'X';}
    	if(i19==0){p19 = 'O';}else{p19 = 'X';}
    	if(i20==0){p20 = 'O';}else{p20 = 'X';}
    	if(i21==0){p21 = 'O';}else{p21 = 'X';}
    	if(i22==0){p22 = 'O';}else{p22 = 'X';}
    	if(i23==0){p23 = 'O';}else{p23 = 'X';}
        if(i24==0){p24 = 'O';}else{p24 = 'X';}
    	if(i25==0){p25 = 'O';}else{p25 = 'X';}
    	if(i26==0){p26 = 'O';}else{p26 = 'X';}
    	if(i27==0){p27 = 'O';}else{p27 = 'X';}
	    if(i28==0){p28 = 'O';}else{p28 = 'X';}
        if(i29==0){p29 = 'O';}else{p29 = 'X';}
    	if(i30==0){p30 = 'O';}else{p30 = 'X';}
    	if(i31==0){p31 = 'O';}else{p31 = 'X';}
    	if(i32==0){p32 = 'O';}else{p32 = 'X';}
    	if(i33==0){p33 = 'O';}else{p33 = 'X';}
    	if(i34==0){p34 = 'O';}else{p34 = 'X';}
	    if(i35==0){p35 = 'O';}else{p35 = 'X';}
	
		
		cout << "     1 2 3 4 5 6    " << endl;
		cout << "   - - - - - - - -  " << endl;
		cout << " A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " | A" << endl;
		cout << " B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " | B" << endl;
		cout << " C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " | C" << endl;
		cout << " D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " | D" << endl;
		cout << " E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " | E" << endl;
		cout << " F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " | F" << endl;
		cout << "   - - - - - - - -  " << endl << endl;
		
		cout << "Enter r to randomize to board, or row and column to change a value -> ";
		
		cin >> input1;//takes first character
		cout << endl;
		
		input1 = toupper(input1);//converting to upper case
		
		if(input1 == 'R')//if R, restarts loop to generate a new board
		{
		    outer--;
			continue;
		}	
	}
	
	if(input1 == 'X')//if X the code exits
	{
		return 0;
	}
	//GOT INPUT FROM USER TO Change THE PARTICULAR LOCATION ^
	
	cin >> input2;//input 2 intake

//------------------------------------------------------CHANGES THE X or O that the user requests through cin, The input is taken and after the change, draws another board after 25 lines------------------------------------------	
	if(input1=='A')//row A
	{
	    if(input2 == '1')
	    {
	        if(i0==1)
	        {
	            i0 = 0;
	        }else if(i0==0)
	        {
	            i0 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i1==1)
	        {
	            i1 = 0;
	        }else if(i1==0)
	        {
	            i1 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i2==1)
	        {
	            i2 = 0;
	        }else if(i2==0)
	        {
	            i2 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i3==1)
	        {
	            i3 = 0;
	        }else if(i3==0)
	        {
	            i3 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i4==1)
	        {
	            i4 = 0;
	        }else if(i4==0)
	        {
	            i4 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i5==1)
	        {
	            i5 = 0;
	        }else if(i5==0)
	        {
	            i5 = 1;
	        }
	    }
	}else if(input1 == 'B')//row B
	{
	    if(input2 == '1')
	    {
	        if(i6==1)
	        {
	            i6 = 0;
	        }else if(i6==0)
	        {
	            i6 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i7==1)
	        {
	            i7 = 0;
	        }else if(i7==0)
	        {
	            i7 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i8==1)
	        {
	            i8 = 0;
	        }else if(i8==0)
	        {
	            i8 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i9==1)
	        {
	            i9 = 0;
	        }else if(i9==0)
	        {
	            i9 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i10==1)
	        {
	            i10 = 0;
	        }else if(i10==0)
	        {
	            i10 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i11==1)
	        {
	            i11 = 0;
	        }else if(i11==0)
	        {
	            i11 = 1;
	        }
	    }
	}else if(input1 == 'C')//row C
	{
	    if(input2 == '1')
	    {
	        if(i12==1)
	        {
	            i12 = 0;
	        }else if(i12==0)
	        {
	            i12 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i13==1)
	        {
	            i13 = 0;
	        }else if(i13==0)
	        {
	            i13 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i14==1)
	        {
	            i14 = 0;
	        }else if(i14==0)
	        {
	            i14 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i15==1)
	        {
	            i15 = 0;
	        }else if(i15==0)
	        {
	            i15 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i16==1)
	        {
	            i16 = 0;
	        }else if(i16==0)
	        {
	            i16 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i17==1)
	        {
	            i17 = 0;
	        }else if(i17==0)
	        {
	            i17 = 1;
	        }
	    }
	}else if(input1 == 'D')//row D
	{
	   if(input2 == '1')
	    {
	        if(i18==1)
	        {
	            i18 = 0;
	        }else if(i18==0)
	        {
	            i18 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i19==1)
	        {
	            i19 = 0;
	        }else if(i19==0)
	        {
	            i19 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i20==1)
	        {
	            i20 = 0;
	        }else if(i20==0)
	        {
	            i20 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i21==1)
	        {
	            i21 = 0;
	        }else if(i21==0)
	        {
	            i21 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i22==1)
	        {
	            i22 = 0;
	        }else if(i22==0)
	        {
	            i22 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i23==1)
	        {
	            i23 = 0;
	        }else if(i23==0)
	        {
	            i23 = 1;
	        }
	    }
	}else if(input1 == 'E')//row E
	{
	    if(input2 == '1')
	    {
	        if(i24==1)
	        {
	            i24 = 0;
	        }else if(i24==0)
	        {
	            i24 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i25==1)
	        {
	            i25 = 0;
	        }else if(i25==0)
	        {
	            i25 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i26==1)
	        {
	            i26 = 0;
	        }else if(i26==0)
	        {
	            i26 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i27==1)
	        {
	            i27 = 0;
	        }else if(i27==0)
	        {
	            i27 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i28==1)
	        {
	            i28 = 0;
	        }else if(i28==0)
	        {
	            i28 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i29==1)
	        {
	            i29 = 0;
	        }else if(i29==0)
	        {
	            i29 = 1;
	        }
	    }
	}else if(input1 == 'F')//row F
	{
	    if(input2 == '1')
	    {
	        if(i30==1)
	        {
	            i30 = 0;
	        }else if(i30==0)
	        {
	            i30 = 1;
	        }
	    }else if(input2 == '2')
	    {
	        if(i31==1)
	        {
	            i31 = 0;
	        }else if(i31==0)
	        {
	            i31 = 1;
	        }
	    }else if(input2 == '3')
	    {
	        if(i32==1)
	        {
	            i32 = 0;
	        }else if(i32==0)
	        {
	            i32 = 1;
	        }
	    }else if(input2 == '4')
	    {
	        if(i33==1)
	        {
	            i33 = 0;
	        }else if(i33==0)
	        {
	            i33 = 1;
	        }
	    }else if(input2 == '5')
	    {
	        if(i34==1)
	        {
	            i34 = 0;
	        }else if(i34==0)
	        {
	            i34 = 1;
	        }
	    }else if(input2 == '6')
	    {
	        if(i35==1)
	        {
	            i35 = 0;
	        }else if(i35==0)
	        {
	            i35 = 1;
	        }
	    }            
	}else
	{
	    cout << "WRONG INPUT(S)";// ROw doesn't match so says wrong input
	    return 0;
	}
    
    //assign the change to characters
	if(i0==0){p0 = 'O';}else{p0 = 'X';}
	if(i1==0){p1 = 'O';}else{p1 = 'X';}
	if(i2==0){p2 = 'O';}else{p2 = 'X';}
	if(i3==0){p3 = 'O';}else{p3 = 'X';}
	if(i4==0){p4 = 'O';}else{p4 = 'X';}
	if(i5==0){p5 = 'O';}else{p5 = 'X';}
	if(i6==0){p6 = 'O';}else{p6 = 'X';}
	if(i7==0){p7 = 'O';}else{p7 = 'X';}
	if(i8==0){p8 = 'O';}else{p8 = 'X';}
	if(i9==0){p9 = 'O';}else{p9 = 'X';}
	if(i10==0){p10 = 'O';}else{p10 = 'X';}
	if(i11==0){p11 = 'O';}else{p11 = 'X';}
	if(i12==0){p12 = 'O';}else{p12 = 'X';}
	if(i13==0){p13 = 'O';}else{p13 = 'X';}
	if(i14==0){p14 = 'O';}else{p14 = 'X';}
	if(i15==0){p15 = 'O';}else{p15 = 'X';}
	if(i16==0){p16 = 'O';}else{p16 = 'X';}
	if(i17==0){p17 = 'O';}else{p17 = 'X';}
	if(i18==0){p18 = 'O';}else{p18 = 'X';}
	if(i19==0){p19 = 'O';}else{p19 = 'X';}
	if(i20==0){p20 = 'O';}else{p20 = 'X';}
	if(i21==0){p21 = 'O';}else{p21 = 'X';}
	if(i22==0){p22 = 'O';}else{p22 = 'X';}
	if(i23==0){p23 = 'O';}else{p23 = 'X';}
    if(i24==0){p24 = 'O';}else{p24 = 'X';}
	if(i25==0){p25 = 'O';}else{p25 = 'X';}
	if(i26==0){p26 = 'O';}else{p26 = 'X';}
	if(i27==0){p27 = 'O';}else{p27 = 'X';}
	if(i28==0){p28 = 'O';}else{p28 = 'X';}
    if(i29==0){p29 = 'O';}else{p29 = 'X';}
	if(i30==0){p30 = 'O';}else{p30 = 'X';}
	if(i31==0){p31 = 'O';}else{p31 = 'X';}
	if(i32==0){p32 = 'O';}else{p32 = 'X';}
	if(i33==0){p33 = 'O';}else{p33 = 'X';}
	if(i34==0){p34 = 'O';}else{p34 = 'X';}
	if(i35==0){p35 = 'O';}else{p35 = 'X';}
	
	for(int i=0; i<25; i++)//25 lines to push up code
	{cout << endl;
	}
	//redraws the grid with change
	cout << "     1 2 3 4 5 6    " << endl;
	cout << "   - - - - - - - -  " << endl;
	cout << " A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " | A" << endl;
	cout << " B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " | B" << endl;
	cout << " C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " | C" << endl;
	cout << " D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " | D" << endl;
	cout << " E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " | E" << endl;
	cout << " F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " | F" << endl;
	cout << "   - - - - - - - -  " << endl << endl;
	
	cout << "What piece do you think it was? -> ";//ask for guess
	cin >> input3;
	cin >> input4;
    input3 = toupper(input3);
    
	cout << endl << endl;
	
	if(input1 == input3 && input2 == input4)//if statement to see if the guess was correct or not
	{
	    cout <<"*** Congratulations, you did it! ***" <<endl <<endl << "Thank you for playing.  Exiting...";
	}else
	{
	    cout << "Sorry, it was "<< input3 << input4 << ". Better luck next time."<<endl<<endl<<"Thank you for playing.  Exiting...";
	}
	
	
	return 0;
}//-------------------------------------------------------------------------------------------END OF CODE-------------------------------------------------------------------------------------------------
