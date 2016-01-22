/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Fibonnaci Sequence & Crud Problem
 * Created on January 19, 2016, 9:29 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Savitch 8th Edition Chapter 3 Problem 10
    //Solution is only precise to 47 terms
    //Declaration and Initialization
    unsigned short nTerms; //The number of terms wanted
    unsigned int nFib, //The current number in the sequence
                 nLast, //The last number in the sequence
                 temp; //Temporary value used to hold the last number during calculation

    //Problem Information
    cout << "Solution to Problem Savitch 8th Ed. Chap3 Prob10" << endl;
    cout << "THE FIBONNACI SEQUENCE" << endl;
    
    //Input Data
    cout << "Input a number of terms to display: ";
    cin >> nTerms;

    //Calculate and output terms
    for (int i = 0; i < nTerms; ++i) {
        //Initial values
        if (i == 0) {
            nFib = 1;
            nLast = 0;
        }            
        //Calculate next term
        else {
            temp = nFib;
            nFib = nFib + nLast;
            nLast = temp;
        }
        //Output current term
        cout << nFib;
        if (i < nTerms - 1) { //Print a comma between terms except the final term
            cout << ", ";
        }
        if (i % 10 == 0 && i != 0) { //Print a new line every 10 terms
            cout << endl;
        }
    }
    cout << endl << endl;

    //Exit Solution 1
    return 0;
}

