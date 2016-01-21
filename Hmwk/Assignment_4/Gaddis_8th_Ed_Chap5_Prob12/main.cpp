/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Celsius to Fahrenheit Table
 * Created on January 20, 2016, 10:16 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    char intrcpt = 32; //Scaled by 9/5 degrees Celsius
    unsigned char c1 = 0, //The freezing point of water in Celsius
                  c2 = 100, //The boiling point of water in Celsius
                  f1 = 32, //The freezing point of water in Fahrenheit
                  f2 = 212; //The boiling point of water in Fahrenheit
    float slope = 5.0f/9.0f; //The slope of the line for temperature conversion
    
    cout << "Solution to Gaddis 8th Ed. Chap5 Prob12" << endl;
    cout << "Celsius to Fahrenheit Conversion Table" << endl;
    
    //Loop to generate the degree Celsius and output table
    cout << "Fahrenheit   Celsius   Celsius" << endl; //Print table header
    cout << fixed << setprecision(2) << showpoint;
    for(int f = f1; f <= f2; ++f){
        float ceq = slope * (f - intrcpt); //The conversion as a slope
        float cintrp = c1 + static_cast<float>((f - f1)) / (f2 - f1) * (c2 - c1); //The conversion using interpolation
        cout << setw(10) << f << setw(10) << ceq << setw(10) << cintrp << endl; //Output values
    }
    
    //Exit
    return 0;
}

