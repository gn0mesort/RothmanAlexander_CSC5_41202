/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Check if a number is prime
 * Created on February 3, 2016, 8:42 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool isPrime(int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    int num; //The number to check the primacy of
    
    //Input Data
    cout << "Enter a number to test whether or not it is prime: ";
    cin >> num;
   
    //for(int num = 2; num <= 1000; ++num) //Uncomment to test some set numbers
    //Output Results
    cout << num << " IS " << (isPrime(num) ? "PRIME" : "NOT PRIME") << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/********************************Is Prime**************************************/
/******************************************************************************/
//  Determine whether or not an integer is a prime number
//Input
//  chkNum : the number to check the primacy of
//Output
// true if the number cannot be divided evenly by anything other than one or itself
// false if the number can be divided evenly by something other than one or itself
bool isPrime(int chkNum){
    for(int i = 2; i < chkNum; ++i){ //loop through all numbers between 1 or chkNum exclusively
        if(chkNum % i == 0) { return false; } //if divisible return false
    }
    
    //Otherwise return true
    return true;
}
