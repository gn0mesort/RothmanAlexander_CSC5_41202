/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Approximate Pi
 * Created on January 19, 2016, 11:43 AM
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
    //Declaration and Initialization
    bool add = false; //Add or subtract the next term
    unsigned int nTerms; //The number of terms
    float pi; //The computed value
    
    //Input Data
    cout << "Enter the number of terms to compute: ";
    cin >> nTerms;

    //Calculate Output
    for (int i = 1; i < nTerms; ++i) { //Calculate the input number of terms
        if (i % 2 != 0) {
            if (add) {
                pi += 4 * (1.0f / i);
                add = false;
            } else {
                pi -= 4 * (1.0f / i);
                add = true;
            }
        }

    }
    pi = -pi;

    //Output Results
    cout << "ACTUAL VALUE OF PI: " << atan(1) * 4 << endl;
    cout << "APPROXIMATE VALUE: " << pi << endl;

    //Exit
    return 0;
}

