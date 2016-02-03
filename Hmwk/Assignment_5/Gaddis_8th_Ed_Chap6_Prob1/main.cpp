/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate falling distance due to gravity on Earth
 * Created on February 3, 2016, 7:39 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
const float ACLGRAV = 9.8f; //Acceleration due to gravity on Earth

//Function Prototypes
float falDist(short);

//Begin Execution
int main(int argc, char** argv) {
    
    //Calculate and Output results
    cout << fixed << setprecision(2) << showpoint;
    for(int i = 1; i <= 10; ++i){ //loop through times 1 second to 10 seconds
        cout << "If you fall for " << setw(2) << i << " seconds you will fall " 
             << setw(5) << falDist(i) << " meters." << endl;
    }
    
    //Exit
    return 0;
}

/******************************************************************************/
/*******************************Falling Distance*******************************/
/******************************************************************************/
//  Calculate falling distance due to gravity on Earth from time
//Input
//  time : the time in seconds of the fall
//Output
//  distance : the distance of the fall in meters
float falDist(short time){
    return 0.5f * ACLGRAV * (time * time);
}

