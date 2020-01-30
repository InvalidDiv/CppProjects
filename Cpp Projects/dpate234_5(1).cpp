/*
    CS 141: Spring 2018 Midterm 2 INSTRUCTIONS
 
     Rules/Comments:
        1. You are provided skeleton code to work from.
        2. You may not delete anything that is provided in the skeleton code.
        3. You are only allowed to add/modify code in the public section of the class. 
           You cannot change code in the private section of the class.
        4. You may not change the contents of the main() function.  
        5. You may not add any libraries besides the ones already provided to you.
        6. The below set of sample runs of your program is not exhaustive.  There could
           be other cases for you to consider.
 
    Your completed program must be called:
          netid_n.cpp
    where netid is your netid and n is the start time of your lab.  (If your UIC email
    address were dreed@uic.edu,then your netid is the first part, to the left of the '@'.)
    If you were in the 8am lab, then your submission would be:
           dreed_8.cpp
    You would then need to submit it via a Google Form.
    NOTE: THERE IS NO REQUIREMENT TO ZIP YOUR FILE THIS TIME. 
    ------------------------------------------------------------------------------
 
    Problem: Write 3 functions to make the program below work. There are two different types 
    		 of constructors needed to make the two different initializations of the class work. 
    		 Finally, there is a comparison function needed to make the final if-else statement work. 
 
    Running the program could look like:
        Enter the attributes of the actor: 4.56 F
        Actor1 info is: 4.56 F
        Actor2 info is: 4.56 F
        Is actor2 same as actor0?
        NO

	And another run of the program might be:
        Enter the attributes of the actor: 5.67 M
        Actor1 info is: 5.67 M
        Actor2 info is: 5.67 M
        Is actor2 same as actor0?
        YES
*/
#include <iostream>
using namespace std;

//------------------------------------------------------------------------
class Actor {
    private:
        float height;
        char gender;

    // Declare and define the functions here:
    
    public:
        float getheight() {
            return height;
        }
        char getgender() {
            return gender;
        }
        Actor() {
        	height = 5.67;
        	gender = 'M';
        }
        
        //====================================
        //Write remaining functions here
        
		Actor(float theHeight,char theGender) : height(theHeight), gender(theGender){}
		
		Actor(const Actor& otherActor){
			height = otherActor.height;
			gender = otherActor.gender;
		}
		
		bool sameAs(const Actor& otherActor){
			
			if((this->height==otherActor.height)&&(this->gender==otherActor.gender))
			{
				return true;
			}
			return false;
		}
        //====================================



};


//------------------------------------------------------------------------
// This portion cannot be edited
//------------------------------------------------------------------------

int main()
{
    // Taking Input
    float height;
    char gender;
    cout << "Enter the attributes of the actor: ";
    cin >> height;
    cin >> gender;

    // Declaring instances of class using constructor
    Actor actor0;

    Actor actor1(height,gender);
    cout << "Actor1 info is: " << actor1.getheight() << " " << actor1.getgender() << endl;
  
    // Declaring instance of class using copy constructor
    Actor actor2(actor1);
	cout << "Actor2 info is: " << actor2.getheight() << " " << actor2.getgender() << endl;

    // Comparing two objects using comparison function
    cout << "Is actor2 same as actor0?" << endl;
    if (actor2.sameAs(actor0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
