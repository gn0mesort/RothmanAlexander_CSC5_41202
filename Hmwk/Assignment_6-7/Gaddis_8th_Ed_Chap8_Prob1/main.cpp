/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Account number validation
 * Created on February 5, 2016, 9:32 PM
 */

#include <iostream>

using namespace std;

bool contains(const int[], int, int);

int main(int argc, char** argv) {
    const int ACCTS = 18;
    const int ACCTNUM[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 
                            1302850, 8080152, 4562555, 5552012, 5050552,
                            7825877, 1250255, 1005231, 6545231, 3852085,
                            7576651, 7881200, 4581002 };
    int acctNum;
    
    cout << "ENTER YOUR ACCOUNT NUMBER: ";
    cin >> acctNum;
    
    cout << "YOUR NUMBER IS " 
         << (contains(ACCTNUM, ACCTS, acctNum) ? "VALID." : "INVALID.") << endl;
    
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

