/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate e^x
 * Created on January 19, 2016, 10:36 AM
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
    const unsigned char NTERMS = 13;
    unsigned int factN = 1; //The factorial of n
    float eToX = 1, //e^x
            x; //The number to raise e to

    //Input Data
    //Read in x
    cout << "NUMBERS MUST BE BETWEEN 1 AND 13" << endl;
    cout << "Input the number to calculate e to the power of: ";
    cin >> x;

    //Calculate Results
    for (int n = 1; n <= NTERMS; ++n) {
        factN *= n; //Calculate factorial
        eToX += pow(x, n) / factN; //Calculate e^x
    }

    //Output Results
    cout << "EXACT VALUE OF e^" << x << ": " << exp(x) << endl;
    cout << "APPROXIMATE VALUE OF e^" << x << ": " << eToX << endl;
    cout << endl << endl;

    //Exit
    return 0;
}

