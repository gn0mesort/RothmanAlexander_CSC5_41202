/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate the value of some quantity of quarters, dimes, and nickels based on user input
 * Created on January 5, 2016, 5:23 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
const char CNV_NCL = 5; //Conversion from nickels to cents
const char CNV_DIM = 10; //Conversion from dimes to cents
const char CNV_QTR = 25; //Conversion from quarters to cents
const char CNV_DOL = 100; //Conversion from cents to dollars

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short numQrtr, //The number of quarters
                   numNckl, //The number of nickels
                   numDime, //The number of dimes 
                   total; //The total value of all the coins in cents
    
    //Input Data
    cout << "Enter the quantity of each type of coin." << endl;
    cout << "Press return after entering a number." << endl;
    //Read in the number of quarters
    cout << "Number of Quarters: ";
    cin >> numQrtr;
    //Read in the number of dimes
    cout << "Number of Dimes:    ";
    cin >> numDime;
    //Read in the number of nickels
    cout << "Number of Nickels:  ";
    cin >> numNckl;
    
    //Calculate Output
    total = (CNV_QTR * numQrtr) + (CNV_DIM * numDime) + (CNV_NCL * numNckl); //Calculate the total by multiplying the number of each type of coin by its value in cents
    
    //Output Data
    cout << "Total:              " << total << " cents" << endl; //Output the total in cents
    cout << "Total in dollars:  $" << total / CNV_DOL << "." 
         << total % CNV_DOL << endl; //Output the total in dollars. Whole dollars are calculated by dividing the total by 100. Cents are calculated by finding the remainder of a division by 100
    
    //Exit
    return 0;
}

