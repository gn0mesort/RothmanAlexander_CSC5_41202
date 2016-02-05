/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: A template program for menus
 * Created on January 24, 2016, 5:53 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants
const float ACLGRAV = 9.8f; //Acceleration due to gravity on Earth

//Function Prototypes
void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
//Functions used by solutions
bool isPrime(int);
float falDist(short);
char cnToss(void);
void gJdgDat(float[], char);
void calcScr(float[], char);
int fndHigh(float[], char);
int fndLow(float[], char);
float calcRtl(unsigned short, unsigned short);

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short choice; //The input choice
    
    do{ //Loop unless input choice is not a list value
        //Output Solution List
        cout << "SOULUTION LIST" << endl;
        cout << "1. Solution to Gaddis 8th Ed. Chap6 Prob1" << endl;
        cout << "2. Solution to Gaddis 8th Ed. Chap6 Prob5" << endl;
        cout << "3. Solution to Gaddis 8th Ed. Chap6 Prob8" << endl;
        cout << "4. Solution to Gaddis 8th Ed. Chap6 Prob12" << endl;
        cout << "5. Solution to Gaddis 8th Ed. Chap6 Prob22" << endl;
        //Read in your choice
        cout << "Enter your choice 1-5 or anything else to quit: ";
        cin >> choice;
        cout << endl;
                
        switch(choice){ //Solution Implementations
            case 1: //Solution to Problem 1
            {
                //Execute Solution 1
                cout << "Solution to Gaddis 8th Ed. Chap6 Prob1" << endl;
                cout << "FALLING DISTANCE" << endl;
                solution1();
                //Exit Solution 1
                cout << endl;
                break;
            }
            case 2: //Solution to Problem 2
            {
                cout << "Solution to Gaddis 8th Ed. Chap6 Prob5" << endl;
                cout << "RETAIL MARKUP" << endl;
                //Execute Solution 2
                solution2();
                //Exit Solution 2
                cout << endl;
                break;
            }
            case 3: //Solution to Problem 3
            {
                cout << "Solution to Gaddis 8th Ed. Chap6 Prob8" << endl;
                cout << "COIN TOSS" << endl;
                //Execute Solution 3
                solution3();
                //Exit Solution 3
                cout << endl;
                break;
            }
            case 4: //Solution to Problem 4
            {
                cout << "Solution to Gaddis 8th Ed. Chap6 Prob12" << endl;
                cout << "STAR SEARCH" << endl;
                //Execute Solution 4
                solution4();
                //Exit Solution 4
                cout << endl;
                break;
            }
            case 5: //Solution to Problem 5
            {
                cout << "Solution to Gaddis 8th Ed. Chap6 Prob22" << endl;
                cout << "PRIME TEST" << endl;
                //Execute Solution 5
                solution5();
                //Exit Solution 5
                cout << endl;
                break;
            }
        }
    } while(choice  > 0 && choice < 6);
    
    //Exit Message
    cout << "Exiting program..." << endl;
    
    //Exit
    return 0;
}

