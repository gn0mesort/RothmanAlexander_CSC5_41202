/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Random number guess game
 * Created on January 24, 2016, 3:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    short gsNum,
          inGsNum;
    
    srand(static_cast<int>(time(0)));
    
    gsNum = rand() % 101;
    
    cout << "Random Number Guessing Game" << endl;
    do{
        cout << "Guess a number: ";
        cin >> inGsNum;
        
        if(inGsNum < gsNum){
            cout << "Too low, try again." << endl;
        }
        else if (inGsNum > gsNum){
            cout << "Too high, try again." << endl;
        }
      
    } while(inGsNum != gsNum);
    
    cout << "You got it!" << endl;    
    
    return 0;
}

