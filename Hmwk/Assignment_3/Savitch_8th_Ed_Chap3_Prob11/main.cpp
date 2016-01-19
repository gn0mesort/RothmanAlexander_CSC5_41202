/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Factorial
 * Created on January 19, 2016, 10:36 AM
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
    unsigned short n; //The number to compute the factorial of
    unsigned int factN = 1; //The factorial of n
    
    cout << "NUMBERS MUST BE BETWEEN 1 AND 13" << endl;
    cout << "Enter the number to calculate the factorial of: ";
    cin >> n;
    
    for(int i = 1; i <= n; ++i){
        factN *= i;
    }
   
    cout << n << "! = " <<  factN << endl;
    
    //Exit
    return 0;
}

