/* 
 * File:   main.cpp
 * Author: Alexander Rothman,Cesar Gonzalez 
 * Purpose: Calculate whether an assignment has a passing grade or not
 * Created on January 11, 2016, 11:46 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main() {
    //Declare and Initialize variables
    unsigned char score1 = 80,
		  score2 = 60;
    
    //Input Data
    
    //Calculate and Output Results
    //If score is greater than or equal to 70 output Pass otherwise Fail
    cout << "Assignment 1: " << (score1 >= 70 ? "Pass" : "Fail") << endl;
    cout << "Assignment 2: " << (score2 >= 70 ? "Pass" : "Fail") << endl;
	
    //Exit
    return 0;
}