/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Pick lottery winners
 * Created on February 6, 2016, 5:07 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool contains(const int[], int, int);

int main(int argc, char** argv) {
    const int SIZE = 10;
    int winNum;
    int myNums[SIZE];
    
    srand(static_cast<int>(time(0)));
    
    cout << "Your numbers:" << endl;
    for(int i = 0; i < SIZE; ++i){
        myNums[i] = rand() % 89999 + 10000;
        cout << myNums[i] << " ";
    }
    cout << endl;
    
    do{
        cout << "Enter this weeks winning number: ";
        cin >> winNum;
    } while(winNum < 10000 || winNum > 99999);
    
    cout << "YOU " << (contains(myNums, SIZE, winNum) ? "WIN!" : "LOSE!") 
         << endl;
    
    
    return 0;
}

bool contains(const int arr[], int length, int key){
    for(int i = 0; i < length; ++i){
        if(arr[i] == key){
            return true;
        }
    }
    
    return false;
}