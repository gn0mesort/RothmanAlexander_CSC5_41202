/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Create a random addition problem for a student
 * Created on January 20, 2016, 8:38 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {
    unsigned short num1,
                   num2,
                   answer,
                   inAnsr;
    
    srand(static_cast<int>(time(0)));
    num1 = rand() % 1000;
    num2 = rand() % 1000;
    
    answer = num1 + num2;
    
    cout << "Enter the correct sum:" << endl;
    cout << num1 << " + " << num2 << " = ";
    cin >> inAnsr;
    
    if(inAnsr == answer){
        cout << "Congratulations!! You answered correctly!" << endl;
    }
    else{
        cout << "Your answer was incorrect. Better luck next time." << endl;
    }
    
    return 0;
}

