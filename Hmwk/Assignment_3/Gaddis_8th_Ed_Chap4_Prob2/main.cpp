/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Roman Numeral Converter
 * Created on January 19, 2016, 7:25 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    unsigned short inNum;
    string roman;
    
    do{
    cout << "Enter a number between 1 and 10: ";
    cin >> inNum;
    } while(inNum > 10 || inNum < 1);
    
    switch(inNum){
        case 1:
        {
            roman = "I";
            break;
        }
        case 2:
        {
            roman = "II";
            break;
        }
        case 3:
        {
            roman = "III";
            break;
        }
        case 4:
        {
            roman = "IV";
            break;
        }
        case 5:
        {
            roman = "V";
            break;
        }
        case 6:
        {
            roman = "VI";
            break;
        }
        case 7:
        {
            roman = "VII";
            break;
        }
        case 8:
        {
            roman = "VIII";
            break;
        }
        case 9:
        {
            roman = "IX";
            break;
        }
        case 10:
        {
            roman = "X";
            break;
        }
        default:
        {
            roman = "INVALID INPUT";
        }
    }
    
    cout << "The roman numeral for " << inNum << " is " << roman << endl;
    
    return 0;
}

