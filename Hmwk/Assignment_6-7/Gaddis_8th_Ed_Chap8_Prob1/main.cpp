/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Account number validation
 * Created on February 5, 2016, 9:32 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool contains(const int[], int, int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const int ACCTS = 18; //Number of accounts
    const int ACCTNUM[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 
                            1302850, 8080152, 4562555, 5552012, 5050552,
                            7825877, 1250255, 1005231, 6545231, 3852085,
                            7576651, 7881200, 4581002 }; //Valid account numbers
    int acctNum; //The user's account number
    
    //Input Data
    cout << "ENTER YOUR ACCOUNT NUMBER: ";
    cin >> acctNum;
    
    //Calculate and Output results
    cout << "YOUR NUMBER IS " 
         << (contains(ACCTNUM, ACCTS, acctNum) ? "VALID." : "INVALID.") << endl;
    
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
    for(int i = 0; i < length; ++i){
        if(arr[i] == key){
            return true;
        }
    }
    
    return false;
}

