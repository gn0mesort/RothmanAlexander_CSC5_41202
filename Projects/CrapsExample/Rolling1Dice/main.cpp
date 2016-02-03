/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Testing Throwing Dice
 * Created on January 25, 2016, 10:09 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Delcaration and Initialization
    const unsigned short MAXTHRW = 36000; //Total throws
    unsigned char die1; //The die
    unsigned short frq1 = 0, //Frequencies
                   frq2 = 0, 
                   frq3 = 0, 
                   frq4 = 0, 
                   frq5 = 0, 
                   frq6 = 0,
                   total;
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Calculate Output
    for(int i = 0; i < MAXTHRW; ++i){
        die1 = (rand() % 6) + 1; //Generate die 1
        
        switch (die1){ //Increment the correct frequency value
            case 1:
            {
                ++frq1;
                break;
            }
            case 2:
            {
                ++frq2;
                break;
            }
            case 3:
            {
                ++frq3;
                break;
            }
            case 4:
            {
                ++frq4;
                break;
            }
            case 5:
            {
                ++frq5;
                break;
            }
            case 6:
            {
                ++frq6;
                break;
            }
            default: { cout << "Not Possible" << endl; }
        }
    }
    
    //Calculate total throws
    total = frq1 + frq2 + frq3 + frq4 + frq5 + frq6;
    
    //Output Results
    cout << fixed << setprecision(2) << showpoint;
    cout << "TOTAL THROWS: " << total << endl;
    //Output frequences as a percentage
    cout << "PERCENTAGES:" << endl;
    cout << "FREQUENCY 1:  " << ((1.0f * frq1) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 2:  " << ((1.0f * frq2) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 3:  " << ((1.0f * frq3) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 4:  " << ((1.0f * frq4) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 5:  " << ((1.0f * frq5) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 6:  " << ((1.0f * frq6) / total) * 100 << "%" << endl;

    cout << endl;
    //Out put frequencies as an integer
    cout << "RAW FREQUENCY:" << endl;
    cout << "FREQUENCY 2:  " << frq1 << endl;
    cout << "FREQUENCY 3:  " << frq2 << endl;
    cout << "FREQUENCY 4:  " << frq3 << endl;
    cout << "FREQUENCY 5:  " << frq4 << endl;
    cout << "FREQUENCY 6:  " << frq5 << endl;
    cout << "FREQUENCY 7:  " << frq6 << endl;

    //Exit
    return 0;
}

