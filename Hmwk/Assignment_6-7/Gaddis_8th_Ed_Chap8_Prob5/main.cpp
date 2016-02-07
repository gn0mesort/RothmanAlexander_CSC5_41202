/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Read and analyze numbers from a file
 * Created on February 5, 2016, 8:22 PM
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> fillVec(string);
int fndHigh(const vector<int>);
int fndLow(const vector<int>);
int sum(const vector<int>);
int avg(int, int);

int main(int argc, char** argv) {
    int total;
    string path = "numbers.txt";
    vector<int> nums;
    
    cout << "Reading file...";
    nums = fillVec(path);
    cout << "DONE!" << endl;
    cout << "LOWEST VALUE:  " << fndLow(nums) << endl;
    cout << "HIGHEST VALUE: " << fndHigh(nums) << endl;
    total = sum(nums);
    cout << "TOTAL VALUE:   " << total << endl;
    cout << "MEAN VALUE:    " << avg(total, nums.size()) << endl;
    
    return 0;
}

int avg(int sum, int count){
    return sum / count;
}

int sum(const vector<int> vec){
    int sum = 0;
    
    for(int i = 0; i < vec.size(); ++i){
        sum += vec[i];
    }
    
    return sum;
}

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

int fndHigh(const vector<int> vec){
    int highest = 0;
    
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] > highest){
            highest = vec[i];
        }
    }
    
    return highest;
}

int fndLow(const vector<int> vec){
    int lowest = vec[0];
    
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] < lowest){
            lowest = vec[i];
        }
    }
    
    return lowest;
}