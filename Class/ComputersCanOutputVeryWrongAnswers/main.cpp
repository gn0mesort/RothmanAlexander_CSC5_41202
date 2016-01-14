/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Illustrate how a computer can a return an inaccurate result
 * Created on January 14, 2016, 11:03 AM
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
    float qty = 0.75f, //A quantity to add repeatedly
          sum = 0, //The result of a repetitive addition
          answer; //The computed answer
    int nLoops = 10000000; //Number of times to loop
    
    //Calculate Output
    //Calculate as a sum
    for(int i = 0; i < nLoops; i++){
        sum += qty;
    }
    
    //Calculate as a product
    answer = nLoops * qty;
    
    //Output Results
    cout << "QUANTITY:       " << qty << endl;
    cout << "SUM ANSWER:     " << sum << endl;
    cout << "PRODUCT ANSWER: " << answer << endl;
    cout << "PERCENT ERROR:  " << (answer - sum) / answer * 100 << "%" << endl;
    
    //Exit
    return 0;
}

