/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Preform coin tosses
 * Created on February 3, 2016, 7:39 AM
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
char cnToss(void);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short totHead = 0, //The total number of heads
                   totTail = 0, //The total number of tails
                   tosses; //The number of tosses to perform
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Input Data
    cout << "How many tosses would you like to preform: ";
    cin >> tosses;
    
    //Calculate Output
    for(int i = 0; i < tosses; ++i){ //Perform each toss
        cnToss() == 1 ? ++totHead : ++totTail; //increment the correct value per toss
    }
    
    //Output Results
    cout << "TOTAL HEADS:  " << totHead << endl; 
    cout << "TOTAL TAILS:  " << totTail << endl;
    cout << "TOTAL TOSSES: " << totHead + totTail << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/*********************************Coin Toss************************************/
/******************************************************************************/
//  Perform a single coin toss
//Output
//  toss : the value of the toss as either 1 or a 2
char cnToss(){
    unsigned char toss = rand() % 2 + 1;
    cout << (toss == 1 ? "HEADS" : "TAILS") << endl;
    return toss;
}
