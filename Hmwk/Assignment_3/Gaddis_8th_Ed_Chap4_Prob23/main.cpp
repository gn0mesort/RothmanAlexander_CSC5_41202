/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Geometry Area Calculator
 * Created on January 20, 2016, 8:51 PM
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const float PI = atan(1) * 4;

int main(int argc, char** argv) {
    unsigned short choice;
    float cArea,
          tArea,
          rArea,
          radius,
          base,
          height;
    
    do {
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        do {
            cout << "Enter your choice (1-4): ";
            cin >> choice;
        } while (choice < 0 && choice > 4);
        cout << fixed << setprecision(4) << showpoint;
        switch(choice){
            case 1:
            {
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "AREA: " << PI * (radius * radius) << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the width of the rectangle: ";
                cin >> base;
                cout << "Enter the length of the rectangle: ";
                cin >> height;
                cout << "AREA: " << base * height << endl;
                break;
            }  
            case 3:
            {
                cout << "Enter the base of the triangle: ";
                cin >> base;
                cout << "Enter the height of the triangle: ";
                cin >> height;
                cout << "AREA: " << base * height * 0.5f << endl;
                break;
            }
            default: { }
        }
    } while (choice != 4);
    
    return 0;
}

