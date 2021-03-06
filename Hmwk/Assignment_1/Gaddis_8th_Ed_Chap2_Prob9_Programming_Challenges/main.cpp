/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Determine the size of data types in my cyborg supercomputer
 * Created on January 9, 2016, 9:29 AM
 */

//System Libraries
#include <iostream> //Standard I/O Library
#include <iomanip> //I/O Manipulation Library

using namespace std;

//User Libraries

//Global Constants
unsigned const char CNV_BIT = 8; //Conversion rate for bytes to bits

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned char chrLnth, //The length of a char type variable in bytes
                  intLnth, //The length of a int type variable in bytes
                  fltLnth, //The length of a float type variable in bytes
                  dblLnth; //The length of a float type variable in bytes
    
    //Input Data
    
    //Calculate Output
    chrLnth = sizeof(char); //Calculate the size of a char
    intLnth = sizeof(int); //Calculate the size of an int
    fltLnth = sizeof(float); //Calculate the size of a float
    dblLnth = sizeof(double); //Calculate the size of a double
    
    //Output Results
    cout << "SIZE OF DATA TYPES:" << endl;
    cout << "CHAR LENGTH:" << setw(10) << static_cast<int>(chrLnth) 
         << " bytes or " << CNV_BIT * chrLnth << " bits" << endl;
    cout << "INT LENGTH:" << setw(11) << static_cast<int>(intLnth)
         << " bytes or " << CNV_BIT * intLnth << " bits" << endl;
    cout << "FLOAT LENGTH:" << setw(9) << static_cast<int>(fltLnth)
         << " bytes or " << CNV_BIT * fltLnth << " bits" << endl;
    cout << "DOUBLE LENGTH:" << setw(8) << static_cast<int>(dblLnth)
         << " bytes or " << CNV_BIT * dblLnth << " bits" << endl;
    
    //Exit
    return 0;
}

