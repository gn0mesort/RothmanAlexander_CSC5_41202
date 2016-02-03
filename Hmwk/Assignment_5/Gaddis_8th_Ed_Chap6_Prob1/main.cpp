/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate falling distance due to gravity on Earth
 * Created on February 3, 2016, 7:39 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

const float ACLGRAV = 9.8f; 

float falDist(short);

int main(int argc, char** argv) {
    
    cout << fixed << setprecision(2) << showpoint;
    for(int i = 1; i <= 10; ++i){
        cout << "If you fall for " << setw(2) << i << " seconds you will fall " 
             << setw(5) << falDist(i) << " meters." << endl;
    }

    return 0;
}

float falDist(short time){
    return 0.5f * ACLGRAV * (time * time);
}

