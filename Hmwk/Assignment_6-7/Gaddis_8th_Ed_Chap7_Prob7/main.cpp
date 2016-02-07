/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Read and analyze numbers from a file
 * Created on February 5, 2016, 8:22 PM
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
vector<int> fillVec(string);
int fndHigh(const vector<int>);
int fndLow(const vector<int>);
int sum(const vector<int>);
int avg(int, int);

//Begin Execution
int main(int argc, char** argv) {
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
    return 0;
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