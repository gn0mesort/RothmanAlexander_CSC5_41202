/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 6, 2016, 8:11 AM
 */

#include <iostream>

using namespace std;

const char cnvPerc = 100;

int main(int argc, char** argv) {
    float milBdgt = 600e9f,
          fedBdgt = 3.8e12f,
          percMil;
    
    percMil = milBdgt / fedBdgt * cnvPerc;
    
    cout << "Total Military Budget:                                $" << milBdgt << endl;
    cout << "Total Federal Budget:                                 $" << fedBdgt << endl;
    cout << "Military Budget as a percentage of the Federal Budget: " << percMil << "%" << endl;
    
    return 0;
}

