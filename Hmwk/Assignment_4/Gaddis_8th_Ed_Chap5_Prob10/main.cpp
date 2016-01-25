/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate Average Rainfall
 * Created on January 22, 2016, 7:51 PM
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
     short years; //The number of years you have rainfall data on
     unsigned short cRnFl, //The current input rainfall
                    tRnFl, //The running total rainfall
                    aRnFl; //The average rainfall
    
     //Input Data
    do{ //Input Validation
    //Read in years    
    cout << "NUMBER OF YEARS IN DATA SET: ";
    cin >> years;
    } while(years <= 0);
    
    cout << "Input each month of data for each year." << endl;
    cout << "All measurements in inches" << endl;
    //Read in rainfall for each month for each year
    for(int i = 0; i < years; ++i){ //Loop through each year
        for(int j = 0; j < 12; ++j){ //Loop through each month
            cout << "RAINFALL FOR MONTH " << j + 1 << " OF YEAR " << i + 1 
                 << ": ";
            cin >> cRnFl;
            //Add input rainfall to total rainfall
            tRnFl += cRnFl;
        }
    }
    
    //Calculate Output
    aRnFl = tRnFl / (12 * years);
    
    //Output Results
    cout << "TOTAL YEARS:      " << years << endl;
    cout << "TOTAL RAINFALL:   " << tRnFl << " inches" << endl;
    cout << "AVERAGE RAINFALL: " << aRnFl <<  " inches / month" << endl;
    
    //Exit
    return 0;
}

