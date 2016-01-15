/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate the speed of sound at sea level at different temperatures
 * Created on January 11, 2016, 7:39 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Variables

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    short strTemp, //The starting temperature in degrees Celsius
          endTemp, //The ending temperature in degrees Celsius
          chgTemp = 1; //The change in temperature per step in degrees Celsius
    float veloSS; //The velocity of the speed of sound at the current temperature in meters / second
    
    //Input Data
    //Read in starting temperature
    cout << "Input the starting temperature: ";
    cin >> strTemp;
    //Read in ending temperature
    cout << "Input the ending temperature: ";
    cin >> endTemp;
     
    //Calculate and Output results
    if(endTemp > strTemp){ //If the ending temperature is higher than the starting temperature
        for(int temp = strTemp; temp <= endTemp; temp += chgTemp){
            veloSS = 331.3f + 0.61f * temp; //Calculate velocity at the current temperature
            cout << fixed << setprecision(2) << showpoint << "At " << temp //Output results 
                 << " degrees Celsius the velocity of sound is " << veloSS 
                 << " m/s" << endl;
        }
    }
    else { //If the ending temperature is lower than the starting temperature
        for(int temp = strTemp; temp >= endTemp; temp -= chgTemp){
            veloSS = 331.3f + 0.61f * temp; //Calculate velocity at the current temperature
            cout << fixed << setw(6) << setprecision(2) << showpoint << "At " //Output results
                 << temp << " degrees Celsius the velocity of sound is " 
                 << veloSS << " m/s" << endl;
        }
    }
    
    //Exit
    return 0;
}

