/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on January 14, 2016, 5:45 AM
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float PI = atan(1) * 4;

int main(int argc, char** argv) {
    const float PCSAREA = 14.125f;
    float pPcs;
    unsigned short pDmtr, 
                   pRds;
    
    cout << "Input the diameter of your pizza in inches: ";
    cin >> pDmtr;
    
    pRds = pDmtr / 2;
    pPcs = (pRds * pRds * PI) / PCSAREA;
    
    cout << fixed << setprecision(1) << showpoint << "Your pizza may have up to "
         << pPcs << " slices." << endl;
    
    return 0;
}

