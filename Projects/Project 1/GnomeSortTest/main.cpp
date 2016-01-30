/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Test Gnome Sort Algorithm
 * Created on January 29, 2016, 9:53 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const unsigned char LENGTH = 27; //Length
    char cArr[LENGTH] = {0}; //String
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    for(int i = 0; i < LENGTH - 1; ++i){ //Generate a random string
        cArr[i] = toupper(rand() % 26 + 65);
    }
    
    cout << cArr << endl; //Output unsorted array
    //Gnome Sort modified to deal with a null terminator
    for(int pos = 1; pos < LENGTH;){ //Gnome Sort
        if(cArr[pos] >= cArr[pos - 1] || cArr[pos] == '\0'){
            ++pos;
        }
        else if (cArr[pos] <= cArr[pos - 1] && cArr[pos] != '\0'){
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos - 1] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            if(pos > 1){
                --pos;
            }
        }
    }
    cout << cArr << endl; //Output sorted array
    
    return 0;
}

