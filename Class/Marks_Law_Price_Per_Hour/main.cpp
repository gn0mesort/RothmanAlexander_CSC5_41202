/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 12, 2016, 11:38 AM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    unsigned short hours,
                   cost,
                   price;
    
    cout << "Enter the price per hour: $";
    cin >> cost;
    cout << "Enter the time the job took: ";
    cin >> hours;
    
    //Ternary
    price = hours < 5 ? 5 * cost : 
            hours <= 8 ? hours * cost : 
            hours > 8 ? ((hours - 8) * cost * 1.5f) + ((hours - (hours - 8)) * cost): 0;
    
    cout << "Total Price Ternary: $" << price << endl;
    
    //Dependent If
    if(hours < 5) price = 5 * cost;
    else if (hours <= 8) price = hours * cost;
    else if (hours > 8) price = ((hours - 8) * cost * 1.5f) + ((hours - (hours - 8)) * cost);
            
    
    cout << "Total Price Dependent If: $" << price << endl;
    
    return 0;
}

