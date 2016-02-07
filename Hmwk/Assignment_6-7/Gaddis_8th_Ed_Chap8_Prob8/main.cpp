/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Benchmark Linear and Binary Search
 * Created on February 6, 2016, 9:11 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void bblSrt(int[], int);
int linSrch(const int[], int, int, unsigned int&);
int binSrch(const int[], int, int, unsigned int&);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const unsigned int SIZE = 20; //The size of the array to search
    unsigned int count = 0, //The number of comparisons made by a search
                 key; //The key to search for
    int arr[SIZE]; //The array to search
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    for(int i = 0; i < SIZE; ++i){ //Generate array values
        arr[i] = rand() % 100000;
    }
    
    key = arr[rand() % SIZE]; //Pick a key from within the array
    
    //Calculate and Output Results
    //Linear Search
    cout << "SEARCHING FOR: " << key << endl;
    cout << "LINEAR SEARCH FOUND " << key << " AT " 
         << linSrch(arr, SIZE, key, count);
    //If you don't output count on a seperate line it's 0 because the output of count occurs before the function call
    //At least on my computer
    cout << " IN " << count 
         << " COMPARISONS" << endl;
    count = 0; //Reset count
    //Binary Search
    bblSrt(arr, SIZE); //Sort array
    cout << "BINARY SEARCH FOUND " << key << " AT " 
         << binSrch(arr, SIZE, key, count); 
    cout << " IN " << count 
         << " COMPARISONS" << endl;
    return 0;
}

/******************************************************************************/
/********************************Linear Search*********************************/
/******************************************************************************/
//  Search an array for a key value using linear search
//Input
//  arr : the array to search
//  length : the length of the array
//  key : the key to search for
//  count : the number of comparisons made
//Output
//  The index of the key value or -1 if not found
//  count : the number of comparisons made
int linSrch(const int arr[], int length, int key, unsigned int &count){
    for(int i = 0; i < length; ++i){ //Loop through each element
        count += 1;
        if (arr[i] == key){ //compare each element to the key
            return i;
        }
    }
    
    return -1;
}


/******************************************************************************/
/********************************Binary Search*********************************/
/******************************************************************************/
//  Search an array for a key value using binary search
//Input
//  arr : the array to search
//  length : the length of the array
//  key : the key to search for
//  count : the number of comparisons made
//Output
//  The index of the key value or -1 if not found
//  count : the number of comparisons made
int binSrch(const int arr[], int length, int key, unsigned int &count){
    int first = 0, //The low end of our guessing range
        last = length - 1, //The high end of our guessing range
        middle; //The midpoint of our range
    
    do{ //Search while first and last haven't passed each other
        count += 1;
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