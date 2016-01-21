/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Geometry Area Calculator
 * Created on January 20, 2016, 8:51 PM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//User Libraries


//Global Constants
const float PI = atan(1) * 4;

//Function Protoypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short choice; //The choice of mode for the calculator
    float radius, //The radius of a cirle
          base, //The base of a triange or width of a rectangle
          height; //The height of a triangle or length of a rectangle
    
    //Problem Information
    cout << "Gaddis 8th Ed. Chap4 Prob23" << endl;
    cout << "Calculator for the Area of Shapes" << endl;

    do { //Loop if the user doesn't want to quit
        //Input a mode choice
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        do { //Input Validation
            cout << "Enter your choice (1-4): ";
            cin >> choice;
        } while (choice < 0 && choice > 4);
        cout << fixed << setprecision(4) << showpoint;
        //Switch between modes
        switch(choice){
            case 1: //Circle Mode
            {
                //Input Radius
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                //Calculate and Output Results
                cout << "AREA: " << PI * (radius * radius) << endl;
                break;
            }
            case 2: //Rectangle Mode
            {   
                //Input width
                cout << "Enter the width of the rectangle: ";
                cin >> base;
                //Input length
                cout << "Enter the length of the rectangle: ";
                cin >> height;
                //Calculate and Output Results
                cout << "AREA: " << base * height << endl;
                break;
            }  
            case 3: //Triangle Mode
            {
                //Input base
                cout << "Enter the base of the triangle: ";
                cin >> base;
                //Input height
                cout << "Enter the height of the triangle: ";
                cin >> height;
                //Calculate and Output Results
                cout << "AREA: " << base * height * 0.5f << endl;
                break;
            }
        }
    } while (choice != 4);
    
    //Exit
    return 0;
}

