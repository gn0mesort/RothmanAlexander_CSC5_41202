/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate Average Rainfall
 * Created on January 22, 2016, 7:51 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
     short years;
     unsigned short cRnFl,
                    tRnFl,
                    aRnFl;
    
    do{
    cout << "NUMBER OF YEARS IN DATA SET: ";
    cin >> years;
    } while(years <= 0);
    
    for(int i = 0; i < years; ++i){
        for(int j = 0; j < 12; ++j){
            cout << "RAINFALL FOR MONTH " << j + 1 << " OF YEAR " << i + 1 
                 << ": ";
            cin >> cRnFl;
            tRnFl += cRnFl;
        }
    }
    
    aRnFl = tRnFl / (12 * years);
    
    cout << "TOTAL YEARS:      " << years << endl;
    cout << "TOTAL RAINFALL:   " << tRnFl << endl;
    cout << "AVERAGE RAINFALL: " << aRnFl << endl;
    
    return 0;
}

