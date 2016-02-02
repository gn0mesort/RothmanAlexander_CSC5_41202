/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: To develop a sorting routine called BubbleSort
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
void fillAry(int [], int);
void prntAry(int [], int, int);
void bblSrt(int[], int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 100; //Size of the array
    int arr[SIZE]; //The array to sort

    srand(static_cast<unsigned int> (time(0))); //Seed PRNG

    fillAry(arr, SIZE); //Fill array
    prntAry(arr, SIZE, 10); //Print array
    bblSrt(arr, SIZE); //Test sort
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
void fillAry(int arr[], int length) {
    //loop and fill the array with random numbers
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 90 + 10;
    }
}

/******************************************************************************/
/******************************Print Array*************************************/
/******************************************************************************/
//  Print an array
//Input
//  arr : the array to print
//  length : the length of the array
void prntAry(int arr[], int length, int perLine) {
    //loop and output array
    cout << endl;
    for (int i = 0; i < length; ++i) {
        if (i % perLine == 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

/******************************************************************************/
/********************************Bubble Sort*************************************/
/******************************************************************************/
//  Sort an array using the BubbleSort algorithm
//Input
//  arr : the array to sort
//  length : the length of the array
//Output
//  arr : the sorted array
void bblSrt(int arr[], int length) {
    bool swap;
    do{
        swap = false;
        for(int j = 0; j < length - 1; ++j){
            if(arr[j] > arr[j + 1]){
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
                swap = true;
            }
        }
    } while(swap);
}