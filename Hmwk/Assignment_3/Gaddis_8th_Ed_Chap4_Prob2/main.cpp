/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Roman Numeral Converter
 * Created on January 19, 2016, 7:25 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initializatin
    unsigned short inNum; //The input number 1-10
    string roman; //The number as a roman numeral
    
    //Problem Information
    cout << "Gaddis 8th Ed Chap4 Prob2" << endl;
    cout << "Roman Numeral Converter" << endl;
    
    //Input Data
    do{ //Input Validation
    cout << "Enter a number between 1 and 10: ";
    cin >> inNum;
    } while(inNum > 10 || inNum < 1);
    
    //Calculate Output
    switch(inNum){ //Convert inNum to a roman numeral
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
    
    //Output Results
    cout << "The roman numeral for " << inNum << " is " << roman << endl;
    
    //Exit
    return 0;
}

