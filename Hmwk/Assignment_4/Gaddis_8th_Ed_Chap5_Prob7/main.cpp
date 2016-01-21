/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Table of Salary Doubling starting at a penny
 * Created on January 20, 2016, 11:12 AM
 * Double is required because number of significant digits
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned int salary = 1; //Salary Starting at a penny
    float tPay = salary; //Total pay in dollars by summing salaries
    
    cout << "Solution to Gaddis 8th Ed. Chap5 Prob7" << endl;
    cout << "Display A salary table" << endl;
    
    //Input Data
    
    //Loop to generate the Salary Table and Total Paid
    cout << fixed << setprecision(2) << showpoint;
    cout << " Day   Salary($)       Total($)" << endl;
    cout << setw(4) << 1 << setw(15) << salary / 100.0f 
         << setw(15) << tPay / 100.0f << endl;
    for(int day = 2; day <= 31; ++day){
        //salary *= 2;
        salary <<= 1; //Bitwise Right Shift equivalent to * 2
        tPay += salary;
        cout << setw(4) << day << setw(15) << salary / 100.0 
             << setw(15) << tPay / 100.0 << endl;
    }
    //Output Results
    
    //Exit
    return 0;
}

