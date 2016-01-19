/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Menu
 * Created on January 19, 2016, 8:31 AM
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
    bool reDsply = true; //Redisplay menu or exit when false
    unsigned short nSltn; //Problem solution to display

    //Menu to display solution
    do {
        //Read in problem to display
        cout << "Assignment 3 Problem Set" << endl;
        cout << "Type 1 to display Savitch 8th Ed. Chap 3 Prob 10" << endl;
        cout << "Type 2 to display Savitch 8th Ed. Chap 3 Prob 11" << endl;
        cout << "Type 3 to display Problem 3" << endl;
        cout << "Type 4 to display Problem 4" << endl;
        cout << "Type 5 to display Problem 5" << endl;
        cout << "Type 6 to display Problem 6" << endl;
        cout << "Type 7 to display Problem 7" << endl;
        cout << "Type 8 to display Problem 8" << endl;
        cout << "Type 9 to display Problem 9" << endl;
        cout << "Type 10 to display Problem 10" << endl;
        cout << "Type anything else to exit" << endl;
        cout << "SOLUTION: ";
        cin >> nSltn;
        cout << endl;

        switch (nSltn) {
            case 1:
            {
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
                    }//Calculate next term
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
                break;
            }
            case 2:
            {
                cout << "Solution to Problem Savitch 8th Ed. Chap 3 Prob 11" 
                     << endl << endl;
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
                break;
            }
            case 3:
            {
                cout << "Solution to Problem 3" << endl << endl;
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
            default:
            {
                cout << "Exiting the program..." << endl;
                reDsply = false;
            }
        }

    } while (reDsply);

    //Exit
    return 0;
}

