/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate income from ticket sales on stadium seating
 * Created on January 14, 2016, 5:27 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const unsigned char ASEATS = 15, //Cost of a Class A seat
                        BSEATS = 12, //Cost of a Class B seat
                        CSEATS = 9; //Cost of a Class C seat
    unsigned short numASts, //Number of Class A tickets sold
                   numBSts, //Number of Class B tickets sold
                   numCSts; //Number of Class C tickets sold
    float total; //The total income
    
    //Input Data
    cout << "Enter the number of each type of tickets that were purchased." 
         << endl;
    //Read in the number of Class A tickets
    cout << "Number of CLASS A tickets sold: ";
    cin >> numASts;
    //Read in the number of Class B tickets
    cout << "Number of CLASS B tickets sold: ";
    cin >> numBSts;
    //Read in the number of Class C tickets
    cout << "Number of CLASS C tickets sold: ";
    cin >> numCSts;
    
    //Calculate Output
    total = (numASts * ASEATS) + (numBSts * BSEATS) + (numCSts * CSEATS);
    
    //Output Results
    cout << "The total number of tickets sold is: " 
         << (numASts + numBSts + numCSts) << " tickets" << endl;
    cout << fixed << setprecision(2) << showpoint << "The total income is: $"
         << total;
    
    //Exit
    return 0;
}

