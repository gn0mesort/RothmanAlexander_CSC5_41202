/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Claculate book club points
 * Created on January 19, 2016, 8:14 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const unsigned char PNTT1 = 5,
                        PNTT2 = 15,
                        PNTT3 = 30,
                        PNTT4 = 60;
    unsigned char points;
    unsigned short purBook;
    
    cout << "How many books did you purchase this month? ";
    cin >> purBook;
    
    if(purBook < 1){
        points = 0;
    }
    else if(purBook < 2){
        points = PNTT1;
    }
    else if(purBook < 3){
        points = PNTT2;
    }
    else if(purBook < 4){
        points = PNTT3;
    }
    else{
        points = PNTT4;
    }
    
    cout << "BOOKS PURCHASED: " << purBook << endl;
    cout << "POINTS EARNED:   " << static_cast<int>(points) << endl;
    
    return 0;
}

