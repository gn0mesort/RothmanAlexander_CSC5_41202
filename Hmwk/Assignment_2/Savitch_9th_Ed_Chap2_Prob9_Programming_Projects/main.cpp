/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate positive and negative sums of 10 numbers
 * Created on January 13, 2016, 1:16 PM
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
    short num1, //First number
          num2, //Second number
          num3, //Third number
          num4, //Fourth number
          num5, //Fifth number
          num6, //Sixth number
          num7, //Seventh number
          num8, //Eighth number
          num9, //Nineth number
          num10; //Tenth number
    int posSum = 0, //The sum of the positive numbers
        negSum = 0; //The sum of the negative numbers
    
    //Input Data
    cout << "Enter 10 numbers between -32767 and 32767" << endl;
    //Read in first number
    cout << "NUMBER 1: ";
    cin >> num1;
    //Read in second number
    cout << "NUMBER 2: ";
    cin >> num2;
    //Read in third number
    cout << "NUMBER 3: ";
    cin >> num3;
    //Read in fourth number
    cout << "NUMBER 4: ";
    cin >> num4;
    //Read in fifth number
    cout << "NUMBER 5: ";
    cin >> num5;
    //Read in sixth number
    cout << "NUMBER 6: ";
    cin >> num6;
    //Read in seventh number
    cout << "NUMBER 7: ";
    cin >> num7;
    //Read in eighth number
    cout << "NUMBER 8: ";
    cin >> num8;
    //Read in nineth number
    cout << "NUMBER 9: ";
    cin >> num9;
    //Read in tenth number
    cout << "NUMBER 10: ";
    cin >> num10;
    
    //Calculate Output
    //Check if each number is positive or negative and then add it to the correct sum
    if(num1 > 0){
        posSum += num1;
    }
    else{
        negSum += num1;
    }
    if(num2 > 0){
        posSum += num2;
    }
    else{
        negSum += num2;
    }
    if(num3 > 0){
        posSum += num3;
    }
    else{
        negSum += num3;
    }
    if(num4 > 0){
        posSum += num4;
    }
    else{
        negSum += num4;
    }
    if(num5 > 0){
        posSum += num5;
    }
    else{
        negSum += num5;
    }
    if(num6 > 0){
        posSum += num6;
    }
    else{
        negSum += num6;
    }
    if(num7 > 0){
        posSum += num7;
    }
    else{
        negSum += num7;
    }
    if(num8 > 0){
        posSum += num8;
    }
    else{
        negSum += num8;
    }
    if(num9 > 0){
        posSum += num9;
    }
    else{
        negSum += num9;
    }
    if(num10 > 0){
        posSum += num10;
    }
    else{
        negSum += num10;
    }
    
    //Output Results
    cout << "NUMBERS: " << num1 << ',' << num2 << ',' << num3 << ',' << num4
         << ',' << num5 << ',' << num6 << ',' << num7 << ',' << num8
         << ',' << num9 << ',' << num10 << endl;
    cout << "POSITIVE SUM: " << posSum << endl;
    cout << "NEGATIVE SUM: " << negSum << endl;
    
    //Exit
    return 0;
}

