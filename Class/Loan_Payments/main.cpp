/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate loan payments
 * Created on January 13, 2016, 8:40 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
const unsigned char CNV_MON = 12; //Convert interest rate to per month
const unsigned char CNV_PER = 100; //Convert percent interest to decimal

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    unsigned short numPay; //The number of payments you will make
    unsigned int loanAmt; //The total amount of the loan in dollars
    float intRate, //The interest rate
          payment, //The total amount per payment in dollars
          totalInt; //The total amount of interest
    
    //Input Data
    cout << "Enter the total amount of the loan in dollars: $";
    cin >> loanAmt;
    cout << "Enter the number of loan payments you will make: ";
    cin >> numPay;
    cout << "Enter the interest rate of your loan per year as a percentage: ";
    cin >> intRate;
    
    //Calculate Output
    intRate /= CNV_PER;
    intRate /= CNV_MON;
    float temp = pow(1 + intRate, numPay);
    payment = ((intRate * temp) / 
              (temp - 1)) * loanAmt;
    totalInt = (payment * numPay) - loanAmt;
    
    //Output Results
    cout << fixed << showpoint << setprecision(2) << "Your payment will be:  $" 
         << payment << endl;
    cout << "The total interest is: $" << totalInt << endl;
    
    //Exit
    return 0;
}

