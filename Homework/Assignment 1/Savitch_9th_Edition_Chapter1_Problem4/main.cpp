/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate how far an object will fall based on a user input time value
 * Created on January 5, 2016, 6:06 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short accel = 32, //The acceleration in feet / second
          time, //The time in seconds
          dist; //The distance in feet
    
    //Input Data
    cout << "Enter a time in seconds to calculate how far the object would fall in freefall." << endl;
    cout << "Press return after entering a number." << endl;
    //Read in time
    cout << "Enter the time: ";
    cin >> time;
    
    //Calculate Output
    dist = (accel * (time * time)) / 2; //distance = acceleration * time^2 / 2
    
    //Output Results
    cout << "Acceleration:   " << accel << " feet / second" << endl;
    cout << "Time:           " << time << " seconds" << endl;
    cout << "Distance:       " << dist << " feet" << endl;
    
    //Exit
    return 0;
}

