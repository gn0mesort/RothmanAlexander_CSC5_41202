/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Splenda is a scary horrible thing
 * Created on January 13, 2016, 7:54 PM
 */

#include <iostream>

const float CNVSODA = 0.001f;
const float CNVGRM = 453.59f;
const short SDAMASS = 350;

using namespace std;

int main(int argc, char** argv) {
    unsigned short msWght,
            msDsge,
            dtWght,
            killAmt,
            numSoda;
    
    cout << "Enter the amount of sweetener needed to kill a mouse: ";
    cin >> msDsge;
    cout << "Enter the weight of the mouse in grams: ";
    cin >> msWght;
    cout << "Enter your ideal weight in pounds: ";
    cin >> dtWght;
    
    dtWght *= CNVGRM; //Convert from pounds to grams
    
    killAmt = (msDsge * dtWght) / msWght;
    numSoda = CNVSODA * SDAMASS * killAmt;
    
    cout << "Your ideal weight in grams is: " << dtWght << endl;
    cout << "The amount needed to kill you is: " << killAmt << " grams" << endl;
    cout << "The number of sodas you can safely consume is: " << numSoda 
         << " sodas" << endl;
    
    
    
    return 0;
}

