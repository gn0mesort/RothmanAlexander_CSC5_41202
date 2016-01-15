/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate average rainfall for a 3 month period
 * Created on January 14, 2016, 1:04 PM
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
    float month1, //The amount of rainfall in the first month  in inches
          month2, //The amount of rainfall in the second month in inches
          month3, //The amount of rainfall in the third month in inches
          average; //The average rainfall in inches
    string mtName1, //The name of the first month
           mtName2, //The name of the second month
           mtName3; //The name of the third month
    
    //Input Data
    //Read in the first month's data
    cout << "Enter the first month's name: ";
    cin >> mtName1;
    cout << "How much rain fell in " << mtName1 << " in inches? ";
    cin >> month1;
    //Read in the second month's data
    cout << "Enter the second month's name: ";
    cin >> mtName2;
    cout << "How much rain fell in " << mtName2 << " in inches? ";
    cin >> month2;
    //Read in the third month's data
    cout << "Enter the third month's name: ";
    cin >> mtName3;
    cout << "How much rain fell in " << mtName3 << " in inches? ";
    cin >> month3;
    
    //Calculate Output
    average = (month1 + month2 + month3) / 3;
    
    //Output Results
    cout << "RAINFALL FOR " << mtName1 << ": " << month1 << " inches" << endl;
    cout << "RAINFALL FOR " << mtName2 << ": " << month2 << " inches" << endl;
    cout << "RAINFALL FOR " << mtName3 << ": " << month3 << " inches" << endl;
    cout << "AVERAGE RAINFUL: " << average << " inches" << endl;
    
    //Exit
    return 0;
}

