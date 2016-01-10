/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate approximate numbers of customers with certain energy drink consumption habits
 * Created on January 6, 2016, 9:33 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
unsigned const char CNV_PER = 100; //Conversion to percentage

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short cstSurv = 16500, //The number of customers surveyed
                   aprxCst, //The approximate number of people who bought a drink
                   aprxCit; //The approximate number of people who bought a drink and preferred citrus
    char percPur = 15, //The percentage of the surveyed customers that purchased a drink
         prefCit = 58; //The percentage of the customers who bought a drink and preferred citrus
    
    //Input Data
    
    //Calculate Output
    aprxCst = cstSurv * percPur / CNV_PER; //Calculate the approximate number of people who bought a drink
    aprxCit = aprxCst * prefCit / CNV_PER; //Calculate the approximate number of people who bought a drink and preferred citrus
    
    //Output Results
    cout << "Customers Surveyed:                                               ";
    cout << cstSurv << " people" << endl;
    cout << "Percentage that purchased at least 1 drink:                       "; 
    cout << static_cast<int>(percPur)  << "%" << endl;
    cout << "Percentage that preferred the citrus flavor:                      "; 
    cout << static_cast<int>(prefCit) << "%" << endl;
    cout << "Approximate number of customers that purchased 1 drink:           "; 
    cout << aprxCst << " people" << endl;
    cout << "Approximate number of customers that preferred the citrus flavor: "; 
    cout << aprxCit << " people" << endl;
    
    //Exit
    return 0;
}

