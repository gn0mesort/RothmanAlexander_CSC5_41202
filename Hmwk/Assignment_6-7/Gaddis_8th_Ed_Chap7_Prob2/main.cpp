/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate rainfall statistics
 * Created on February 5, 2016, 9:05 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string month(int);
int fndHigh(const float[], int);
int fndLow(const float[], int);
float sum(const float[], int);
float avg(float, int);
void gSort(float[], int[], int);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const unsigned char NMONTHS = 12; //The number of months
    float total; //The total rainfall in inches
    int index[NMONTHS]; //The indexing array
    float months[NMONTHS]; //The array of months
    

    for(int i = 0; i < NMONTHS; ++i){ //Fill Indexing array
        index[i] = i;
    }
    
    //Input Data
    for (int i = 0; i < NMONTHS; ++i) { //Loop through each month
        do { //Input Validation
            cout << "ENTER RAINFAIL FOR " << month(i + 1) << " IN INCHES: ";
            cin >> months[index[i]];
        } while (months[index[i]] < 0.0f);
    }
    //Calculate and Output Results
    total = sum(months, NMONTHS); //Calculate total rainfall
    //Output highest month
    cout << "THE LEAST RAIN FELL IN " << month(fndLow(months, NMONTHS) + 1) 
         << endl;
    //Output lowest month
    cout << "THE MOST RAIN FELL IN " << month(fndHigh(months, NMONTHS) + 1) 
         << endl;
    //Output total rainfall
    cout << "TOTAL RAINFALL:   " << total << endl;
    //Output average rainfall
    cout << "AVERAGE RAINFALL: " << avg(total, NMONTHS) << endl;

    //Sort months by rainfall
    gSort(months, index, NMONTHS);
    //Output sorted months
    cout << "MONTHS SORTED BY AVERAGE RAINFALL:" << endl;
    for(int i = 0; i < NMONTHS; ++i){
        cout << month(index[i] + 1) << endl;
    }
    
    //Exit
    return 0;
}

/******************************************************************************/
/************************************Month*************************************/
/******************************************************************************/
//  Convert an integer to a month name
//Inputs
//  num : the number of the month
//Outputs
//  A string containing the matching month name
string month(int num) {
    string r;
    switch (num) {
        case 1:
        {
            r = "JANUARY";
            break;
        }
        case 2:
        {
            r = "FEBRUARY";
            break;
        }
        case 3:
        {
            r = "MARCH";
            break;
        }
        case 4:
        {
            r = "APRIL";
            break;
        }
        case 5:
        {
            r = "MAY";
            break;
        }
        case 6:
        {
            r = "JUNE";
            break;
        }
        case 7:
        {
            r = "JULY";
            break;
        }
        case 8:
        {
            r = "AUGUST";
            break;
        }
        case 9:
        {
            r = "SEPTEMBER";
            break;
        }
        case 10:
        {
            r = "OCTOBER";
            break;
        }
        case 11:
        {
            r = "NOVEMBER";
            break;
        }
        case 12:
        {
            r = "DECEMBER";
            break;
        }
    }

    return r;
}

/******************************************************************************/
/*********************************Find Highest*********************************/
/******************************************************************************/
//  Finds the highest value in an array
//Inputs
//  arr : the array to search
//  length : the length of the array to search
//Output
//  The highest value in the array
int fndHigh(const float arr[], int length){
    int highPos = 0;
    float highest = 0;
    
    for(int i = 0; i < length; ++i){
        if(arr[i] > highest){
            highest = arr[i];
            highPos = i;
        }
    }
    
    return highPos;
}

/******************************************************************************/
/*********************************Find Lowest**********************************/
/******************************************************************************/
//  Finds the lowest value in an array
//Inputs
//  arr : the array to search
//  length : the length of the array to search
//Output
//  The lowest value in the array
int fndLow(const float arr[], int length){
    int lowPos = 0;
    float lowest = arr[0];
    
    for(int i = 0; i < length; ++i){
        if(arr[i] < lowest){
            lowest = arr[i];
            lowPos = i;
        }
    }
    
    return lowPos;
}

/******************************************************************************/
/************************************Average***********************************/
/******************************************************************************/
//  Calculates an average
//Inputs
//  sum : the sum of the values to be averaged
//  count : the number of values to be averaged
//Output
//  The average of the set
float avg(float sum, int count){
    return sum / count;
}

/******************************************************************************/
/*************************************Sum**************************************/
/******************************************************************************/
//  Sums an array
//Inputs
//  arr : the array to sum
//  length : the length of the array to sum
//Output
//  The sum of the values in the array
float sum(const float arr[], int length){
    float sum = 0;
    
    for(int i = 0; i < length; ++i){
        sum += arr[i];
    }
    
    return sum;
}

/******************************************************************************/
/*********************************Gnome Sort***********************************/
/******************************************************************************/
//  Sort an integer array.
//Inputs
//  arr : the array to sort
//  index : the indexing array
//  length : the length of the array to sort
void gSort(float arr[], int index[], int length){
    for(int pos = 1; pos < length;){ 
        if(arr[index[pos]] >= arr[index[pos - 1]]){
            ++pos; //move one position forward
        }
        else if (arr[index[pos]] <= arr[index[pos - 1]]){ //If the current character is less than or equal to the previous
            //Swap the current character and the last
            index[pos] = index[pos] ^ index[pos - 1];
            index[pos - 1] = index[pos] ^ index[pos - 1];
            index[pos] = index[pos] ^ index[pos - 1];
            if(pos > 1){ //If the position is greater than one
                --pos; //Move back one position
            }
        }
    }
}