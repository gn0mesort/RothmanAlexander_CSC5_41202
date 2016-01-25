/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Hotel Occupancy
 * Created on January 22, 2016, 7:44 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short numFlrs, //The number of floors in the hotel
                   numRms, //The number of rooms in the current floor
                   totRms; //The running total of rooms
    
    //Input Data
    //Read in the number of floors
    cout << "How many floors are in your hotel? ";
    cin >> numFlrs;
    
    for(int i = 0; i < numFlrs; ++i){ //Read in the number of rooms for each floor
        //Read in the rooms on the current floor
        cout << "How many rooms are on floor " << i + 1 << "? ";
        cin >> numRms;
        //Calculate new total rooms
        totRms += numRms;
    }
    
    //Output Results
    cout << "NUMBER OF FLOORS: " << numFlrs << endl;
    cout << "TOTAL ROOMS:      " << totRms << endl;
    
    //Exit
    return 0;
}

