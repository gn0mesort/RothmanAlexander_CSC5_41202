/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Find all matching elements with a binary search
 * Created on February 4, 2016, 8:51 AM
 */

//Systme Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void bblSrt(int[], int);
void gSort(int[], int);
int binSrch(int[], int, int);
void fndAll(int[], int, int);
void fillAry(int[], int);
void prntAry(int[], int, int); 

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const unsigned short SIZE = 1000; //The size of the array to search
    int key; //The key to search for
    int arr[SIZE]; //The array to search
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Fill Array
    cout << "FILLING ARRAY...";
    fillAry(arr, SIZE);
    cout << "DONE!" << endl;
    //Bubble Sort Array
    cout << "SORTING ARRAY...";
    //bblSrt(arr, SIZE); //Slower
    gSort(arr, SIZE); //Faster than bubble sort
    cout << "DONE!" << endl;
    //Output Sorted Array
    cout << "SORTED ARRAY:" << endl;
    prntAry(arr, SIZE, 10);
    //Generate the search key
    key = arr[rand() % SIZE]; //Key will always be a value found in the array
    cout << "KEY IS: " << key << endl; //Output key
    //Find all indexes for the key
    fndAll(arr, SIZE, key);
    
    //Exit
    return 0;
}

/******************************************************************************/
/***********************************Find All***********************************/
/******************************************************************************/
//  Search an array for a key value using binary search
//Input
//  arr : the array to search
//  length : the length of the array
//  key : the key to search for
void fndAll(int arr[], int length, int key){
    bool aFound[length]; //An array indicating whether or not each value has been found
    for(int i = 0; i < length; ++i){
        int found = binSrch(arr, length - i, key); //Search for the key decreasing the length each time
        if(found != -1 && !aFound[found]){ //If found and not already found
            cout << "FOUND AT: arr[" << found << "]" << endl; //Output the location of the key
            cout << "arr[" << found << "] IS: " << arr[found] << endl; //Check the value at that location
            aFound[found] = true; //Set the position as already found
        }
    }
}

/******************************************************************************/
/********************************Binary Search*********************************/
/******************************************************************************/
//  Search an array for a key value using binary search
//Input
//  arr : the array to search
//  length : the length of the array
//  key : the key to search for
//Output
//  The index of the key value or -1 if not found
int binSrch(int arr[], int length, int key){
    int first = 0, //The low end of our guessing range
        last = length - 1, //The high end of our guessing range
        middle; //The midpoint of our range
    
    do{ //Search while first and last haven't passed each other
        middle = (first + last) / 2; //calculate midpoint
        if(arr[middle] == key){ return middle; } //return position if found
        else if(arr[middle] > key){ last = middle - 1; } //reset last
        else{ first = middle + 1; } //reset first
    } while(first <= last);
    
    return -1; //return -1 if not found
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
    for (int i = 0; i < length; ++i) {
        if (i % perLine == 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

/******************************************************************************/
/*********************************Gnome Sort***********************************/
/******************************************************************************/
//  Sort an integer array.
//Inputs
//  arr : the array to sort
//  length : the length of the array to sort
void gSort(int arr[], int length){
    for(int pos = 1; pos < length;){ 
        if(arr[pos] >= arr[pos - 1]){
            ++pos; //move one position forward
        }
        else if (arr[pos] <= arr[pos - 1]){ //If the current character is less than or equal to the previous
            //Swap the current character and the last
            arr[pos] = arr[pos] ^ arr[pos - 1];
            arr[pos - 1] = arr[pos] ^ arr[pos - 1];
            arr[pos] = arr[pos] ^ arr[pos - 1];
            if(pos > 1){ //If the position is greater than one
                --pos; //Move back one position
            }
        }
    }
}