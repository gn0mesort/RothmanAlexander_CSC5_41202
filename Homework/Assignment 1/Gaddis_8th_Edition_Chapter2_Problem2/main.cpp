/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate the total sales (in dollars) that the East Coast division of a company will make based on a percentage and the overall total sales.
 * Created on January 5, 2016, 8:01 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    float percent = 0.58f; //The percentage of overall sales by the East Coast division
    int ovrSls = 8600000, //The overall sales of the company 
        total; //The total sales of the East Coast division
    
    //Calculate Output
    total = ovrSls * percent;
    
    //Output Results
    cout << "Overall Sales:                           $" << ovrSls << endl;
    cout << "Predicted Percentage:                     " << (percent * 100) << "%" << endl; //Output the percentage as a percentage rather than a floating point number
    cout << "Total Sales for the East Coast division: $" << total << endl;
    
    //Exit
    return 0;
}

