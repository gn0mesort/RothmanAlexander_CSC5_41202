/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Rock Paper Scissors vs CPU
 * Created on January 20, 2016, 8:50 AM
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    char comp, //The CPUs choice for this turn
         player; //The player's choice for this turn
 
    srand(static_cast<int>(time(0))); //Seed the random number generator
    
    //Output Header
    cout << "Solution to Savitch 7th Ed. Chap3 Prob1" << endl;
    cout << "The ROCK-PAPER-SCISSORS Game" << endl;
    
    //Input Data
    do{
        cout << "What is your move P, R, S? ";
        cin  >> player;
        player = toupper(player);
    }while(!(player == 'P' || player == 'R' || player == 'S'));
    
    //Computer Generated Play
    do{
        comp = rand() % 4 + 80;
    }while(comp == 'Q');
    
    //Output Results
    cout << "The computer played: " << comp << endl;
    cout << "The player played:   " << player << endl;
       
    //Exit
    return 0;
}

