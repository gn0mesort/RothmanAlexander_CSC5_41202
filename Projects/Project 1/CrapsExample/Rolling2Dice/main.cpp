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
    //Declaration and Initialization
    const unsigned short MAXTHRW = 36000; //Total throws
    unsigned char die1, //The first die
                  die2; //The second die
    unsigned short frq2 = 0, //Frequencies
                   frq3 = 0, 
                   frq4 = 0, 
                   frq5 = 0, 
                   frq6 = 0, 
                   frq7 = 0, 
                   frq8 = 0, 
                   frq9 = 0, 
                   frq10 = 0, 
                   frq11 = 0, 
                   frq12 = 0,
                   total;
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Calculate Output
    for(int i = 0; i < MAXTHRW; ++i){
        die1 = (rand() % 6) + 1; //Generate die 1
        die2 = (rand() % 6) + 1; //Generate die 2
        
        switch (die1 + die2){ //Increment the correct frequency value
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
            case 7:
            {
                ++frq7;
                break;
            }
            case 8:
            {
                ++frq8;
                break;
            }
            case 9:
            {
                ++frq9;
                break;
            }
            case 10:
            {
                ++frq10;
                break;
            }
            case 11:
            {
                ++frq11;
                break;
            }
            case 12:
            {
                ++frq12;
                break;
            }
            default: { cout << "Not Possible" << endl; }
        }
    }
    
    //Calculate total throws
    total = frq2 + frq3 + frq4 + frq5 + frq6 + frq7 + frq8 + frq9 + frq10 
                 + frq11 + frq12;
    
    //Output Results
    cout << fixed << setprecision(2) << showpoint;
    cout << "TOTAL THROWS: " << total << endl;
    //Output frequences as a percentage
    cout << "PERCENTAGES:" << endl;
    cout << "FREQUENCY 2:  " << ((1.0f * frq2) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 3:  " << ((1.0f * frq3) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 4:  " << ((1.0f * frq4) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 5:  " << ((1.0f * frq5) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 6:  " << ((1.0f * frq6) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 7:  " << ((1.0f * frq7) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 8:  " << ((1.0f * frq8) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 9:  " << ((1.0f * frq9) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 10: " << ((1.0f * frq10) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 11: " << ((1.0f * frq11) / total) * 100 << "%" << endl;
    cout << "FREQUENCY 12: " << ((1.0f * frq12) / total) * 100 << "%" << endl;
    cout << endl;
    //Out put frequencies as an integer
    cout << "RAW FREQUENCY:" << endl;
    cout << "FREQUENCY 2:  " << frq2 << endl;
    cout << "FREQUENCY 3:  " << frq3 << endl;
    cout << "FREQUENCY 4:  " << frq4 << endl;
    cout << "FREQUENCY 5:  " << frq5 << endl;
    cout << "FREQUENCY 6:  " << frq6 << endl;
    cout << "FREQUENCY 7:  " << frq7 << endl;
    cout << "FREQUENCY 8:  " << frq8 << endl;
    cout << "FREQUENCY 9:  " << frq9 << endl;
    cout << "FREQUENCY 10: " << frq10 << endl;
    cout << "FREQUENCY 11: " << frq11 << endl;
    cout << "FREQUENCY 12: " << frq12 << endl;
    
    //Exit
    return 0;
}

