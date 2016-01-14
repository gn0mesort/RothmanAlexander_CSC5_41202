/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate square roots the Babylonian way
 * Created on January 13, 2016, 10:46 AM
 * Version 2: Uses loop to end calculation
 */

//System Libraries
#include <iostream>
#include <cmath>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int count = 0;
    float number, //The number to find the root of
          guess, //Intermediate values the asymptotically approach sqrt(number)
          r,
          tol = 0.001f; //The accuracy of the result/tolerance
    
    //Input Data
    cout << "Input the value to compute the square root of: ";
    cin >> number;
    
    //Calculate Output
    //Approximate sqrt first pass
    guess = number / 2; //Only preform once
   
    //Output values to check
    cout << "INPUT VALUE:         " << number << endl;
    cout << "ACTUAL SQUARE ROOT:  " << sqrt(number) << endl;
    cout << endl;
    
    //Output initial values
    guess = number /2;
    cout << "INITIAL GUESS:   " << guess << endl;
    
    //Loop approximating the square root
    do {
        r = number / guess;
        guess = (guess + r) / 2;
        ++count;
    } while(abs((r - guess) / guess) * 100 > tol); //End the loop when close enough
    
    //Output Results
    cout << "THE GUESS:       " << guess << endl;
    cout << "THE RESULT:      " << r << endl;
    cout << "NUMBER OF LOOPS: " << count << endl;
    
    //Exit
    return 0;
}

