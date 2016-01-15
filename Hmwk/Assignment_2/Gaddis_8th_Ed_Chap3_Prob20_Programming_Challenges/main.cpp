/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate how many slices a pizza may have
 * Created on January 14, 2016, 5:45 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
const float PI = atan(1) * 4;

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const float PCSAREA = 14.125f; //The area of a single slice of pizza in inches
    float pPcs; //The number of pieces of pieces the pizza can be divided into
    unsigned short pDmtr, //The diameter of the pizza in inches
                   pRds; //The radius of the pizza in inches
    
    //Input Data
    //Read in the diameter
    cout << "Input the diameter of your pizza in inches: ";
    cin >> pDmtr;
    
    //Calculate output
    pRds = pDmtr / 2; //Calculate radius
    pPcs = (pRds * pRds * PI) / PCSAREA; //Calculate number of possible pieces
    
    //Output Results
    cout << fixed << setprecision(1) << showpoint << "Your pizza may have up to "
         << pPcs << " slices." << endl;
    
    //Exit
    return 0;
}

