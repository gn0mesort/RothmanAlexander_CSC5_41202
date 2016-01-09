/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Convert the given number of square feet into acres
 * Created on January 5, 2016, 8:19 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
unsigned short CNV_ACR = 43560;

//Functional Prototypes

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
    acres = sqrFeet / static_cast<float>(CNV_ACR); //Calculate acres as a floating point value
    
    //Output Results
    cout << "Square Feet:" << setw(10) << sqrFeet << " square feet" << endl;
    cout << "Acres:" << setw(14) << fixed << showpoint << setprecision(2) 
         << acres << " acres" << endl;
    
    //Exit
    return 0;
}

