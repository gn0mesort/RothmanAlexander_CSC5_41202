/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: 
 * Created on January 5, 2016, 9:29 AM
 */
//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned char hrsWrkd = 40; //Hours worked (hrs)
    float payRate = 1e1f, //Pay Rate in dollars/hour 
          payChck; //Total pay check in dollars
    //Input data
    
    //Calculate or map inputs to outputs
    payChck = payRate * hrsWrkd; //Calculate pay check in dollars
    //Output the results
    cout << "Pay Rate     = $ " << payRate << "'s/hr" << endl;
    cout << "Hours Worked =   " <<  static_cast<int>(hrsWrkd) << " hrs" << endl;
    cout << "Pay Check    = $" << payChck << endl;
    
    //Exit stage right
    return 0;
}

