/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate Retail prices based on wholesale prices
 * Created on February 3, 2016, 7:39 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

float calcRtl(unsigned short, unsigned short);

int main(int argc, char** argv) {
    short input;
    unsigned short whsCost,
            mkUpPer;

    do {
        cout << "Enter the wholesale value of the item: $";
        cin >> input;
    } while (input < 0);
    whsCost = input;
    do {
        cout << "Enter the retail markup percentage:     ";
        cin >> input;
    } while (input < 0);
    mkUpPer = input;
    cout << fixed << setprecision(2) << showpoint;
    cout << "The retail value is $" << calcRtl(whsCost, mkUpPer);

    return 0;
}

float calcRtl(unsigned short whsCost, unsigned short mkUpPer) {
    return whsCost * (1.0f + static_cast<float> (mkUpPer) / 100);
}

