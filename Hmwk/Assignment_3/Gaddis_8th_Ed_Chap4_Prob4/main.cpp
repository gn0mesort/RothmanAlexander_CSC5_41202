/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate and compare the area of rectangles
 * Created on January 19, 2016, 7:38 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    unsigned short r1Wdth,
                   r2Wdth,
                   r1Lngth,
                   r2Lngth;
    unsigned int r1Area,
                 r2Area;
    
    cout << "Input the width of the first rectangle: ";
    cin >> r1Wdth;
    cout << "Input the length of the first rectangle: ";
    cin >> r1Lngth;
    cout << "Input the width of the second rectangle: ";
    cin >> r2Wdth;
    cout << "Input the length of the second rectangle: ";
    cin >> r2Lngth;
    
    r1Area = r1Wdth * r1Lngth;
    r2Area = r2Wdth * r2Lngth;
    
    cout << "The area of rectangle 1 is: " << r1Area << endl;
    cout << "The area of rectangle 2 is: " << r2Area << endl;
    cout << "The area of rectangle 1 is " 
         << ((r1Area > r2Area) ? "greater than " : (r1Area < r2Area) 
         ? "less than " : "equal to ") << "the area of rectangle 2." << endl;
    
    return 0;
}

