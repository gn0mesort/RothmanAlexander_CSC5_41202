/* 
 * File:   main.cpp
 * Author: Alexander Rothman, Cesar Gonzalez 
 * Purpose: Test Mark's Law for switch statements
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
    unsigned short score; //The score to grade
    char grade; //The grade to output
    
    //Input Data
    //Read in score
    cout << "Input a score between 0 and 100" << endl;
    cout << "Score: ";
    cin >> score;
    
    //Calculate Output
    score = score - (score % 10); //Round down to the nearest 10
    //Switch statement
    switch (score){
        case 0: grade = 'F';
                break;
        case 10: grade = 'F';
                 break;
        case 20: grade = 'F';
                 break;         
        case 30: grade = 'F';
                 break;
        case 40: grade = 'F';
                 break;
        case 50: grade = 'F';
                 break;
        case 60: grade = 'D';
                 break;
        case 70: grade = 'C';
                 break;
        case 80: grade = 'B';
                 break;
        case 90: grade = 'A';
                 break;
        case 100: grade = 'A';
                 break;
        default: grade = 'F';         
    }
    
    //Output Results
    cout << "Grade: " << grade << endl;
    
    //Exit
    return 0;
}

