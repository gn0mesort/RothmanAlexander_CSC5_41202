/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: A template program for menus
 * Created on January 24, 2016, 5:53 PM
 */

//System Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
//Problem Functions
string month(int);
int fndHigh(const int[], int);
int fndLow(const int[], int);
int fndHigh(const float[], int);
int fndLow(const float[], int);
float sum(const float[], int);
float avg(float, int);
vector<int> fillVec(string);
int fndHigh(const vector<int>);
int fndLow(const vector<int>);
int sum(const vector<int>);
int avg(int, int);
bool contains(const int[], int, int);
void gSort(float[], int[], int);
void bblSrt(int[], int);
int linSrch(const int[], int, int, unsigned int&);
int binSrch(const int[], int, int, unsigned int&);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short choice; //The input choice
    
    do{ //Loop unless input choice is not a list value
        //Output Solution List
        cout << "SOULUTION LIST" << endl;
        cout << "1. Solution to Gaddis 8th Ed. Chap7 Prob1" << endl;
        cout << "2. Solution to Gaddis 8th Ed. Chap7 Prob2" << endl;
        cout << "3. Solution to Gaddis 8th Ed. Chap7 Prob7" << endl;
        cout << "4. Solution to Gaddis 8th Ed. Chap8 Prob1" << endl;
        cout << "5. Solution to Gaddis 8th Ed. Chap8 Prob2" << endl;
        cout << "6. Solution to Gaddis 8th Ed. Chap8 Prob5" << endl;
        cout << "7. Solution to Gaddis 8th Ed. Chap8 Prob8" << endl;
        //Read in your choice
        cout << "Enter your choice 1-10 or anything else to quit: ";
        cin >> choice;
        cout << endl;
                
        switch(choice){ //Solution Implementations
            case 1: //Solution to Problem 1
            {
                //Execute Solution 1
                cout << "Solution to Gaddis 8th Ed. Chap7 Prob1" << endl;
                cout << "HIGHEST AND LOWEST OF 10 NUMBERS" << endl;
                solution1();
                //Exit Solution 1
                cout << endl;
                break;
            }
            case 2: //Solution to Problem 2
            {
                //Execute Solution 2
                cout << "Solution to Gaddis 8th Ed. Chap7 Prob2" << endl;
                cout << "RAINFALL STATISTICS" << endl;
                solution2();
                //Exit Solution 2
                cout << endl;
                break;
            }
            case 3: //Solution to Problem 3
            {
                //Execute Solution 3
                cout << "Solution to Gaddis 8th Ed. Chap7 Prob7" << endl;
                cout << "FILE I/O NUMBER ANALYSIS" << endl;
                solution3();
                //Exit Solution 3
                cout << endl;
                break;
            }
            case 4: //Solution to Problem 4
            {
                //Execute Solution 4
                cout << "Solution to Gaddis 8th Ed. Chap8 Prob1" << endl;
                cout << "ACCOUNT NUMBER VALIDATION" << endl;
                solution4();
                //Exit Solution 4
                cout << endl;
                break;
            }
            case 5: //Solution to Problem 5
            {
                //Execute Solution 5
                cout << "Solution to Gaddis 8th Ed. Chap8 Prob2" << endl;
                cout << "LOTTERY NUMBERS" << endl;
                solution5();
                //Exit Solution 5
                cout << endl;
                break;
            }
            case 6: //Solution to Problem 6
            {
                //Execute Solution 6
                cout << "Solution to Gaddis 8th Ed. Chap8 Prob5" << endl;
                cout << "RAINFALL STATISTICS MOD" << endl;
                solution6();
                //Exit Solution 6
                cout << endl;
                break;
            }
            case 7: //Solution to Problem 7
            {
                //Execute Solution 7
                cout << "Solution to Gaddis 8th Ed. Chap8 Prob8" << endl;
                cout << "SEARCH BENCHMARK" << endl;
                solution7();
                //Exit Solution 7
                cout << endl;
                break;
            }

        }
    } while(choice  > 0 && choice < 8);
    
    //Exit Message
    cout << "Exiting program..." << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/*******************************Solution 1*************************************/
