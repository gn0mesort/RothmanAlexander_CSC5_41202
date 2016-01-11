/* 
 * File:   main.cpp
 * Author: Alexander Rothman,Cesar Gonzalez 
 * Purpose: Calculate pay with overtime
 * Created on January 11, 2016, 11:46 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    unsigned char payRate = 10, //The rate of pay in dollars per hour
                  hrsWrk1 = 30, //The hours worked on the first day
                  hrsWrk2 = 50, //The hours worked on the second day
                  ovrTime; //The amount of overtime hours
    unsigned short total1, //The total for the first day
                   total2; //The total for the second day
    
    //Input Data
    
    //Calculate Output
    //First Day
    ovrTime = (hrsWrk1 - 40) > 0 ? hrsWrk1 - 40 : 0; //Calculate overtime hours
    total1 = (hrsWrk1 - ovrTime) * payRate + (ovrTime > 0 ? ovrTime * (1.5f * payRate) : 0); //Calculate total pay
    
    //Second Day
    ovrTime = (hrsWrk2 - 40) > 0 ? hrsWrk2 - 40 : 0; //Calculate overtime hours
    total2 = (hrsWrk2 - ovrTime) * payRate + (ovrTime > 0 ? ovrTime * (1.5f * payRate) : 0); //Calculate total pay
    
    //Output Results
    cout << "Total Pay for " << hrsWrk1 << " hours: " << total1 << endl;
    cout << "Total Pay for " << hrsWrk2 << " hours: " << total2;
    
    //Exit
    return 0;
}

