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
void fillAry(int [], int);
void prntAry(int [], int, int);
void lstSmal(int [], int, int);
void swap(int &, int &);
void markSrt(int[], int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 100;
    int arr[SIZE];
    
    srand(static_cast<unsigned int>(time(0)));
    
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
//Input
//  arr : the array to fill
//  length : the length of the array
//Output
//  arr : the filled array
void fillAry(int arr[], int length){
    //loop and fill the array with random numbers
    for(int i = 0; i < length; ++i){
        arr[i] = rand() % 90 + 10;
    }
}

/******************************************************************************/
/******************************Print Array*************************************/
/******************************************************************************/
//Input
//  arr : the array to print
//  length : the length of the array
void prntAry(int arr[], int length, int perLine){
    //loop and output array
    cout << endl;
    for(int i = 0; i < length; ++i){
        if(i % perLine == 0){
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

/******************************************************************************/
/******************************Smallest in List********************************/
/******************************************************************************/
//Input
//  arr : the array to use
//  length : the length of the array
//  pos : the position to check against
void lstSmal(int arr[] , int length, int pos){
    //loop and compare
    for(int i = pos + 1; i < length; ++i){
        if(arr[pos] > arr[i]){
            swap(arr[pos], arr[i]);
        }
    }
}

/******************************************************************************/
/***********************************Swap***************************************/
/******************************************************************************/
//Input
//  val1 : the first value
//  val2 : the second value
//Output
//  val1 : the second value swapped into the first value
//  val2 : the first value swapped into the second value
void swap(int &val1, int &val2){
    //swap one value with another
    val1 = val1 ^ val2;
    val2 = val1 ^ val2;
    val1 = val1 ^ val2;
}

/******************************************************************************/
/********************************Mark Sort*************************************/
/******************************************************************************/
//Input
//  arr : the array to sort
//  length : the length of the array
//Output
//  arr : the sorted array
void markSrt(int arr[], int length){
    for(int i = 0; i < length - 1; ++i){
        lstSmal(arr, length, i);
    }
}