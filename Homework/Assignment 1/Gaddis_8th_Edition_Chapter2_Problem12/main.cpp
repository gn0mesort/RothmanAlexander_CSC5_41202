/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Convert the given number of square feet into acres
 * Created on January 5, 2016, 8:19 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned int sqrFeet; //The number of square feet to convert. Input by the user
    float acres; //The number of acres converted from square feet
    
    //Input Data
    cout << "Enter the square footage to convert into acres." << endl;
    cout << "Press return after entering a number." << endl;
    //Read in square feet
    cout << "How many square feet? ";
    cin >> sqrFeet;
    
    //Calculate Output
    acres = sqrFeet / 43560e0f;//Calculate acres as a floating point value
    
    //Output Results
    cout << "Square Feet: " << sqrFeet << " square feet" << endl;
    cout << "Acres:       " << acres << " acres" << endl;
    
    //Exit
    return 0;
}

