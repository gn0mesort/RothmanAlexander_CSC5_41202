/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Variations on a savings theme
 * Created on January 26, 2016, 8:44 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants
const char PERCENT = 100; //Convert decimal to percentage and back

//Function Prototypes
float save1(float, float, int); //Power Function
float save2(float, float, int); //Exponent and Log Functions
float save3(float, float, int); //For loop
float save4(float, float, int); //Banking for loop
float save5(float, float, int); //Recursion
float save6(float, int, float = 0.05f); //Defaulted
float save7(float, float, int); //Static Variable

int main(int argc, char** argv) {
    //Declaration and Initialization
    float pv, //The present value
          intRate; //The interest rate
    char nComp; //The number of compounding periods
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    pv = rand() % 9001 + 1000; //A random number from 1000 to 10000
    intRate = rand() % 11 + 5; //A random value from 5 to 15
    nComp = rand() % 16; //A random value from 0 to 15 
    
    //Output Random Inputs
    cout << fixed << setprecision(2) << showpoint;
    cout << "CURRENT VALUE: $" << pv << endl;
    cout << "INTEREST RATE:  " << intRate << "%" << endl;
    cout << "YEARS:          " <<  static_cast<int>(nComp) << " years" << endl;
    
    //Output Results
    //Power Function
    cout << "SAVINGS USING POWER FUNCTION:                              $" 
         << save1(pv, intRate / PERCENT, nComp) << endl;
    //Exponent and Log Function
    cout << "SAVINGS USING EXPONENTIAL AND LOG FUNCTION:                $" 
         << save2(pv, intRate / PERCENT, nComp) << endl;
    //For Loop
    cout << "SAVINGS USING FOR LOOP FUNCTION:                           $" 
         << save3(pv, intRate / PERCENT, nComp) << endl;
    //Banking For Loop
    cout << "SAVINGS USING FOR LOOP FUNCTION BANKING VERSION:           $" 
         << save4(pv, intRate / PERCENT, nComp) << endl;
    //Recursion
    cout << "SAVINGS USING RECURSION:                                   $" 
         << save5(pv, intRate / PERCENT, nComp) << endl;
    //Defaulting Interest
    cout << "SAVINGS USING DEFAULTING INTEREST OF 5%:                   $" 
         << save6(pv, nComp) << endl;
    //Static Variable
    save7(pv, intRate / PERCENT, nComp);
    cout << "SAVINGS USING FOR LOOP STATIC VARIABLE:                    $" 
         << save7(pv, intRate / PERCENT, nComp) << endl;
    
    
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/
/***********************************SAVE1**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: Power function version
float save1(float pv, float i, int n){
    return pv * pow((1 + i), n);
}

/******************************************************************************/
/***********************************SAVE2**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: Exponential and log function version
float save2(float pv, float i, int n){
    return pv * exp(n * log(1 + i));
}

/******************************************************************************/
/***********************************SAVE3**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: For loop version
float save3(float pv, float i, int n){
    for(int years = 1; years <= n; ++years){
        pv *= (1 + i);
    }
    
    return pv;
}

/******************************************************************************/
/***********************************SAVE4**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: For loop banking version
float save4(float pv, float i, int n){
    int ip = pv * PERCENT; //Convert to pennies
    for(int years = 1; years <= n; ++years){
        ip *= (1 + i);
    }
    
    return static_cast<float>(ip) / PERCENT; //Convert back to dollars and return
}

/******************************************************************************/
/***********************************SAVE5**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: Recursive Function
float save5(float pv, float i, int n){
    if(n <= 0){ return pv; }
    return save5(pv, i, n - 1) * (1 + i);
}

/******************************************************************************/
/***********************************SAVE6**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: Recursive Function
float save6(float pv, int n, float i){
    return pv * pow((1 + i), n);
}

/******************************************************************************/
/***********************************SAVE7**************************************/
/******************************************************************************/
//Inputs
// pv -> Present value in $'s
// i -> Interest rate in %
// n -> Number of compounding periods
//Output
// fv -> Future value in $'s
//Note: For loop version with a static variable
float save7(float pv, float i, int n){
    static int nCalls = 0;
    for(int years = 1; years <= n; ++years){
        pv *= (1 + i);
    }
    ++nCalls;
    cout << "SAVE 7 STATIC COUNTER: " << nCalls << endl;
    return pv;
}