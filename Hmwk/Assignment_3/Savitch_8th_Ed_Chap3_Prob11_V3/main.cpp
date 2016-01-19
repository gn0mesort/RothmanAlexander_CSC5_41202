/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate e^x using a tolerance
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
    unsigned int nTerm = 1; //Counter to determine how many terms
    float eToX = 1, //e^x
          tol = 1e-6f, //The tolerance for approximation
          term = 1, //The factorial of n
          x; //The number to raise e to
    
    //Input Data
    //Read in x
    cout << "Input the number to calculate e to the power of: ";
    cin >> x;
    
    //Calculate Results
    do{
        term *= x / nTerm++;
        eToX += term;
    }while (term > tol);
    
    //Output Results
    cout << "EXACT VALUE OF e^" << x << ": " << exp(x) << endl;
    cout << "NUMBER OF TERMS REQUIRED TO APPROXIMATE e^" << x << ": " 
         << nTerm << endl;
    cout << "APPROXIMATE VALUE OF e^" << x << ": " << eToX << endl;
    cout << endl << endl;
    
    //Exit
    return 0;
}

