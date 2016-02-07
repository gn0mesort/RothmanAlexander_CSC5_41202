/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Find the highest and lowest of 10 numbers
 * Created on February 5, 2016, 8:08 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int fndHigh(const int[], int);
int fndLow(const int[], int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 10; //Size of the array
    int nums[SIZE]; //The array to fill
    
    //Input Data
    for(int i = 0; i < 10; ++i){ //Read in a number for each array element
        cout << "Input value " << i + 1<< ": ";
        cin >> nums[i];
    }
    
    //Calculate and Output results
    cout << "The highest value is " << fndHigh(nums, SIZE) << endl;
    cout << "The lowest value is " << fndLow(nums, SIZE) << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/***********************************Find High**********************************/
/******************************************************************************/
//  Find the highest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  highest : the highest value in the array
int fndHigh(const int arr[], int length){
    int highest = 0;
    
    for(int i = 0; i < length; ++i){
        if(arr[i] > highest){
            highest = arr[i];
        }
    }
    
    return highest;
}

/******************************************************************************/
/***********************************Find Low***********************************/
/******************************************************************************/
//  Find the lowest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  lowest : the lowest value in the array
int fndLow(const int arr[], int length){
    int lowest = arr[0];
    
    for(int i = 0; i < length; ++i){
        if(arr[i] < lowest){
            lowest = arr[i];
        }
    }
    
    return lowest;
}

