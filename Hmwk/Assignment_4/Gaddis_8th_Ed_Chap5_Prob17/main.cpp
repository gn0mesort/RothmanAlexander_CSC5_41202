/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Sales Bar Chart
 * Created on January 24, 2016, 3:25 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const char ax = '*';
    short st1Sls,
            st2Sls,
            st3Sls,
            st4Sls,
            st5Sls;
    
    cout << "All values are in whole dollars" << endl;
    cout << "Enter today's sales for store 1: ";
    cin >> st1Sls;
    cout << "Enter today's sales for store 2: ";
    cin >> st2Sls;
    cout << "Enter today's sales for store 3: ";
    cin >> st3Sls;
    cout << "Enter today's sales for store 4: ";
    cin >> st4Sls;
    cout << "Enter today's sales for store 5: ";
    cin >> st5Sls;
    cout << endl;
    
    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;
    
    cout << "Store 1: ";
    for(int i = 0; i < st1Sls / 100; ++i){
        cout << ax;
    }
    cout << endl;
    cout << "Store 2: ";
    for(int i = 0; i < st2Sls / 100; ++i){
        cout << ax;
    }
    cout << endl;
    cout << "Store 3: ";
    for(int i = 0; i < st3Sls / 100; ++i){
        cout << ax;
    }
    cout << endl;
    cout << "Store 4: ";
    for(int i = 0; i < st4Sls / 100; ++i){
        cout << ax;
    }
    cout << endl;
    cout << "Store 5: ";
    for(int i = 0; i < st5Sls / 100; ++i){
        cout << ax;
    }
    cout << endl;
    
    return 0;
}

