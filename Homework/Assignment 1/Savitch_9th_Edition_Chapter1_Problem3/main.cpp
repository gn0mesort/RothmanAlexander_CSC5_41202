/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate the value of some quantity of quarters, dimes, and nickels based on user input
 * Created on January 5, 2016, 5:23 PM
 */

//System Libraries
#include <iostream>

using namespace std;

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
    total = (25 * numQrtr) + (10 * numDime) + (5 * numNckl); //Calculate the total by multiplying the number of each type of coin by its value in cents
    
    //Output Data
    cout << "Total:              " << total << " cents" << endl; //Output the total in cents
    cout << "Total in dollars:  $" << total / 100 << "." << total % 100 << endl; //Output the total in dollars. Whole dollars are calculated by dividing the total by 100. Cents are calculated by finding the remainder of a division by 100
    
    //Exit
    return 0;
}

