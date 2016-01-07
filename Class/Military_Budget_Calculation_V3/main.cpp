/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate the military budget of the USA as a percentage of the Federal budget
 * Created on January 7, 2016, 10:18 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
const char CNV_PERC = 100; //Conversion to percentage

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    float milBdgt = 600e9f, //The total Military budget for the USA
          fedBdgt = 3.8e12f, //The total Federal budget for the USA
          percMil; //The percentage of the Federal budget used by the Military
    
    //Input Data
    
    //Calculate Output
    percMil = milBdgt / fedBdgt * CNV_PERC;
    
    //Output Results
    cout << "Total Military Budget:                                $"; 
    cout << milBdgt << endl;
    cout << "Total Federal Budget:                                 $"; 
    cout << fedBdgt << endl;
    cout << "Military Budget as a percentage of the Federal Budget: "; 
    cout << percMil << "%" << endl;
    
    //Exit
    return 0;
}

