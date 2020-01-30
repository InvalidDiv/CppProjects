#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
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
	
	char input;
	int loop = 0;
	int sum = 0;
	int outer = 0;
	
	while(outer<1)
	{
		while(loop<1)
		{
			loop++;
			//forming the box
			
			//row 1
			i0 = rand() % 2;
			i1 = rand() % 2;
			i2 = rand() % 2;
			i3 = rand() % 2;
			i4 = rand() % 2;
			i5 = rand() % 2;
				
			sum = i0+i1+i2+i3+i4+i5;
			
			if(sum%2==0)
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
			
			if(sum%2==0)
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
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
		
		}
	
	loop = 0;
	//breaking the row assignment into two parts so that less memory/workload is used when assigning the odd parity in columns.
	
		while(loop<1)
		{
			loop++;
			//row 4
			i18 = rand() % 2;
			i19 = rand() % 2;
			i20 = rand() % 2;
			i21 = rand() % 2;
			i22 = rand() % 2;
			i23 = rand() % 2;
			
			sum = i18+i19+i20+i21+i22+i23;
			
			if(sum%2==0)
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
			
			if(sum%2==0)
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
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 1
			sum = i0+i6+i12+i18+i24+i30;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 2
			sum = i1+i7+i13+i19+i25+i31;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 3
			sum = i2+i8+i14+i20+i26+i32;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 4
			sum = i3+i9+i15+i21+i27+i33;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 5
			sum = i4+i10+i16+i22+i28+i34;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
			//column 6
			sum = i5+i11+i17+i23+i29+i35;
			
			if(sum%2==0)
				{
				loop--;
				continue;
				}
			
		}
		
	//Assign all random integers to characters, all 1s are Xs and all 0s are Os.
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
	
	cout << "Enter r to randomize to board, or row and column to change a value -> " << endl;
	
	input = '\0';
	
	while(cin >> input && (input!='R'||input!='r'||input!='X'||input!='x'))
	{
	    
	
	
	outer++;
	}
	return 0;
}