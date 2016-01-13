/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate square roots the Babylonian way
 * Created on January 13, 2016, 10:46 AM
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
    float number, //The number to find the root of
          guess, //Intermediate values the asymptotically approach sqrt(number)
          r;
    
    //Input Data
    cout << "Input the value to compute the square root of: ";
    cin >> number;
    
    //Calculate Output
    //Approximate sqrt first pass
    guess = number / 2; //Only preform once
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output First Pass Results
    cout << "INPUT VALUE:         " << number << endl;
    cout << "ACTUAL SQUARE ROOT:  " << sqrt(number) << endl;
    cout << endl;
    cout << "RESULT AFTER 1 PASS: " << r << endl;
    cout << "GUESS AFTER 1 PASS:  " << guess << endl;
    
    //Approximate sqrt second pass
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output Second Pass
    cout << "RESULT AFTER 2 PASS: " << r << endl;
    cout << "GUESS AFTER 2 PASS:  " << guess << endl;
    
    //Approximate sqrt third pass
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output third Pass
    cout << "RESULT AFTER 3 PASS: " << r << endl;
    cout << "GUESS AFTER 3 PASS:  " << guess << endl;
    
    //Approximate sqrt fourth pass
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output fourth Pass
    cout << "RESULT AFTER 4 PASS: " << r << endl;
    cout << "GUESS AFTER 4 PASS:  " << guess << endl;
    
    //Approximate sqrt fifth pass
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output fifth Pass
    cout << "RESULT AFTER 5 PASS: " << r << endl;
    cout << "GUESS AFTER 5 PASS:  " << guess << endl;
    
    //Approximate sqrt sixth pass
    r = number / guess;
    guess = (guess + r) / 2;
    
    //Output sixth Pass
    cout << "RESULT AFTER 6 PASS: " << r << endl;
    cout << "GUESS AFTER 6 PASS:  " << guess << endl;
    
    //Exit
    return 0;
}

