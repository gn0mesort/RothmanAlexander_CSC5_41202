/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Hotel Occupancy
 * Created on January 22, 2016, 7:44 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    unsigned short numFlrs,
                   numRms,
                   totRms;
    
    cout << "How many floors are in your hotel? ";
    cin >> numFlrs;
    
    for(int i = 0; i < numFlrs; ++i){
        cout << "How many rooms are on floor " << i + 1 << "? ";
        cin >> numRms;
        totRms += numRms;
    }
    
    cout << "NUMBER OF FLOORS: " << numFlrs << endl;
    cout << "TOTAL ROOMS:      " << totRms << endl;
    
    return 0;
}

