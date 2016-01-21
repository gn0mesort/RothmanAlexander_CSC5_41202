/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Inflation
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
    float price = 0.25f, //Initial price in dollars
          inflate = 0.07f, //Inflation rate / year
          rule72 = 0.72f / inflate; //Rule of 72, future value = 2 * present value
    
    cout << "Fun Look at Inflation and rule of 72" << endl;

    //Output Results
    cout << "INFLATION RATE: " << inflate * 100 << "%" << endl;
    cout << "DOUBLING TIME: " << rule72 << " years" << endl;
    //Output Table
    cout << "YEAR YEAR PRICE   INFLATION" << endl; //Table Heading
    //Calculate the savings
    cout << fixed << setprecision(2) << showpoint;
    for(int y = 0, year = 2016; y <= 50; ++y, ++year){
        cout << setw(2) << y << " " << setw(6) << year << " " << setw(4) 
             << price << " " << setw(7) << price * inflate << endl;
        price *= (1 + inflate);
    }

    //Exit
    return 0;
}

