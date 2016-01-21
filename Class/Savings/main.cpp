/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Interest rates and savings
 * Created on January 21, 2016, 11:05 AM
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
    float balance = 100.0f, //Initial balance in dollars
          intRate = 0.05f, //Interest rate / year
          rule72 = 0.72f / intRate; //Rule of 72, future value = 2 * present value
    
    cout << "Fun Look at Savings and rule of 72" << endl;
    cout << "https://california.municipalbonds.com/bonds/recent/" << endl;

    //Output Results
    cout << "INTEREST RATE: " << intRate * 100 << "%" << endl;
    cout << "DOUBLING TIME: " << rule72 << " years" << endl;
    //Output Table
    cout << "YEAR YEAR BALANCE INTEREST" << endl; //Table Heading
    //Calculate the savings
    cout << fixed << setprecision(2) << showpoint;
    for(int y = 0, year = 2016; y <= 50; ++y, ++year){
        cout << setw(2) << y << " " << setw(6) << year << " " << setw(7) 
             << balance << " " << setw(6) << balance * intRate << endl;
        balance *= (1 + intRate);
    }

    //Exit
    return 0;
}

