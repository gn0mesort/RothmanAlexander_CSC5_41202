/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate rainfall statistics
 * Created on February 5, 2016, 9:05 PM
 */

#include <iostream>

using namespace std;

string month(int);
int fndHigh(const float[], int);
int fndLow(const float[], int);
float sum(const float[], int);
float avg(float, int);
void gSort(float[], int[], int);

int main(int argc, char** argv) {
    const unsigned char NMONTHS = 12;
    float total;
    int index[NMONTHS];
    float months[NMONTHS];
    

    for(int i = 0; i < NMONTHS; ++i){
        index[i] = i;
    }
    for (int i = 0; i < NMONTHS; ++i) {
        do {
            cout << "ENTER RAINFAIL FOR " << month(i + 1) << " IN INCHES: ";
            cin >> months[index[i]];
        } while (months[index[i]] < 0.0f);
    }
    total = sum(months, NMONTHS);
    cout << "THE LEAST RAIN FELL IN " << month(fndLow(months, NMONTHS) + 1) 
         << endl;
    cout << "THE MOST RAIN FELL IN " << month(fndHigh(months, NMONTHS) + 1) 
         << endl;
    cout << "TOTAL RAINFALL:   " << total << endl;
    cout << "AVERAGE RAINFALL: " << avg(total, NMONTHS) << endl;

    gSort(months, index, NMONTHS);
    cout << "MONTHS SORTED BY AVERAGE RAINFALL:" << endl;
    for(int i = 0; i < NMONTHS; ++i){
        cout << month(index[i] + 1) << endl;
    }
    
    return 0;
}

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

float avg(float sum, int count){
    return sum / count;
}

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