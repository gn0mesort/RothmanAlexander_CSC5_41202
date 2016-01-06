
/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate the sum and product of two integers
 * Created on January 5, 2016, 4:31 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    int oprndA = 0, //The first operand 
        oprndB = 0, //The second operand
        sum, //The sum of the first and second operands
        product; //The product of the first and second operands
    
    //Input Data
    cout << "Enter two numbers to calculate their sum and product." << endl;
    cout << "Press return after entering a number." << endl;
    //Read in first operand
    cout << "Enter the first number:  ";
    cin >> oprndA;
    //Read in second operand
    cout << "Enter the second number: ";
    cin >> oprndB;
    
    //Calculate Output 
    sum = oprndA + oprndB; //Calculate the sum
    product = oprndA * oprndB; //Calculate the product
    
    //Output Results
    cout << "First Number:  " << oprndA << endl;
    cout << "Second Number: " << oprndB << endl;
    cout << "Sum:           " << sum << endl;
    cout << "Product:       " << product << endl;
    
    //Exit
    return 0;
}

