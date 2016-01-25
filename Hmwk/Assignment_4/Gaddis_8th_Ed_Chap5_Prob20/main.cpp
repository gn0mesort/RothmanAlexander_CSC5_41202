/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Random number guess game
 * Created on January 24, 2016, 3:41 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short gsNum, //The number the player needs to guess
          inGsNum; //The number that player has guessed
    
    srand(static_cast<int>(time(0))); //Initialize PRNG
    
    gsNum = rand() % 101; //Generate a random number to guess
    
    cout << "Random Number Guessing Game" << endl;
    do{ //Loop till the player wins
        //Input Data
        //Read in the player's guess
        cout << "Guess a number: ";
        cin >> inGsNum;
        
        //Output if higher or lower
        if(inGsNum < gsNum){ //Guess is lower than the answer
            cout << "Too low, try again." << endl;
        }
        else if (inGsNum > gsNum){ //Guess is higher than the answer
            cout << "Too high, try again." << endl;
        }
      
    } while(inGsNum != gsNum);
    
    //Output winning text
    cout << "You got it!" << endl;    
    
    //Exit
    return 0;
}