/******************************************************************************/
/*******************************Solution 1*************************************/
/******************************************************************************/
void solution1(){
    //Calculate and Output results
    cout << fixed << setprecision(2) << showpoint;
    for(int i = 1; i <= 10; ++i){ //loop through times 1 second to 10 seconds
        cout << "If you fall for " << setw(2) << i << " seconds you will fall " 
             << setw(5) << falDist(i) << " meters." << endl;
    }
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 2*************************************/
/******************************************************************************/
void solution2(){
        //Declaration and Initialization
    short input; //The input number
    unsigned short whsCost, //The wholesale cost of the product
            mkUpPer; //The retail markup

    //Input Data
    do { //Input validation
        cout << "Enter the wholesale value of the item: $";
        cin >> input;
    } while (input < 0);
    whsCost = input; //Set wholesale cost
    do { //Input validation
        cout << "Enter the retail markup percentage:     ";
        cin >> input;
    } while (input < 0);
    mkUpPer = input; //Set mark up percentage
    
    //Calculate and Output Results
    cout << fixed << setprecision(2) << showpoint;
    cout << "The retail value is $" << calcRtl(whsCost, mkUpPer);

    //Exit
}

/******************************************************************************/
/*******************************Solution 3*************************************/
/******************************************************************************/
void solution3(){
    //Declaration and Initialization
    unsigned short totHead = 0, //The total number of heads
                   totTail = 0, //The total number of tails
                   tosses; //The number of tosses to perform
    srand(static_cast<int>(time(0))); //Seed PRNG
    
    //Input Data
    cout << "How many tosses would you like to preform: ";
    cin >> tosses;
    
    //Calculate Output
    for(int i = 0; i < tosses; ++i){ //Perform each toss
        cnToss() == 1 ? ++totHead : ++totTail; //increment the correct value per toss
    }
    
    //Output Results
    cout << "TOTAL HEADS:  " << totHead << endl; 
    cout << "TOTAL TAILS:  " << totTail << endl;
    cout << "TOTAL TOSSES: " << totHead + totTail << endl;
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 4*************************************/
/******************************************************************************/
void solution4(){
        //Declaration and Initialization
    const char JUDGES = 5; //The number of judges
    float scores[JUDGES]; //An array holding each judges score
    
    //Input Data
    gJdgDat(scores, JUDGES); //Fill the array with scores
    
    //Calculate and Output Results
    calcScr(scores, JUDGES); //Calculate the final score
    
    //Exit
}

/******************************************************************************/
/*******************************Solution 5*************************************/
/******************************************************************************/
void solution5(){
    //Declaration and Initialization
    int num; //The number to check the primacy of
    
    //Input Data
    cout << "Enter a number to test whether or not it is prime: ";
    cin >> num;
   
    //for(int num = 2; num <= 1000; ++num) //Uncomment to test some set numbers
    //Output Results
    cout << num << " IS " << (isPrime(num) ? "PRIME" : "NOT PRIME") << endl;
    
    //Exit
}

/******************************************************************************/
/********************************Is Prime**************************************/
/******************************************************************************/
//  Determine whether or not an integer is a prime number
//Input
//  chkNum : the number to check the primacy of
//Output
// true if the number cannot be divided evenly by anything other than one or itself
// false if the number can be divided evenly by something other than one or itself
bool isPrime(int chkNum){
    for(int i = 2; i < chkNum; ++i){ //loop through all numbers between 1 or chkNum exclusively
        if(chkNum % i == 0) { //if divisible return false
            cout << chkNum << " is divisible by " << i << endl;
            return false; 
        } 
    }
    
    //Otherwise return true
    return true;
}

/******************************************************************************/
/*******************************Falling Distance*******************************/
/******************************************************************************/
//  Calculate falling distance due to gravity on Earth from time
//Input
//  time : the time in seconds of the fall
//Output
//  distance : the distance of the fall in meters
float falDist(short time){
    return 0.5f * ACLGRAV * (time * time);
}

/******************************************************************************/
/*********************************Coin Toss************************************/
/******************************************************************************/
//  Perform a single coin toss
//Output
//  toss : the value of the toss as either 1 or a 2
char cnToss(){
    unsigned char toss = rand() % 2 + 1;
    cout << (toss == 1 ? "HEADS" : "TAILS") << endl;
    return toss;
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

/******************************************************************************/
/******************************Calculate Retail********************************/
/******************************************************************************/
//  Calculate the retail price of a product
//Input
//  whsCost : the wholesale cost of the product
//  mkUpPer : the mark up percentage
//Output
//  the price of the product after applying retail markup 
float calcRtl(unsigned short whsCost, unsigned short mkUpPer) {
    return whsCost * (1.0f + static_cast<float> (mkUpPer) / 100);
}