/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Menu
 * Created on January 19, 2016, 8:31 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declaration and Initialization
    bool reDsply = true; //Redisplay menu or exit when false
    unsigned short nSltn; //Problem solution to display
    
    //Menu to display solution
    do {
        //Read in problem to display
        cout << "Assignment 3 Problem Set" << endl;
        cout << "Type 1 to display Savitch 8th Ed. Chap 3 Prob 10" << endl;
        cout << "Type 2 to display Savitch 8th Ed. Chap 3 Prob 11" << endl;
        cout << "Type 3 to display Savitch 8th Ed. Chap 3 Prob 3" << endl;
        cout << "Type 4 to display Savitch 7th Ed. Chap 3 Prob 1" << endl;
        cout << "Type 5 to display Gaddis 8th Ed. Chap 4 Prob 4" << endl;
        cout << "Type 6 to display Gaddis 8th Ed. Chap 4 Prob 23" << endl;
        cout << "Type 7 to display Gaddis 8th Ed. Chap 4 Prob 16" << endl;
        cout << "Type 8 to display Gaddis 8th Ed. Chap 4 Prob 13" << endl;
        cout << "Type 9 to display Gaddis 8th Ed. Chap 4 Prob 12" << endl;
        cout << "Type 10 to display Gaddis 8th Ed. Chap 4 Prob 11" << endl;
        cout << "Type anything else to exit" << endl;
        cout << "SOLUTION: ";
        cin >> nSltn;
        cout << endl;
        
        switch (nSltn) {
            case 1:
            {
                //Savitch 8th Edition Chapter 3 Problem 10
                //Solution is only precise to 47 terms or 235 days
                //Declaration and Initialization
                const unsigned char DYSREP = 5; //The number of days to reproduce crud
                unsigned short nDays, //The number of days to allow crud reproduction
                        nTerms; //The number of fibonnaci terms to generate
                unsigned int nFib, //The current number in the sequence
                        nLast, //The last number in the sequence
                        temp; //Temporary value used to hold the last number during calculation
                float crdWght; //The weight of the crud in pounds
                
                //Problem Information
                cout << "Solution to Problem Savitch 8th Ed. Chap3 Prob10" << endl;
                cout << "THE FIBONNACI SEQUENCE" << endl;
                
                //Input Data
                cout << "Input a number of days for crud production: ";
                cin >> nDays;
                cout << "Input the current weight of the crud in pounds: ";
                cin >> crdWght;
                
                //Calculate and output terms
                nTerms = (nDays / DYSREP) + 1; //Convert days to the sequence terms
                cout << "FIBONNACI SEQUENCE TERMS:" << endl;
                for (int i = 0; i < nTerms; ++i) {
                    //Initial values
                    if (i == 0) {
                        nFib = 1;
                        nLast = 0;
                    }            
                    //Calculate next term
                    else {
                        temp = nFib;
                        nFib = nFib + nLast;
                        nLast = temp;
                    }
                    //Output current term
                    cout << nFib;
                    if (i < nTerms - 1) { //Print a comma between terms except the final term
                        cout << ", ";
                    }
                    if (i % 10 == 0 && i != 0) { //Print a new line every 10 terms
                        cout << endl;
                    }
                }
                cout << endl;
                cout << "CRUD WEIGHT AFTER " << nDays << " DAYS: " 
                        << crdWght * nFib << " pounds" << endl;
                cout << endl << endl;
                
                //Exit Solution 1
                break;
            }
            case 2:
            {
                //Savitch 8th Ed. Chap 3 Prob 11
                //Declaration and Initialization
                const unsigned char NTERMS = 13;
                unsigned int factN = 1; //The factorial of n
                float eToX = 1, //e^x
                        x; //The number to raise e to
                
                //Problem Information
                cout << "Solution to Savitch 8th Ed. Chap3 Prob11" << endl;
                cout << "Calculate e^x" << endl;
                
                //Input Data
                //Read in x
                cout << "NUMBERS MUST BE BETWEEN 1 AND 13" << endl;
                cout << "Input the number to calculate e to the power of: ";
                cin >> x;
                
                //Calculate Results
                for (int n = 1; n <= NTERMS; ++n) {
                    factN *= n; //Calculate factorial
                    eToX += pow(x, n) / factN; //Calculate e^x
                }
                
                //Output Results
                cout << "EXACT VALUE OF e^" << x << ": " << exp(x) << endl;
                cout << "APPROXIMATE VALUE OF e^" << x << ": " << eToX << endl;
                cout << endl;
                
                //Exit Solution 2
                break;
            }
            case 3:
            {
                //Savitch 8th Ed. Chap 3 Prob 3
                //Declaration and Initialization
                unsigned char n1000s, //Number of 1000s
                        n100s, //Number of 100s
                        n10s, //Number of 10s
                        n1s; //Number of 1s
                unsigned short cNum, //Number to Convert
                        temp; //Hold he value of the first part of each calculation
                
                srand(static_cast<int> (time(0))); //Seed PRNG
                cNum = rand() % 2001 + 1000; //Get a new number to convert
                
                //Problem Information
                cout << "Solution to Savitch 9th Ed. Chap3 Prob3" << endl;
                cout << "The Roman Number Conversion Program" << endl;
                
                //Calculate Output
                //Output original number
                cout << "THE NUMBER TO CONVERT: " << cNum << endl;
                //Calculate the number in each place
                //Calculate 1000s
                temp = cNum - cNum % 1000;
                n1000s = temp / 1000;
                cNum -= temp;
                //Calculate 100s
                temp = cNum - cNum % 100;
                n100s = temp / 100;
                cNum -= temp;
                //Calculate 100s
                temp = cNum - cNum % 10;
                n10s = temp / 10;
                cNum -= temp;
                //Calculate 1s
                n1s = cNum;
                
                //Output Results
                //Output the number in each place of our original number
                cout << "NUMBER OF 1000S: " << static_cast<int> (n1000s) << endl;
                cout << "NUMBER OF 100S:  " << static_cast<int> (n100s) << endl;
                cout << "NUMBER OF 10S:   " << static_cast<int> (n10s) << endl;
                cout << "NUMBER OF 1S:    " << static_cast<int> (n1s) << endl;
                cout << "THE ROMAN NUMERAL EQUIVALENT: ";
                switch (n1000s) { //Output 1000s
                    case 3: { cout << 'M'; }
                    case 2: { cout << 'M'; }
                    case 1: { cout << 'M'; }
                }
                switch (n100s) { //Output 100s
                    case 9:
                    {
                        cout << "CM";
                        break;
                    }
                    case 8:
                    {
                        cout << "DCCC";
                        break;
                    }
                    case 7:
                    {
                        cout << "DCC";
                        break;
                    }
                    case 6:
                    {
                        cout << "DC";
                        break;
                    }
                    case 5:
                    {
                        cout << 'D';
                        break;
                    }
                    case 4:
                    {
                        cout << "CD";
                        break;
                    }
                    case 3: { cout << 'C'; }
                    case 2: { cout << 'C'; }
                    case 1: { cout << 'C'; }
                }
                switch (n10s) { //Output 10s
                    case 9:
                    {
                        cout << "XC";
                        break;
                    }
                    case 8:
                    {
                        cout << "LXXX";
                        break;
                    }
                    case 7:
                    {
                        cout << "LXX";
                        break;
                    }
                    case 6:
                    {
                        cout << "LX";
                        break;
                    }
                    case 5:
                    {
                        cout << 'L';
                        break;
                    }
                    case 4:
                    {
                        cout << "XL";
                        break;
                    }
                    case 3: { cout << 'X'; }
                    case 2: { cout << 'X'; }
                    case 1: { cout << 'X'; }
                }
                switch (n1s) { //Output 1s
                    case 9:
                    {
                        cout << "IX";
                        break;
                    }
                    case 8:
                    {
                        cout << "VIII";
                        break;
                    }
                    case 7:
                    {
                        cout << "VII";
                        break;
                    }
                    case 6:
                    {
                        cout << "VI";
                        break;
                    }
                    case 5:
                    {
                        cout << 'V';
                        break;
                    }
                    case 4:
                    {
                        cout << "IV";
                        break;
                    }
                    case 3: { cout << 'I'; }
                    case 2: { cout << 'I'; }
                    case 1: { cout << 'I'; }
                }
                cout << endl << endl; //End line
                
                //Exit Solution 3
                break;
            }
            case 4:
            {
                //Savitch 7th Ed. Chap3 Prob1
                //Declaration and Initialization
                char comp, //The CPUs choice for this turn
                        player, //The player's choice for this turn
                        qstion; //Does the player want to continue playing?
                unsigned short pScore = 0, //The player's score
                        cScore = 0; //The computer's score
                
                srand(static_cast<int> (time(0))); //Seed the random number generator
                
                //Problem Information
                cout << "Solution to Savitch 7th Ed. Chap3 Prob1" << endl;
                cout << "The ROCK-PAPER-SCISSORS Game" << endl;
                
                //Input Data
                do {
                    //Read Player input
                    do {
                        cout << "What is your move P, R, S? ";
                        cin >> player;
                        player = toupper(player);
                    } while (!(player == 'P' || player == 'R' || player == 'S'));
                    
                    //Computer Generated Play
                    do {
                        comp = rand() % 4 + 80;
                    } while (comp == 'Q');
                    
                    //Output Results
                    //Output the moves by the computer and player
                    cout << "The computer played: " << comp << endl;
                    cout << "The player played:   " << player << endl;
                    //Determine results
                    if (player == comp) {
                        cout << "RESULT: TIE!!" << endl;
                    } else if ((player == 'P' && comp == 'R') || (player == 'R' && comp == 'S')
                            || (player == 'S' && comp == 'P')) {
                        cout << "RESULT: PLAYER WINS!!" << endl;
                        ++pScore;
                    } else {
                        cout << "RESULT: COMPUTER WINS!!" << endl;
                        ++cScore;
                    }
                    //Show Scores
                    cout << "PLAYER SCORE:   " << pScore << endl;
                    cout << "COMPUTER SCORE: " << cScore << endl;
                    //Keep playing?
                    cout << "Quit Playing? (Y/N) ";
                    cin >> qstion;
                    qstion = toupper(qstion);
                    cout << endl;
                } while (qstion != 'Y');
                
                //Exit Solution 4
                break;
            }
            case 5:
            {
                //Gaddis 8th Ed. Chap4 Prob4
                //Declaration and Initialization
                unsigned short r1Wdth, //The width of the first rectangle
                        r2Wdth, //The width of the second rectangle
                        r1Lngth, //The length of the first rectangle
                        r2Lngth; //The length of the second rectangle
                unsigned int r1Area, //The area of the first rectangle
                        r2Area; //The area of the second rectangle
                
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap4 Prob4" << endl;
                cout << "Calculate and compare the area of two rectangles" << endl;
                
                //Input Data
                //Read in the width of the first rectangle
                cout << "Input the width of the first rectangle: ";
                cin >> r1Wdth;
                //Read in the length of the first rectangle
                cout << "Input the length of the first rectangle: ";
                cin >> r1Lngth;
                //Read in the width of the second rectangle
                cout << "Input the width of the second rectangle: ";
                cin >> r2Wdth;
                //Read in the length of second rectangle
                cout << "Input the length of the second rectangle: ";
                cin >> r2Lngth;
                
                //Calculate Output
                //Calculate the area of the first rectangle
                r1Area = r1Wdth * r1Lngth;
                //Calculate the area of the second rectangle
                r2Area = r2Wdth * r2Lngth;
                
                //Output Results
                cout << "The area of rectangle 1 is: " << r1Area << endl;
                cout << "The area of rectangle 2 is: " << r2Area << endl;
                //Output which rectangle has the largest area
                cout << "The area of rectangle 1 is " 
                        << ((r1Area > r2Area) ? "greater than " : (r1Area < r2Area) 
                        ? "less than " : "equal to ") << "the area of rectangle 2." << endl;
                cout << endl;
                
                //Exit Solution 5
                break;
            }
            case 6:
            {
                //Gaddis 8th Ed. Chap4 Prob23
                //Declaration and Initialization
                const float PI = atan(1) * 4;
                unsigned short choice; //The choice of mode for the calculator
                float radius, //The radius of a cirle
                        base, //The base of a triange or width of a rectangle
                        height; //The height of a triangle or length of a rectangle
                
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap4 Prob23" << endl;
                cout << "Calculator for the Area of Shapes" << endl;
                
                do { //Loop if the user doesn't want to quit
                    //Input a mode choice
                    cout << "Geometry Calculator" << endl;
                    cout << "1. Calculate the Area of a Circle" << endl;
                    cout << "2. Calculate the Area of a Rectangle" << endl;
                    cout << "3. Calculate the Area of a Triangle" << endl;
                    cout << "4. Quit" << endl;
                    do { //Input Validation
                        cout << "Enter your choice (1-4): ";
                        cin >> choice;
                    } while (choice < 0 && choice > 4);
                    cout << fixed << setprecision(4) << showpoint;
                    //Switch between modes
                    switch(choice){
                        case 1: //Circle Mode
                        {
                            //Input Radius
                            cout << "Enter the radius of the circle: ";
                            cin >> radius;
                            //Calculate and Output Results
                            cout << "AREA: " << PI * (radius * radius) << endl;
                            break;
                        }
                        case 2: //Rectangle Mode
                        {   
                            //Input width
                            cout << "Enter the width of the rectangle: ";
                            cin >> base;
                            //Input length
                            cout << "Enter the length of the rectangle: ";
                            cin >> height;
                            //Calculate and Output Results
                            cout << "AREA: " << base * height << endl;
                            break;
                        }  
                        case 3: //Triangle Mode
                        {
                            //Input base
                            cout << "Enter the base of the triangle: ";
                            cin >> base;
                            //Input height
                            cout << "Enter the height of the triangle: ";
                            cin >> height;
                            //Calculate and Output Results
                            cout << "AREA: " << base * height * 0.5f << endl;
                            break;
                        }
                    }
                } while (choice != 4);
                cout << endl;
                
                //Exit Solution 6
                break;
            }
            case 7:
            {
                //Gaddis 8th Ed. Chap4 Prob16
                //Declaration and Initialization
                string name1, //The name of the first runner
                        name2, //The name of the second runner
                        name3; //The name of the third runner
                
                float time1, //The first runner's time
                        time2, //The second runner's time
                        time3; //The third runner's time
                
                //Problem Information
                cout << "Solution Gaddis 8th Ed. Chap4 Prob16" << endl;
                cout << "Race Winner Calculator" << endl;
                
                //Input Data
                //Read in name1
                cout << "Enter the first runner's name: ";
                cin >> name1;
                //Read in name2
                cout << "Enter the second runner's name: ";
                cin >> name2;
                //Read in name3
                cout << "Enter the third runner's name: ";
                cin >> name3;
                
                cout << "All times are in seconds." << endl;
                do{ //Input Validation loop
                    //Read in time1
                    cout << "Enter the first runner's time: ";
                    cin >> time1;
                    //Read in time2
                    cout << "Enter the second runner's time: ";
                    cin >> time2;
                    //Read in time3
                    cout << "Enter the third runner's time: ";
                    cin >> time3;
                } while (time1 < 0 || time2 < 0 || time3 < 0);
                
                //Calculate and Output Results
                //If times are all equal runners win in order of input
                if(time1 <= time2 && time1 <= time3){ //If time1 is the lowest
                    cout << "FIRST PLACE:  " << name1 << endl;
                    if(time2 <= time3){ //If time2 is less than time3
                        cout << "SECOND PLACE: " << name2 << endl;
                        cout << "THIRD PLACE:  " << name3 << endl;
                    }
                    else{ //If time3 is less than time2
                        cout << "SECOND PLACE: " << name3 << endl;
                        cout << "THIRD PLACE:  " << name2 << endl;
                    }
                }
                else if(time2 <= time1 && time2 <= time3) { //If time2 is the lowest
                    cout << "FIRST PLACE:  " << name2 << endl;
                    if(time1 <= time3){ //If time1 is less than time3 
                        cout << "SECOND PLACE: " << name1 << endl;
                        cout << "THIRD PLACE:  " << name3 << endl;
                    }
                    else{ //If time3 is less than time1
                        cout << "SECOND PLACE: " << name3 << endl;
                        cout << "THIRD PLACE:  " << name1 << endl;
                    }
                }
                else if (time3 <= time1 && time3 <= time2){ //If time3 is the lowest
                    cout << "FIRST PLACE:  " << name3 << endl;
                    if(time1 <= time2){ //If time1 is less than time2
                        cout << "SECOND PLACE: " << name1 << endl;
                        cout << "THIRD PLACE:  " << name2 << endl;
                    }
                    else{ //If time2 is less than time1
                        cout << "SECOND PLACE: " << name2 << endl;
                        cout << "THIRD PLACE:  " << name1 << endl;
                    }
                    
                }
                cout << endl;
                
                //Exit Solution 7
                break;
            }
            case 8:
            {
                //Gaddis 8th Ed. Chap4 Prob13
                //Declaration and Initialization
                const unsigned char PNTT1 = 5, //Points for tier 1
                        PNTT2 = 15, //Points for tier 2
                        PNTT3 = 30, //Points for tier 3
                        PNTT4 = 60; //Points for tier 4
                unsigned char points; //The number of points earned
                unsigned short purBook; //The number of books purchased
                
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap4 Prob13" << endl;
                cout << "Book Club Points" << endl;
                
                //Input Data
                cout << "How many books did you purchase this month? ";
                cin >> purBook;
                
                //Calculate Output
                if(purBook < 1){ //If 0 books were purchased
                    points = 0;
                }
                else if(purBook < 2){ //If 1 book was purchased
                    points = PNTT1;
                }
                else if(purBook < 3){ //If 2 books were purchased
                    points = PNTT2;
                }
                else if(purBook < 4){ //If 3 books were purchased
                    points = PNTT3;
                }
                else{ //If 4 or more books were purchased
                    points = PNTT4;
                }
                
                //Output Results
                cout << "BOOKS PURCHASED: " << purBook << endl;
                cout << "POINTS EARNED:   " << static_cast<int>(points) << endl;
                cout << endl;
                
                //Exit Solution 8
                break;
            }
            case 9:
            {
                //Gaddis 8th Ed. Chap4 Prob12
                //Declaration and Initialization
                const unsigned short PRICE = 99; //The price of 1 unit of software in dollars
                const float DSCT1 = 0.2f, //The first discount tier
                        DSCT2 = 0.3f, //The second discount tier
                        DSCT3 = 0.4f, //The third discount tier
                        DSCT4 = 0.5f; //The fourth discount tier
                unsigned short qSftwr, //The quantity of software being bought
                        total; //The total price after the discount
                float dsc; //The discount for the quantity being purchased
                
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap4 Prob12" << endl;
                cout << "Software Purchase Discount Calculator" << endl;
                
                //Input Data
                do{ //Input Validation
                    cout << "How much software are you purchasing? ";
                    cin >> qSftwr;
                } while(qSftwr < 0);
                
                //Calculate Output
                if (qSftwr < 10){ //If the quantity is less than 10
                    dsc = 0.0f;
                }
                else if (qSftwr < 20){ //If the quantity is less than 20
                    dsc = DSCT1;
                }
                else if (qSftwr < 50){ //If the quantity is less than 50
                    dsc = DSCT2;
                }
                else if (qSftwr < 100){ //If the quantity is less than 100
                    dsc = DSCT3;
                }
                else{ //If the quantity is 100 or more
                    dsc = DSCT4;
                }
                
                //Calculate the total price
                total = (PRICE * qSftwr) - ((PRICE * qSftwr) * dsc);
                
                //Output Results
                cout << "SUBTOTAL: $" << PRICE * qSftwr << endl;
                cout << "DISCOUNT:  " << dsc * 100 << "%" << endl;
                cout << "TOTAL:    $" << total << endl; 
                cout << endl;
                
                //Exit Solution 9
                break;
            }
            case 10:
            {
                //Gaddis 8th Ed. Chap4 Prob11
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
                cout << "Solution to Gaddis 8th Ed. Chap4 Prob11" << endl;
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
                cout << endl;
                
                //Exit Solution 10
                break;
            }
            default:
            {
                cout << "Exiting the program..." << endl;
                reDsply = false;
            }
        }
        
    } while (reDsply);
    
    //Exit
    return 0;
}


