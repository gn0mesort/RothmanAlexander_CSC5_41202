/* 
 * File:   main.cpp
 * Author: Alexander Rothman, Cesar Gonzalez 
 * Purpose: Test Mark's Law for dependent ifs
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
    unsigned short score; 
             char grade;
    
    //Input Data
    //Read in score
    cout << "Input a score between 0 and 100" << endl;
    cout << "Score: ";
    cin >> score;
    
    //Calculate Output
    //Dependent Ifs
    if( score < 60)
        grade = 'F';
    else if (score < 70)
        grade = 'D';
    else if (score < 80)
        grade = 'C';
    else if (score < 90)
        grade = 'B';
    else if (score >= 90)
        grade = 'A';
    else
        grade = 'F';
    
    //Output Results
    cout << "Grade: " << grade << endl;
    
    //Exit
    return 0;
}

