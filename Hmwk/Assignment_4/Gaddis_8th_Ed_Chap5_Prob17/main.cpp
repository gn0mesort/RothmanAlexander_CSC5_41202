/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Sales Bar Chart
 * Created on January 24, 2016, 3:25 PM
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
    const char ax = '*'; //Character to use in graphing
    short st1Sls, //Store 1 Sales
          st2Sls, //Store 2 Sales
          st3Sls, //Store 3 Sales
          st4Sls, //Store 4 Sales
          st5Sls; //Store 5 Sales
    
    //Input Data
    cout << "All values are in whole dollars" << endl;
    //Read in store 1 data
    cout << "Enter today's sales for store 1: ";
    cin >> st1Sls;
    //Read in store 2 data
    cout << "Enter today's sales for store 2: ";
    cin >> st2Sls;
    //Read in store 3 data
    cout << "Enter today's sales for store 3: ";
    cin >> st3Sls;
    //Read in store 4 data
    cout << "Enter today's sales for store 4: ";
    cin >> st4Sls;
    //Read in store 5 data
    cout << "Enter today's sales for store 5: ";
    cin >> st5Sls;
    cout << endl;
    
    //Calculate and Output results
    //Graph Header
    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;
    //Output Bar Graph
    cout << "Store 1: ";
    for(int i = 0; i < st1Sls / 100; ++i){ //Store 1 bar
        cout << ax;
    }
    cout << endl;
    cout << "Store 2: ";
    for(int i = 0; i < st2Sls / 100; ++i){ //Store 2 bar
        cout << ax;
    }
    cout << endl;
    cout << "Store 3: ";
    for(int i = 0; i < st3Sls / 100; ++i){ //Store 3 bar
        cout << ax;
    }
    cout << endl;
    cout << "Store 4: ";
    for(int i = 0; i < st4Sls / 100; ++i){ //Store 4 bar
        cout << ax;
    }
    cout << endl;
    cout << "Store 5: ";
    for(int i = 0; i < st5Sls / 100; ++i){ //Store 5 bar
        cout << ax;
    }
    cout << endl;
    
    //Exit
    return 0;
}

