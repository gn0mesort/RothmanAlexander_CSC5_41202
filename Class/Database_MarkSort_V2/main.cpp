/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: To develop a sorting routine called MarkSort
 * Created on February 4, 2016, 8:15 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *, int *, int);
void prntAry(int *, int *, int, int);
void prntAry(int *, int, int);
void markSrt(int *, int *, int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 100; //Size of the array
    int arr[SIZE], //The array to sort
        index[SIZE];
    

    srand(static_cast<unsigned int> (time(0))); //Seed PRNG

    fillAry(arr, index, SIZE); //Fill array
    cout << "Original Array" << endl;
    prntAry(arr, SIZE, 10); //Print array
    cout << "Original Index" << endl;
    prntAry(index, SIZE, 10); //Print array
    cout << "Original Array using Index array" << endl;
    prntAry(arr, index, SIZE, 10);
    markSrt(arr, index, SIZE); //Test sort
    cout << "Sorted Index" << endl;
    prntAry(index, SIZE, 10); //Print array
    cout << "Sorted Indexed Array" << endl;
    prntAry(arr, index, SIZE, 10); //Print sorted array
    cout << "Original Array" << endl;
    prntAry(arr, SIZE, 10); //Print array

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
void fillAry(int *arr, int *index, int length) {
    //loop and fill the array with random numbers
    for (int i = 0; i < length; ++i) {
        *(arr + i) = rand() % 90 + 10;
        *(index + i) = i;
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
        cout << setw(2) << *(arr + i) << " ";
    }
    cout << endl << endl;
}

/******************************************************************************/
/******************************Print Array*************************************/
/******************************************************************************/
//  Print an array
//Input
//  arr : the array to print
//  index : an array for indexing
//  length : the length of the array
void prntAry(int *arr, int *index, int length, int perLine) {
    //loop and output array
    cout << endl;
    for (int i = 0; i < length; ++i) {
        if (i % perLine == 0) {
            cout << endl;
        }
        cout << setw(2) << *(arr + *(index + i)) << " ";
    }
    cout << endl << endl;
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
void markSrt(int *arr, int *index, int length) {
    for (int i = 0; i < length - 1; ++i) { //loop through array
        //loop and compare
        for (int j = i + 1; j < length; ++j) {
            if (*(arr + *(index + i)) > *(arr + *(index + j))) {
                //swap one value with another
                *(index + i) = *(index + i) ^ *(index + j);
                *(index + j) = *(index + i) ^ *(index + j);
                *(index + i) = *(index + i) ^ *(index + j);
            }
        }
    }
}