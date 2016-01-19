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
    //Solution is only precise to 47 terms or 235 days
    //Declaration and Initialization
    const unsigned char DYSREP = 5; //The number of days to reproduce crud
    unsigned short nDays, //The number of days to allow crud reproduction
                   nTerms; //The number of fibonnaci terms to generate
    unsigned int nFib, //The current number in the sequence
                 nLast, //The last number in the sequence
                 temp; //Temporary value used to hold the last number during calculation
    float crdWght; //The weight of the crud in pounds

    //Input Data
    cout << "Solution to Problem Savitch 8th Ed. Chap 3 Prob 10"
            << endl;
    cout << "THE FIBONNACI SEQUENCE" << endl << endl;
    cout << "Input a number of days for crud production: ";
    cin >> nDays;
    cout << "Input the current weight of the crud in pounds: ";
    cin >> crdWght;

    //Calculate and output terms
    nTerms = (nDays / DYSREP) + 1; //Convert days to the sequence terms
    cout << "FIBONNACI SEQUENCE TERMS:" << endl;
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
    cout << endl;
    cout << "CRUD WEIGHT AFTER " << nDays << " DAYS: " 
         << crdWght * nFib << " pounds" << endl;
    cout << endl << endl;

    //Exit Solution 1
    return 0;
}

