/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Apply discounts to software sales
 * Created on January 19, 2016, 7:56 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const unsigned short PRICE = 99;
    const float DSCT1 = 0.2f,
                DSCT2 = 0.3f,
                DSCT3 = 0.4f,
                DSCT4 = 0.5f;
    unsigned short qSftwr, 
                   total;
    float dsc;
    
    do{
        cout << "How much software are you purchasing? ";
        cin >> qSftwr;
    } while(qSftwr < 0);
    
    if (qSftwr < 10){
        dsc = 0.0f;
    }
    else if (qSftwr < 20){
        dsc = DSCT1;
    }
    else if (qSftwr < 50){
        dsc = DSCT2;
    }
    else if (qSftwr < 100){
        dsc = DSCT3;
    }
    else{
        dsc = DSCT4;
    }
    
    total = (PRICE * qSftwr) - ((PRICE * qSftwr) * dsc);
    
    cout << "SUBTOTAL: $" << PRICE * qSftwr << endl;
    cout << "DISCOUNT:  " << dsc * 100 << "%" << endl;
    cout << "TOTAL:    $" << total << endl; 
    
    return 0;
}

