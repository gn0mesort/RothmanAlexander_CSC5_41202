/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Splenda is a scary horrible thing
 * Created on January 13, 2016, 7:54 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants
const float CNVSODA = 0.001f; //Conversion to the amount of sweetener in a soda
const float CNVGRM = 453.59f; //Convert pounds to grams
const short SDAMASS = 350; //The mass of a standard can of soda

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short msWght, //The weight of the mouse in grams
                   msDsge, //The dosage of sweetener a mouse can handle in grams
                   dtWght, //The dieter's ideal weight in pounds
                   killAmt, //The amount of sweetener needed to kill the dieter in grams 
                   numSoda; //The number of soda's needed to kill the dieter
    
    //Input Data
    //Read in the amount of sweetener needed to kill a mouse
    cout << "Enter the amount of sweetener needed to kill a mouse: ";
    cin >> msDsge;
    //Read in the weight of the mouse
    cout << "Enter the weight of the mouse in grams: ";
    cin >> msWght;
    //Read in the ideal weight of the dieter
    cout << "Enter your ideal weight in pounds: ";
    cin >> dtWght;
    
    //Calculate Output
    dtWght *= CNVGRM; //Convert from pounds to grams
    killAmt = (msDsge * dtWght) / msWght; //Calculate the amount of sweetener needed to kill the dieter
    numSoda = CNVSODA * SDAMASS * killAmt; //Convert that amount to the amount sodas needed to kill the dieter
    
    //Output Results
    cout << "Your ideal weight in grams is: " << dtWght << endl;
    cout << "The amount needed to kill you is: " << killAmt << " grams" << endl;
    cout << "The number of sodas you can safely consume is: " << numSoda 
         << " sodas" << endl;
    
    //Exit
    return 0;
}

