/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate Retail prices based on wholesale prices
 * Created on February 3, 2016, 7:39 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float calcRtl(unsigned short, unsigned short);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short input; //The input number
    unsigned short whsCost, //The wholesale cost of the product
            mkUpPer; //The retail markup

    //Input Data
    do { //Input validation
        cout << "Enter the wholesale value of the item: $";
        cin >> input;
    } while (input < 0);
    whsCost = input; //Set wholesale cost
    do { //Input validation
        cout << "Enter the retail markup percentage:     ";
        cin >> input;
    } while (input < 0);
    mkUpPer = input; //Set mark up percentage
    
    //Calculate and Output Results
    cout << fixed << setprecision(2) << showpoint;
    cout << "The retail value is $" << calcRtl(whsCost, mkUpPer);

    //Exit
    return 0;
}


/******************************************************************************/
/******************************Calculate Retail********************************/
/******************************************************************************/
//  Calculate the retail price of a product
//Input
//  whsCost : the wholesale cost of the product
//  mkUpPer : the mark up percentage
//Output
//  the price of the product after applying retail markup 
float calcRtl(unsigned short whsCost, unsigned short mkUpPer) {
    return whsCost * (1.0f + static_cast<float> (mkUpPer) / 100);
}

