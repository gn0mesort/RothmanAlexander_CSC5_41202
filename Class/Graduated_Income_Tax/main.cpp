/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 13, 2016, 11:13 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned int   grsIncm,
                   netIncm,
                   txTotal;
    
    cout << "Enter your gross income in dollars: $";
    cin >> grsIncm;
    
    if(grsIncm > 5000){
        txTotal += grsIncm * 0.05f;
    }
    if(grsIncm > 10000){
        txTotal += grsIncm * 0.1f;
    }
    if(grsIncm > 15000){
        txTotal += grsIncm * 0.15f;
    }
    if(grsIncm > 20000){
        txTotal += grsIncm * 0.2f;
    }
    if(grsIncm > 25000){
        txTotal += grsIncm * 0.25f;
    }
    if(grsIncm > 30000){
       txTotal += grsIncm * 0.3f;
    }
    if(grsIncm > 35000){
        txTotal += grsIncm * 0.35f;
    }
    if(grsIncm > 40000){
        txTotal += grsIncm * 0.4f;
    }
    
    netIncm = grsIncm - txTotal;
    
    cout << "GROSS INCOME: " << grsIncm << endl;
    cout << "NET INCOME: " << netIncm << endl;
    cout << "TOTAL TAX: " << txTotal << endl;
        
    return 0;
}

