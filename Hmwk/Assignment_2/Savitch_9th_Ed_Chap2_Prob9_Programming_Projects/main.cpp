/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on January 13, 2016, 1:16 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    short num1,
          num2,
          num3,
          num4,
          num5,
          num6,
          num7,
          num8,
          num9,
          num10;
    int posSum = 0,
        negSum = 0;
    
    cout << "Enter 10 numbers between -32767 and 32767" << endl;
    cout << "NUMBER 1: ";
    cin >> num1;
    cout << "NUMBER 2: ";
    cin >> num2;
    cout << "NUMBER 3: ";
    cin >> num3;
    cout << "NUMBER 4: ";
    cin >> num4;
    cout << "NUMBER 5: ";
    cin >> num5;
    cout << "NUMBER 6: ";
    cin >> num6;
    cout << "NUMBER 7: ";
    cin >> num7;
    cout << "NUMBER 8: ";
    cin >> num8;
    cout << "NUMBER 9: ";
    cin >> num9;
    cout << "NUMBER 10: ";
    cin >> num10;
    
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
    
    cout << "NUMBERS: " << num1 << ',' << num2 << ',' << num3 << ',' << num4
         << ',' << num5 << ',' << num6 << ',' << num7 << ',' << num8
         << ',' << num9 << ',' << num10 << endl;
    cout << "POSITIVE SUM: " << posSum << endl;
    cout << "NEGATIVE SUM: " << negSum << endl;
    
    return 0;
}

