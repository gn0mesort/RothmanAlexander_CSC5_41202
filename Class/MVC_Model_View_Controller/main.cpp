/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Model View Controller example
 * Created on January 28, 2016, 9:42 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
const char PERCENT = 100;

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    float pv = 100.0f, //Present Value
          fv = pv; //Future Value
    int iRate = 6, //Interest Rate
        nComp = 12; //Number of compounding periods
    
    //Calculate and display table
    //Output Heading
    cout << fixed << setprecision(2) << showpoint;
    cout << "YEAR SAVINGS" << endl;

    for (int year = 0; year <= nComp; ++year) {
        int ifv = fv * PERCENT; //Shift 2 places
        fv = static_cast<float> (ifv + 0.005f) / PERCENT; //Convert back
        cout << setw(4) << year << setw(8) << fv << endl;
        fv *= (1 + static_cast<float> (iRate) / PERCENT);
    }
    cout << endl;

    //The MVC concept separates the view from the model
    //Declare and Initialize Array
    float balance[nComp + 1];
    balance[0] = pv;

    //Calculate the array i.e. model
    for (int year = 0; year <= nComp; ++year) {
        int ifv = balance[year] * PERCENT; //Shift 2 places
        balance[year] = static_cast<float> (ifv + 0.005f) / PERCENT; //Convert back
        balance[year + 1] = balance[year] * (1 + static_cast<float> (iRate) / PERCENT);
    }

    //Display Model
    cout << "YEAR SAVINGS" << endl;
    for (int year = 0; year <= nComp; ++year) {
        cout << setw(4) << year << setw(8) << balance[year] << endl;
    }

    //Exit
    return 0;
}

