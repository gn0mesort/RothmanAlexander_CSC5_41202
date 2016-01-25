/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Budget Analysis
 * Created on January 24, 2016, 3:48 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    char cont; //Character to check whether or not to continue looping
    short counter = 1; //Counter to indicate which expense you're on
    float mTotal, //The monthly total budget
          cTotal, //The current total used this month
          inVal; //The current input value
    
    //Input Data
    //Read in monthly total budget
    cout << "Input all values in dollars" << endl;
    cout << "MONTHLY BUDGET: $";
    cin >> mTotal;
    
    //Read in expenses
    do{ //Loop till not Y
        //Read in input value
        cout << "EXPENSE " << counter++ << ": $";
        cin >> inVal;
        //Calculate current monthly total
        cTotal += inVal;
        //Read in whether or not to continue
        cout << "Continue? (Y/N) ";
        cin >> cont;
        //Convert to uppercase
        cont = toupper(cont);
    } while(cont == 'Y'); 
    cout << endl;
   
    //Output Results
    cout << "MONTHLY BUDGET: $" << mTotal << endl;
    cout << "TOTAL EXPENSES: $" << cTotal << endl;
    cout << "NET BUDGET:     $" << mTotal - cTotal << endl;
    
    //Exit
    return 0;
}

