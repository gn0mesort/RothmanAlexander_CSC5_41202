/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Calculate a total grade and percentage
 * Created on January 13, 2016, 1:33 PM
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
    unsigned short exCount, //The number of exercises
                   mxScore, //The max score for the current exercise
                   score, //The score for the current exercise
                   mxTotal, //The the total max score
                   scTotal; //The total score
    
    //Input Data
    //Read in the number exercises
    cout << "How many exercises are there? ";
    cin >> exCount;
    
    //Read in scores and max scores for exercises
    for(int i = 0; i < exCount; ++i){ //Preform loop once for each exercise
        //Read in score for the current exercise
        cout << "Score received for exercise " << i + 1 << ": ";
        cin >> score;
        //Read in max score for the current exercise
        cout << "Total possible points for exercise " << i + 1 << ": ";
        cin >> mxScore;
        //Add scores to totals
        mxTotal += mxScore;
        scTotal += score;
    }
    
    //Calculate and Output Results
    cout << "Your total is " << scTotal << " out of " << mxTotal << ", or " 
         << (static_cast<float>(scTotal) / mxTotal) * 100 << '%' << endl; //Convert total score to a float, divide by total max score and multiply by 100 to convert to percentage
    
    //Exit
    return 0;
}

