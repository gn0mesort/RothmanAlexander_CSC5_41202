/* 
 * File:   main.cpp
 * Author: Alexander Rothman, Cesar Gonzalez 
 * Purpose: Test Mark's Law for independent ifs
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
    //Declare and Initialize Variable
    unsigned short score; //The score to grade 
    char grade; //The grade to output
    
    //Input Data
    //Read in score
    cout << "Input a score between 0 and 100" << endl;
    cout << "Score: ";
    cin >> score;
    
    //Calculate Output
    //Independent Ifs
    if(score < 60)
        grade = 'F';
    if (score < 70 && score > 60)
        grade = 'D';
    if (score < 80 && score > 70)
        grade = 'C';
    if (score < 90 && score > 80)
        grade = 'B';
    if (score >= 90)
        grade = 'A';
    
    //Output Results
    cout << "Grade: " << grade << endl;
    
    //Exit
    return 0;
}

