/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Power Function Example
 * Created on January 25, 2016, 8:36 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int pow(int, int);

//Begin Execution
int main(int argc, char** argv) {
    //Timing variables
    int begin, //Begin time
        end, //End time
        loop = 200000000; //Number of times to preform each process
    //Declaration and Initialization
    int x, //Base of the problem
        y, //Exponent of the problem
        z; //Result
    
    //Input Data
    cout << "INPUT A: ";
    cin >> x;
    cout << "INPUT B: ";
    cin >> y;
    
    //Calculate a ^ b using new function
    begin = static_cast<unsigned int>(time(0)); //Get beginning time
    for(int i = 0; i < loop; ++i){
        z = pow(x, y); //Calculate
    }
    end = static_cast<unsigned int>(time(0)); //Get ending time
    
    //Output Results
    cout << "ITERATIONS: " << loop << endl;
    cout << "RESULT: " << z << endl; 
    cout << x << " ^ " << y << " = " << z << endl;
    cout << "TOTAL TIME: " << end - begin << " seconds" << endl;
    
    //Compare to CMATH pow()
    double xd = x, //copy X into a double
           yd = y, //copy Y into a double
           zd; //The result as a double
    
    //Calculate a ^ b using CMATH pow()
    begin = static_cast<unsigned int>(time(0)); //Get beginning time
    for(int i = 0; i < loop; ++i){
        zd = pow(xd, yd); //Calculate
    }
    end = static_cast<unsigned int>(time(0)); //Get ending time
    
    //Output Results
    cout << "RESULT: " << zd << endl; 
    cout << xd << " ^ " << yd << " = " << zd << endl;
    cout << "TOTAL TIME: " << end - begin << " seconds" << endl;
    cout << "Same as z = exp(y * loge(x)) --> " << exp(yd * log(xd)) << endl;
    
    //Exit
    return 0;
}
//000000001111111111222222222233333333334444444444555555555666666666677777777777
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                            Power Function
//Inputs
//  a -> Integer Base
//  b -> Integer Power-Exponent
//Returns
// c -> Integer z = a ^ b
int pow(int a, int b){
    if(b <= 0) { return 1; } //If raised to the power of 0
    if(b == 1) {return a; } //If raised to the power of 1
    int abd2 = pow(a, b/2);
    if(b % 2 == 0) { return abd2 * abd2; } //If Even
    else { return abd2 * abd2 * a; } //Else odd
    
}

