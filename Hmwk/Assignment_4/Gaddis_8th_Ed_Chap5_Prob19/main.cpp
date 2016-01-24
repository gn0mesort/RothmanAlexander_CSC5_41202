/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Budget Analysis
 * Created on January 24, 2016, 3:48 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    char cont;
    short counter = 1;
    float mTotal,
          cTotal,
          inVal;
    
    cout << "Input all values in dollars" << endl;
    cout << "MONTHLY BUDGET: $";
    cin >> mTotal;
    
    do{
        cout << "EXPENSE " << counter++ << ": $";
        cin >> inVal;
        cTotal += inVal;
        cout << "Continue? (Y/N) ";
        cin >> cont;
        cont = toupper(cont);
    } while(cont == 'Y');
    cout << endl;
   
    cout << "MONTHLY BUDGET: $" << mTotal << endl;
    cout << "TOTAL EXPENSES: $" << cTotal << endl;
    cout << "NET BUDGET:     $" << mTotal - cTotal << endl;
    
    return 0;
}

