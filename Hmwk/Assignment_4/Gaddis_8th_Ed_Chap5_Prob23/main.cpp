/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Pattern Printing
 * Created on January 24, 2016, 3:15 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Output Header
    cout << setw(10) << "Pattern A" << "  " << setw(10) << "Pattern B" << endl;
    
    //Output pattern
    for(int i = 1, j = 10; i <= 10; ++i, --j){
        string fwd(i, '*'), //create a new string for the ascending pattern with i *'s
               rvs(j, '*'); //create a new string for the descending pattern with j *'s
        //Output one line of the pattern
        cout << setw(10) << fwd << "  " << setw(10) << rvs << endl;
    }
    
    //Exit
    return 0;
}

