/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on January 14, 2016, 5:27 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    const unsigned char ASEATS = 15,
                        BSEATS = 12,
                        CSEATS = 9;
    unsigned short numASts,
                   numBSts,
                   numCSts;
    float total;
    
    cout << "Enter the number of each type of tickets that were purchased." 
         << endl;
    cout << "Number of CLASS A tickets sold: ";
    cin >> numASts;
    cout << "Number of CLASS B tickets sold: ";
    cin >> numBSts;
    cout << "Number of CLASS C tickets sold: ";
    cin >> numCSts;
    
    total = (numASts * ASEATS) + (numBSts * BSEATS) + (numCSts * CSEATS);
    
    cout << "The total number of tickets sold is: " 
         << (numASts + numBSts + numCSts) << " tickets" << endl;
    cout << fixed << setprecision(2) << showpoint << "The total income is: $"
         << total;
    
    return 0;
}

