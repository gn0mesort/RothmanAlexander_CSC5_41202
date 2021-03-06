/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate the total sales (in dollars) that the East Coast division of a company will make based on a percentage and the overall total sales.
 * Created on January 5, 2016, 8:01 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
unsigned const char CNV_PER = 100; //Conversion to percentage

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    float percent = 0.58f; //The percentage of overall sales by the East Coast division
    unsigned int ovrSls = 8600000, //The overall sales of the company 
                 total; //The total sales of the East Coast division
    
    //Input Data
    
    //Calculate Output
    total = ovrSls * percent; // Calculate the sales of the East Coast division
    
    //Output Results
    cout << "Overall Sales:                           $" << ovrSls << endl;
    cout << "Predicted Percentage:                     " << (percent * CNV_PER) //Output the percentage as a percentage rather than a floating point number
                                                         << "%" << endl; 
    cout << "Total Sales for the East Coast division: $" << total << endl;
    
    //Exit
    return 0;
}

