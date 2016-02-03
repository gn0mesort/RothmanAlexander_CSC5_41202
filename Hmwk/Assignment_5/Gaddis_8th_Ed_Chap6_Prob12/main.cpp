/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Star Search
 * Created on February 3, 2016, 8:20 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void gJdgDat(float[], char);
void calcScr(float[], char);
int fndHigh(float[], char);
int fndLow(float[], char);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const char JUDGES = 5; //The number of judges
    float scores[JUDGES]; //An array holding each judges score
    
    //Input Data
    gJdgDat(scores, JUDGES); //Fill the array with scores
    
    //Calculate and Output Results
    calcScr(scores, JUDGES); //Calculate the final score
    
    //Exit
    return 0;
}

/******************************************************************************/
/*******************************Get Judge Data*********************************/
/******************************************************************************/
//  Get the data for each judge and place it into the score array
//Input
//  scores[] : the scoring array
//  length : the length of the array
//Output
//  scores[] : the filled scoring array
void gJdgDat(float scores[], char length){
    //Prompt user for scores
    cout << "Input the scores for each judge. Scores are between 0 and 10" 
         << endl;
    for(int i = 0; i < length; ++i){ //loop through each judge
        do{ //Input Validation
            cout << "JUDGE " << i + 1 << ": ";
            cin >> scores[i]; //set the current judges score to input
        } while(scores[i] < 0.0f && scores[i] > 10.0f);
    }
}

/******************************************************************************/
/*****************************Calculate Scores*********************************/
/******************************************************************************/
//  Get the data for each judge and place it into the score array
//Input
//  scores[] : the scoring array
//  length : the length of the array
void calcScr(float scores[], char length){
    const float NOCOUNT = -1.0f; //Special value indicating not to use it in scoring
    float total = 0.0f; //The total score
    
    scores[fndHigh(scores, length)] = NOCOUNT; //Find the highest score
    scores[fndLow(scores, length)] = NOCOUNT; //Find the lowest score
    
    for(int i = 0; i < length; ++i){ //loop through the scores and calculate the total
        if(scores[i] != NOCOUNT){ //Do not count the highest or lowest score
            total += scores[i];
        }
    }
    //Calculate and output final score
    cout << fixed << setprecision(2) << showpoint;
    cout << "FINAL SCORE: " << total / (length - 2) << endl;
    
}

/******************************************************************************/
/**********************************Find High***********************************/
/******************************************************************************/
//  Find the position of the highest score
//Input
//  scores[] : the scoring array
//  length : the length of the array
//Output
//  highPos : the position of the highest score
int fndHigh(float scores[], char length){
    float highest = 0; //The current highest score
    int highPos = 0; //The position of the current highest score
    for (int i = 0; i < length; ++i){ //loop through each score
        if(scores[i] >= highest){ //if the current score is higher than the highest score
            highest = scores[i];
            highPos = i;
        }
    }
    
    return highPos;
}

/******************************************************************************/
/*********************************Find Lowest**********************************/
/******************************************************************************/
//  Find the position of the lowest score 
//Input
//  scores[] : the scoring array
//  length : the length of the array
//Output
//  lowPos : the position of the lowest score
int fndLow(float scores[], char length){
    float lowest = 0;  //The current lowest score
    int lowPos = 0; //The position of the current lowest score
    for (int i = 0; i < length; ++i){ //loop through each score
        if(scores[i] <= lowest){ //if the current score is lower than the lowest score
            lowest = scores[i];
            lowPos = i;
        }
    }
    
    return lowPos;
}