/******************************************************************************/
void solution1(){
    //Declaration and Initialization
    const int SIZE = 10; //Size of the array
    int nums[SIZE]; //The array to fill
    
    //Input Data
    for(int i = 0; i < 10; ++i){ //Read in a number for each array element
        cout << "Input value " << i + 1<< ": ";
        cin >> nums[i];
    }
    
    //Calculate and Output results
    cout << "The highest value is " << fndHigh(nums, SIZE) << endl;
    cout << "The lowest value is " << fndLow(nums, SIZE) << endl;
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 2*************************************/
/******************************************************************************/
void solution2(){
    //Declaration and Initialization
    const unsigned char NMONTHS = 12; //The number of months
    float total; //The total rainfall in inches
    float months[NMONTHS]; //The array of months
    
    //Input Data
    for (int i = 0; i < NMONTHS; ++i) { //Loop through each month
        do { //Input Validation
            cout << "ENTER RAINFAIL FOR " << month(i + 1) << " IN INCHES: ";
            cin >> months[i];
        } while (months[i] < 0.0f);
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
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 3*************************************/
/******************************************************************************/
void solution3(){
    //Declaration and Initialization
    int total; //The total of the numbers
    string path = "numbers.txt"; //Path to the file containing the numbers
    vector<int> nums; //Vector to hold the numbers in the file
    
    //Input Data
    cout << "Reading file...";
    nums = fillVec(path); //Fill the vector
    cout << "DONE!" << endl;
    
    //Calculate and Output Results
    cout << "LOWEST VALUE:  " << fndLow(nums) << endl; //Find the highest
    cout << "HIGHEST VALUE: " << fndHigh(nums) << endl; //Find the lowest
    total = sum(nums); //Calculate the sum
    cout << "TOTAL VALUE:   " << total << endl;
    cout << "MEAN VALUE:    " << avg(total, nums.size()) << endl; //Average
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 4*************************************/
/******************************************************************************/
void solution4(){
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
}

/******************************************************************************/
/*******************************Solution 5*************************************/
/******************************************************************************/
void solution5(){
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
}

/******************************************************************************/
/*******************************Solution 6*************************************/
/******************************************************************************/
void solution6(){
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
}

/******************************************************************************/
/*******************************Solution 7*************************************/
/******************************************************************************/
void solution7(){
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
}


/******************************************************************************/
/***********************************Find High**********************************/
/******************************************************************************/
//  Find the highest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  highest : the highest value in the array
int fndHigh(const int arr[], int length){
    int highest = 0;
    
    for(int i = 0; i < length; ++i){
        if(arr[i] > highest){
            highest = arr[i];
        }
    }
    
    return highest;
}

/******************************************************************************/
/***********************************Find Low***********************************/
/******************************************************************************/
//  Find the lowest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  lowest : the lowest value in the array
int fndLow(const int arr[], int length){
    int lowest = arr[0];
    
    for(int i = 0; i < length; ++i){
        if(arr[i] < lowest){
            lowest = arr[i];
        }
    }
    
    return lowest;
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
/***********************************Average************************************/
/******************************************************************************/
//  Find the average of a vector
//Input
//  sum : the sum of a vector
//  count : the size of a vector
//Output
//  the average of the vector
int avg(int sum, int count){
    return sum / count;
}

/******************************************************************************/
/**************************************Sum*************************************/
/******************************************************************************/
//  Sum a vector
//Input
//  vec : the vector to sum
//Output
//  sum : the sum of the values in the vector
int sum(const vector<int> vec){
    int sum = 0;
    
    for(int i = 0; i < vec.size(); ++i){
        sum += vec[i];
    }
    
    return sum;
}

/******************************************************************************/
/***********************************Fill Vector********************************/
/******************************************************************************/
//  Fill a vector with values from a file
//Input
//  path : the path to the file to read
//Output
//  vec : A vector containing the values from the file
vector<int> fillVec(string path){
    int input;
    vector<int> vec;
    ifstream iFile;
    
    iFile.open(path.c_str());
    while(iFile >> input){
        vec.push_back(input);
    }
    iFile.close();
    
    return vec;
}

/******************************************************************************/
/***********************************Find High**********************************/
/******************************************************************************/
//  Find the highest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  highest : the highest value in the array
int fndHigh(const vector<int> vec){
    int highest = 0;
    
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] > highest){
            highest = vec[i];
        }
    }
    
    return highest;
}

/******************************************************************************/
/***********************************Find Low***********************************/
/******************************************************************************/
//  Find the lowest value in an array
//Input
//  arr : the array to search
//  length : the length of the array
//Output
//  lowest : the lowest value in the array
int fndLow(const vector<int> vec){
    int lowest = vec[0];
    
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] < lowest){
            lowest = vec[i];
        }
    }
    
    return lowest;
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