/* 
 * File:   main.cpp
 * Author: Alexander Rothman, Cesar Gonzalez 
 * Purpose: Test Mark's Law for ternary operators
 * Created on January 12, 2016, 10:11 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    unsigned short score; //The input score to grade
    char grade; //The output grade
    
    //Input Data
    //Read in score
    cout << "Input a score between 0 and 100" << endl;
    cout << "Score: ";
    cin >> score;
    
    //Calculate Output
    grade = score < 60 ? 'F' : //Chained ternary operator
            score < 70 ? 'D' : 
            score < 80 ? 'C' : 
            score < 90 ? 'B' : 
            score >= 90 ? 'A' : 'F'; 
    
    //Output results
    cout << "Grade: " << grade << endl;
    
    //Exit
    return 0;
}

