 /* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Square Display
 * Created on January 24, 2016, 3:00 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const char X = 'X';
    unsigned short sideLn;
    
    do{
    cout << "How long should each side be? ";
    cin >> sideLn;
    } while (sideLn > 15);
    
    for(int i = 0; i < sideLn; ++i){
        for(int j = 0; j < sideLn; ++j){
            cout << X;
        }
        cout << endl;
    }
    
    return 0;
}

