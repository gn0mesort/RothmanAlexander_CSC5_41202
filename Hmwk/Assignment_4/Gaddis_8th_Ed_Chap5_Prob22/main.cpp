 /* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Square Display
 * Created on January 24, 2016, 3:00 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const char X = 'X'; //The character to use for the box
    unsigned short sideLn; //The length of the sides of the box
    
    //Input Data
    do{ //Input Validation
    //Read in side length  
    cout << "How long should each side be? ";
    cin >> sideLn;
    } while (sideLn > 15);
    
    //Output the box
    for(int i = 0; i < sideLn; ++i){ //print box columns
        for(int j = 0; j < sideLn; ++j){ //print box rows
            cout << X;
        }
        cout << endl;
    }
    
    //Exit
    return 0;
}

