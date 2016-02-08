/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: To develop a sorting routine called MarkSort
 * Created on February 2, 2016, 8:18 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *, int);
void prntAry(int *, int, int);
void markSrt(int *, int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 100; //Size of the array
    int arr[SIZE]; //The array to sort

    srand(static_cast<unsigned int> (time(0))); //Seed PRNG

    fillAry(arr, SIZE); //Fill array
    prntAry(arr, SIZE, 10); //Print array
    markSrt(arr, SIZE); //Test sort
    prntAry(arr, SIZE, 10); //Print sorted array

    //Exit
    return 0;
}

/******************************************************************************/
/*******************************Fill Array*************************************/
/******************************************************************************/
//  Fill an array with random integer values for later sorting
//Input
//  arr : the array to fill
//  length : the length of the array
//Output
//  arr : the filled array
void fillAry(int *arr, int length) {
    //loop and fill the array with random numbers
    for (int i = 0; i < length; ++i) {
        *(arr + i) = rand() % 90 + 10;
    }
}

/******************************************************************************/
/******************************Print Array*************************************/
/******************************************************************************/
//  Print an array
//Input
//  arr : the array to print
//  length : the length of the array
void prntAry(int *arr, int length, int perLine) {
    //loop and output array
    cout << endl;
    for (int i = 0; i < length; ++i) {
        if (i % perLine == 0) {
            cout << endl;
        }
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

/******************************************************************************/
/********************************Mark Sort*************************************/
/******************************************************************************/
//  Sort an array using the MarkSort algorithm
//Input
//  arr : the array to sort
//  length : the length of the array
//Output
//  arr : the sorted array
void markSrt(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) { //loop through array
        //loop and compare
        for (int j = i + 1; j < length; ++j) {
            if (*(arr + i) > *(arr + j)) {
                //swap one value with another
                *(arr + i) = *(arr + i) ^ *(arr + j);
                *(arr + j) = *(arr + i) ^ *(arr + j);
                *(arr + i) = *(arr + i) ^ *(arr + j);
            }
        }
    }
}