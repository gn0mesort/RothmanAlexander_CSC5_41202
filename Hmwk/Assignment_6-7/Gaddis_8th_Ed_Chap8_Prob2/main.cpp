/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Pick lottery winners
 * Created on February 6, 2016, 5:07 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool contains(const int[], int, int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int SIZE = 10; //Number of lottery numbers to pick
    int winNum; //The winning number
    int myNums[SIZE]; //A collection of picked lottery numbers
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Generate picked lottery numbers at random
    cout << "Your numbers:" << endl;
    for(int i = 0; i < SIZE; ++i){
        myNums[i] = rand() % 89999 + 10000; //Generate a number between 10000 and 99999
        cout << myNums[i] << " "; //Output each number
    }
    cout << endl;
    
    //Input Data
    do{ //Input Validation
        cout << "Enter this weeks winning number: ";
        cin >> winNum;
    } while(winNum < 10000 || winNum > 99999);
    
    //Calculate and output results
    cout << "YOU " << (contains(myNums, SIZE, winNum) ? "WIN!" : "LOSE!") 
         << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/***********************************Contains***********************************/
/******************************************************************************/
//  Search an array to determine whether or not it contains a value
//Input
//  arr : the array to search
//  length : the length of the array
//  key : the key to search for
//Output
//  true if the key value is found
//  false otherwise
bool contains(const int arr[], int length, int key){
    for(int i = 0; i < length; ++i){ //Loop through each value
        if(arr[i] == key){ //compare the value to the key
            return true; //Return true if they match
        }
    }
    
    return false; //Otherwise return false
}