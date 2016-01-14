/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on January 13, 2016, 1:33 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned short exCount,
                   mxScore,
                   score,
            mxTotal,
            scTotal;
    
    cout << "How many exercises are there? ";
    cin >> exCount;
    
    for(short i = 0; i < exCount; ++i){
        cout << "Score received for exercise " << i + 1 << ": ";
        cin >> score;
        cout << "Total possible points for exercise " << i + 1 << ": ";
        cin >> mxScore;
        mxTotal += mxScore;
        scTotal += score;
    }
    
    cout << "Your total is " << scTotal << " out of " << mxTotal << ", or " 
         << (static_cast<float>(scTotal) / mxTotal) * 100 << '%' << endl;
    
    return 0;
}

