/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Arabic to Roman numeral converter
 * Created on January 21, 2016, 8:20 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned char n1000s, //Number of 1000s
                  n100s, //Number of 100s
                  n10s, //Number of 10s
                  n1s; //Number of 1s
    unsigned short cNum, //Number to Convert
                   temp; //Hold he value of the first part of each calculation

    srand(static_cast<int> (time(0))); //Seed PRNG
    cNum = rand() % 2001 + 1000; //Get a new number to convert

    cout << "Solution to Savitch 9th Ed. Chap3 Prob3" << endl;
    cout << "The Roman Number Conversion Program" << endl;

    //Calculate Output
    //Output original number
    cout << "THE NUMBER TO CONVERT: " << cNum << endl;
    //Calculate the number in each place
    //Calculate 1000s
    temp = cNum - cNum % 1000;
    n1000s = temp / 1000;
    cNum -= temp;
    //Calculate 100s
    temp = cNum - cNum % 100;
    n100s = temp / 100;
    cNum -= temp;
    //Calculate 100s
    temp = cNum - cNum % 10;
    n10s = temp / 10;
    cNum -= temp;
    //Calculate 1s
    n1s = cNum;

    //Output Results
    //Output the number in each place of our original number
    cout << "NUMBER OF 1000S: " << static_cast<int> (n1000s) << endl;
    cout << "NUMBER OF 100S:  " << static_cast<int> (n100s) << endl;
    cout << "NUMBER OF 10S:   " << static_cast<int> (n10s) << endl;
    cout << "NUMBER OF 1S:    " << static_cast<int> (n1s) << endl;
    cout << "THE ROMAN NUMERAL EQUIVALENT: ";
    switch (n1000s) { //Output 1000s
        case 3:
        {
            cout << 'M';
        }
        case 2:
        {
            cout << 'M';
        }
        case 1:
        {
            cout << 'M';
        }
    }
    switch (n100s) { //Output 100s
        case 9:
        {
            cout << "CM";
            break;
        }
        case 8:
        {
            cout << "DCCC";
            break;
        }
        case 7:
        {
            cout << "DCC";
            break;
        }
        case 6:
        {
            cout << "DC";
            break;
        }
        case 5:
        {
            cout << 'D';
            break;
        }
        case 4:
        {
            cout << "CD";
            break;
        }
        case 3:
        {
            cout << 'C';
        }
        case 2:
        {
            cout << 'C';
        }
        case 1:
        {
            cout << 'C';
        }
    }
    switch (n10s) { //Output 10s
        case 9:
        {
            cout << "XC";
            break;
        }
        case 8:
        {
            cout << "LXXX";
            break;
        }
        case 7:
        {
            cout << "LXX";
            break;
        }
        case 6:
        {
            cout << "LX";
            break;
        }
        case 5:
        {
            cout << 'L';
            break;
        }
        case 4:
        {
            cout << "XL";
            break;
        }
        case 3:
        {
            cout << 'X';
        }
        case 2:
        {
            cout << 'X';
        }
        case 1:
        {
            cout << 'X';
        }
    }
    switch (n1s) { //Output 1s
        case 9:
        {
            cout << "IX";
            break;
        }
        case 8:
        {
            cout << "VIII";
            break;
        }
        case 7:
        {
            cout << "VII";
            break;
        }
        case 6:
        {
            cout << "VI";
            break;
        }
        case 5:
        {
            cout << 'V';
            break;
        }
        case 4:
        {
            cout << "IV";
            break;
        }
        case 3:
        {
            cout << 'I';
        }
        case 2:
        {
            cout << 'I';
        }
        case 1:
        {
            cout << 'I';
        }
    }
    cout << endl; //End line

    //Exit
    return 0;
}

