/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: How many does it take?
 * Created on January 6, 2016, 11:38 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
const char WT_BILL = 1; //Weight of a single bill in grams
const float CNV_LBS = 1/435.5f; //Conversion from grams to pounds

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned int amtStl; //The amount to steal
    unsigned short denom; //The bill denomination in dollars
    unsigned char wtPers = 80, //The weight one person can carry in lbs
                  nPerps; //The number of perpetrators
    
    //Input Data
    cout << "How much money would you like to acquire? ";
    cin >> amtStl;
    cout << "What is the bill denomination desired? ";
    cin >> denom;
    
    //Calculate Output
    nPerps = CNV_LBS * amtStl * WT_BILL / denom / wtPers; // Calculate the number of perpetrators
    nPerps += 1; //Round up to the nearest whole person.
    //Output Data
    cout << "Amount Desired =                           $" << amtStl << endl;
    cout << "Desired Denomination =                     $" << denom << endl;
    cout << "Number of Individuals required on the job = "; 
    cout << static_cast<int>(nPerps) << " people" << endl;
    
    //Exit
    return 0;
}

