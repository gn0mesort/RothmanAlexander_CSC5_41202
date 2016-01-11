/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: 
 * Version: 1.0
 * Created on January 11, 2016, 7:39 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    short strTemp,
          endTemp,
          temp,
          chgTemp = 1;
    float veloSS;
    
    cout << "Input the starting temperature: ";
    cin >> strTemp;
    cout << "Input the ending temperature: ";
    cin >> endTemp;
    
    temp = strTemp; 
    
    if(endTemp > strTemp){
        for(short temp = strTemp; temp <= endTemp; temp += chgTemp){
            veloSS = 331.3f + 0.61f * temp;
            cout << fixed << setprecision(2) << showpoint << "At " << temp 
                 << " degrees Celsius the velocity of sound is " << veloSS 
                 << " m/s" << endl;
        }
    }
    else {
        for(short temp = strTemp; temp >= endTemp; temp -= chgTemp){
            veloSS = 331.3f + 0.61f * temp;
            cout << fixed << setw(6) << setprecision(2) << showpoint << "At " 
                 << temp << " degrees Celsius the velocity of sound is " 
                 << veloSS << " m/s" << endl;
        }
    }
    
    
    return 0;
}

