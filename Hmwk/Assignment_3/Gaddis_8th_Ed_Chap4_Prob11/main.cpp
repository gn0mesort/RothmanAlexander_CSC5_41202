/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Create a random addition problem for a student
 * Created on January 20, 2016, 8:38 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    unsigned short num1, //The first operand in the problem
                   num2, //The second operand in the problem
                   answer, //The answer to the problem
                   inAnsr; //The answer input by the user
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    num1 = rand() % 1000; //Get a random value between 0 and 1000 for num1
    num2 = rand() % 1000; //Get a random value between 0 and 1000 for num2
    
    answer = num1 + num2; //Set the answer to num1 + num2
    
    //Problem Information
    cout << "Gaddis 8th Ed. Chap4 Prob11" << endl;
    cout << "Math Tutor" << endl;
    
    //Input Data
    cout << "Enter the correct sum:" << endl;
    cout << num1 << " + " << num2 << " = ";
    cin >> inAnsr;
    
    //Output Results
    if(inAnsr == answer){ //If the input answer is correct
        cout << "Congratulations!! You answered correctly!" << endl;
    }
    else{ //If the input answer is incorrect
        cout << "Your answer was incorrect. Better luck next time." << endl;
    }
    
    //Exit
    return 0;
}

