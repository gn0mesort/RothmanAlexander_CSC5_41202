/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate and compare the area of rectangles
 * Created on January 19, 2016, 7:38 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short r1Wdth, //The width of the first rectangle
                   r2Wdth, //The width of the second rectangle
                   r1Lngth, //The length of the first rectangle
                   r2Lngth; //The length of the second rectangle
    unsigned int r1Area, //The area of the first rectangle
                 r2Area; //The area of the second rectangle
    
    //Problem Information
    cout << "Gaddis 8th Ed. Chap4 Prob4" << endl;
    cout << "Calculate and compare the area of two rectangles" << endl;
    
    //Input Data
    //Read in the width of the first rectangle
    cout << "Input the width of the first rectangle: ";
    cin >> r1Wdth;
    //Read in the length of the first rectangle
    cout << "Input the length of the first rectangle: ";
    cin >> r1Lngth;
    //Read in the width of the second rectangle
    cout << "Input the width of the second rectangle: ";
    cin >> r2Wdth;
    //Read in the length of second rectangle
    cout << "Input the length of the second rectangle: ";
    cin >> r2Lngth;
    
    //Calculate Output
    //Calculate the area of the first rectangle
    r1Area = r1Wdth * r1Lngth;
    //Calculate the area of the second rectangle
    r2Area = r2Wdth * r2Lngth;
    
    //Output Results
    cout << "The area of rectangle 1 is: " << r1Area << endl;
    cout << "The area of rectangle 2 is: " << r2Area << endl;
    //Output which rectangle has the largest area
    cout << "The area of rectangle 1 is " 
         << ((r1Area > r2Area) ? "greater than " : (r1Area < r2Area) 
         ? "less than " : "equal to ") << "the area of rectangle 2." << endl;
    
    //Exit
    return 0;
}

