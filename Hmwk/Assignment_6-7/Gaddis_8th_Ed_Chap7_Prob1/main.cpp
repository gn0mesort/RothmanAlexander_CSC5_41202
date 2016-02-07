/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Find the highest and lowest of 10 numbers
 * Created on February 5, 2016, 8:08 PM
 */

#include <iostream>

using namespace std;

int fndHigh(const int[], int);
int fndLow(const int[], int);

int main(int argc, char** argv) {
    const int SIZE = 10;
    int nums[SIZE];
    
    for(int i = 0; i < 10; ++i){
        cout << "Input value " << i + 1<< ": ";
        cin >> nums[i];
    }
    
    cout << "The highest value is " << fndHigh(nums, SIZE) << endl;
    cout << "The lowest value is " << fndLow(nums, SIZE) << endl;
    
    return 0;
}

int fndHigh(const int arr[], int length){
    int highest = 0;
    
    for(int i = 0; i < length; ++i){
        if(arr[i] > highest){
            highest = arr[i];
        }
    }
    
    return highest;
}

int fndLow(const int arr[], int length){
    int lowest = arr[0];
    
    for(int i = 0; i < length; ++i){
        if(arr[i] < lowest){
            lowest = arr[i];
        }
    }
    
    return lowest;
}

