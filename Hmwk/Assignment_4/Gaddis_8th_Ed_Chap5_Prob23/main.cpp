/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Pattern Printing
 * Created on January 24, 2016, 3:15 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    cout << setw(10) << "Pattern A" << "  " << setw(10) << "Pattern B" << endl;
    
    for(int i = 1, j = 10; i <= 10; ++i, --j){
        string fwd(i, '*'),
               rvs(j, '*');
        cout << setw(10) << fwd << "  " << setw(10) << rvs << endl;
    }
    
    return 0;
}

