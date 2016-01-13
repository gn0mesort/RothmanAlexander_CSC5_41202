/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Check room capacity
 * Created on January 13, 2016, 10:13 AM
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
    //Declare and Initialize Variables
    const unsigned char MAXCAP = 35; //Max capacity of the room
    char delta; //Difference between capacity and utilization
    unsigned short  stsUtil; //Seats actually used
    
    //Input Data
    cout << "How many seats are being utilized in BE200? ";
    cin >> stsUtil;
    
    //Calculate Output
    delta = MAXCAP - stsUtil;
    
    //Output Results
    cout << "Maximum Capacity: " << static_cast<int>(MAXCAP) << " seats" << endl;
    if(delta >= 0){
        cout << "Class will be held." << endl;
        cout << static_cast<int>(delta) << " seats remain." << endl;
        cout << fixed << setprecision(2) << showpoint 
             << static_cast<float>(stsUtil) / MAXCAP * 100.0f 
             << "% of space utilized." << endl;
    }
    else{
        cout << "Room capacity exceeded!!" << endl;
        cout << -static_cast<int>(delta) << " students over capacity." << endl;
        cout << fixed << setprecision(2) << showpoint 
             << static_cast<float>(stsUtil) / MAXCAP * 100.0f 
             << "% of space utilized." << endl;
    }
    
    //Exit
    return 0;
}

