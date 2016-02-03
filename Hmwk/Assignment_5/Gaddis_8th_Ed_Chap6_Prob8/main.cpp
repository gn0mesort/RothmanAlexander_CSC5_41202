/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Preform coin tosses
 * Created on February 3, 2016, 7:39 AM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char cnToss(void);

int main(int argc, char** argv) {
    unsigned short totHead = 0,
                   totTail = 0,
                   tosses;
    srand(static_cast<int>(time(0)));
    
    cout << "How many tosses would you like to preform: ";
    cin >> tosses;
    
    for(int i = 0; i < tosses; ++i){
        cnToss() == 1 ? ++totHead : ++totTail;
    }
    cout << "TOTAL HEADS:  " << totHead << endl;
    cout << "TOTAL TAILS:  " << totTail << endl;
    cout << "TOTAL TOSSES: " << totHead + totTail << endl;
    
    return 0;
}

char cnToss(){
    unsigned char toss = rand() % 2 + 1;
    cout << (toss == 1 ? "HEADS" : "TAILS") << endl;
    return toss;
}
