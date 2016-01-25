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

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    short choice; //The input choice
    
    do{ //Loop unless input choice is not a list value
        //Output Solution List
        cout << "SOULUTION LIST" << endl;
        cout << "1. Solution to Gaddis 8th Ed. Chap5 Prob10" << endl;
        cout << "2. Solution to Gaddis 8th Ed. Chap5 Prob12" << endl;
        cout << "3. Solution to Gaddis 8th Ed. Chap5 Prob17" << endl;
        cout << "4. Solution to Gaddis 8th Ed. Chap5 Prob19" << endl;
        cout << "5. Solution to Gaddis 8th Ed. Chap5 Prob2" << endl;
        cout << "6. Solution to Gaddis 8th Ed. Chap5 Prob20" << endl;
        cout << "7. Solution to Gaddis 8th Ed. Chap5 Prob22" << endl;
        cout << "8. Solution to Gaddis 8th Ed. Chap5 Prob23" << endl;
        cout << "9. Solution to Gaddis 8th Ed. Chap5 Prob7" << endl;
        cout << "10. Solution to Gaddis 8th Ed. Chap5 Prob9" << endl;
        //Read in your choice
        cout << "Enter your choice 1-10 or anything else to quit: ";
        cin >> choice;
        cout << endl;
        
        switch(choice){ //Solution Implementations
            case 1: //Solution to Problem 1
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob10" << endl;
                cout << "AVERAGE RAINFALL CALCULATOR" << endl;
                
                //Declaration and Initialization
                short years; //The number of years you have rainfall data on
                unsigned short cRnFl, //The current input rainfall
                        tRnFl, //The running total rainfall
                        aRnFl; //The average rainfall
                
                //Input Data
                do{ //Input Validation
                    //Read in years    
                    cout << "NUMBER OF YEARS IN DATA SET: ";
                    cin >> years;
                } while(years <= 0);
                
                cout << "Input each month of data for each year." << endl;
                cout << "All measurements in inches" << endl;
                //Read in rainfall for each month for each year
                for(int i = 0; i < years; ++i){ //Loop through each year
                    for(int j = 0; j < 12; ++j){ //Loop through each month
                        cout << "RAINFALL FOR MONTH " << j + 1 << " OF YEAR " << i + 1 
                                << ": ";
                        cin >> cRnFl;
                        //Add input rainfall to total rainfall
                        tRnFl += cRnFl;
                    }
                }
                
                //Calculate Output
                aRnFl = tRnFl / (12 * years);
                
                //Output Results
                cout << "TOTAL YEARS:      " << years << endl;
                cout << "TOTAL RAINFALL:   " << tRnFl << " inches" << endl;
                cout << "AVERAGE RAINFALL: " << aRnFl <<  " inches / month" << endl;
                
                //Exit
                cout << endl;
                break;
            }
            case 2: //Solution to Problem 2
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob12" << endl;
                cout << "Celsius to Fahrenheit Conversion Table" << endl;
                
                //Declaration and Initialization
                char intrcpt = 32; //Scaled by 9/5 degrees Celsius
                unsigned char c1 = 0, //The freezing point of water in Celsius
                        c2 = 100, //The boiling point of water in Celsius
                        f1 = 32, //The freezing point of water in Fahrenheit
                        f2 = 212; //The boiling point of water in Fahrenheit
                float slope = 5.0f/9.0f; //The slope of the line for temperature conversion
                
                //Loop to generate the degree Celsius and output table
                cout << "Fahrenheit   Celsius   Celsius" << endl; //Print table header
                cout << fixed << setprecision(2) << showpoint;
                for(int f = f1; f <= f2; ++f){
                    float ceq = slope * (f - intrcpt); //The conversion as a slope
                    float cintrp = c1 + static_cast<float>((f - f1)) / (f2 - f1) * (c2 - c1); //The conversion using interpolation
                    cout << setw(10) << f << setw(10) << ceq << setw(10) << cintrp << endl; //Output values
                }
                
                //Exit
                cout << endl;
                break;
            }
            case 3: //Solution to Problem 3
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob17" << endl;
                cout << "SALES BAR GRAPH" << endl;
                
                //Declaration and Initialization
                const char ax = '*'; //Character to use in graphing
                short st1Sls, //Store 1 Sales
                        st2Sls, //Store 2 Sales
                        st3Sls, //Store 3 Sales
                        st4Sls, //Store 4 Sales
                        st5Sls; //Store 5 Sales
                
                //Input Data
                cout << "All values are in whole dollars" << endl;
                //Read in store 1 data
                cout << "Enter today's sales for store 1: ";
                cin >> st1Sls;
                //Read in store 2 data
                cout << "Enter today's sales for store 2: ";
                cin >> st2Sls;
                //Read in store 3 data
                cout << "Enter today's sales for store 3: ";
                cin >> st3Sls;
                //Read in store 4 data
                cout << "Enter today's sales for store 4: ";
                cin >> st4Sls;
                //Read in store 5 data
                cout << "Enter today's sales for store 5: ";
                cin >> st5Sls;
                cout << endl;
                
                //Calculate and Output results
                //Graph Header
                cout << "SALES BAR CHART" << endl;
                cout << "(Each * = $100)" << endl;
                //Output Bar Graph
                cout << "Store 1: ";
                for(int i = 0; i < st1Sls / 100; ++i){ //Store 1 bar
                    cout << ax;
                }
                cout << endl;
                cout << "Store 2: ";
                for(int i = 0; i < st2Sls / 100; ++i){ //Store 2 bar
                    cout << ax;
                }
                cout << endl;
                cout << "Store 3: ";
                for(int i = 0; i < st3Sls / 100; ++i){ //Store 3 bar
                    cout << ax;
                }
                cout << endl;
                cout << "Store 4: ";
                for(int i = 0; i < st4Sls / 100; ++i){ //Store 4 bar
                    cout << ax;
                }
                cout << endl;
                cout << "Store 5: ";
                for(int i = 0; i < st5Sls / 100; ++i){ //Store 5 bar
                    cout << ax;
                }
                cout << endl;
                
                //Exit
                cout << endl;
                break;
            }
            case 4: //Solution to Problem 4
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob19" << endl;
                cout << "MONTHLY BUDGET AND EXPENSES CALCULATOR" << endl;
                
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
                cout << endl;
                break;
            }
            case 5: //Solution to Problem 5
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob2" << endl;
                cout << "ASCII TABLE 0-127" << endl;
                
                //Declaration and Initialization
                const unsigned char NUMCHAR = 128, //The number of character total to print
                        CHARROW = 16, //The number of characters per row
                        NUMROW = NUMCHAR / CHARROW; //The number of rows
                
                //Output Results
                //Table Header
                cout << "THE ASCII TABLE 0 to 127" << endl;
                //Table
                for(int i = 0; i < NUMROW; ++i){ //Output table rows
                    for(int curPos = 0; curPos < CHARROW; ++curPos){ //Output the current position in the table in one row
                        //Calculate the current position by adding the number of characters per row * the row + the position in the current row
                        cout << setw(4) << static_cast<int>(curPos + (CHARROW * i)) 
                                << " ";
                    }
                    cout << endl;
                    for(int curChar = 0; curChar < CHARROW; ++curChar){ //Output the current character
                        if(curChar + (CHARROW * i) < 32 || curChar + (CHARROW * i) == 127){ //If the current character is a non-printing character
                            switch(curChar + (CHARROW * i)){ //Convert nonprinting characters to string indicator
                                case 0:
                                {
                                    cout << setw(4) << "NUL" << " ";
                                    break;
                                }
                                case 1:
                                {
                                    cout << setw(4) << "SOH" << " ";
                                    break;
                                }
                                case 2:
                                {
                                    cout << setw(4) << "STX" << " ";
                                    break;
                                }
                                case 3:
                                {
                                    cout << setw(4) << "ETX" << " ";
                                    break;
                                }
                                case 4:
                                {
                                    cout << setw(4) << "EOT" << " ";
                                    break;
                                }
                                case 5:
                                {
                                    cout << setw(4) << "ENQ" << " ";
                                    break;
                                }
                                case 6:
                                {
                                    cout << setw(4) << "ACK" << " ";
                                    break;
                                }
                                case 7:
                                {
                                    cout << setw(4) << "BEL" << " ";
                                    break;
                                }
                                case 8:
                                {
                                    cout << setw(4) << "BS" << " ";
                                    break;
                                }
                                case 9:
                                {
                                    cout << setw(4) << "TAB" << " ";
                                    break;
                                }
                                case 10:
                                {
                                    cout << setw(4) << "LF" << " ";
                                    break;
                                }
                                case 11:
                                {
                                    cout << setw(4) << "VT" << " ";
                                    break;
                                }
                                case 12:
                                {
                                    cout << setw(4) << "FF" << " ";
                                    break;
                                }
                                case 13:
                                {
                                    cout << setw(4) << "CR" << " ";
                                    break;
                                }
                                case 14:
                                {
                                    cout << setw(4) << "SO" << " ";
                                    break;
                                }
                                case 15:
                                {
                                    cout << setw(4) << "SI" << " ";
                                    break;
                                }
                                case 16:
                                {
                                    cout << setw(4) << "DLE" << " ";
                                    break;
                                }
                                case 17:
                                {
                                    cout << setw(4) << "DC1" << " ";
                                    break;
                                }
                                case 18:
                                {
                                    cout << setw(4) << "DC2" << " ";
                                    break;
                                }
                                case 19:
                                {
                                    cout << setw(4) << "DC3" << " ";
                                    break;
                                }
                                case 20:
                                {
                                    cout << setw(4) << "DC4" << " ";
                                    break;
                                }
                                case 21:
                                {
                                    cout << setw(4) << "NAK" << " ";
                                    break;
                                }
                                case 22:
                                {
                                    cout << setw(4) << "SYN" << " ";
                                    break;
                                }
                                case 23:
                                {
                                    cout << setw(4) << "ETB" << " ";
                                    break;
                                }
                                case 24:
                                {
                                    cout << setw(4) << "CAN" << " ";
                                    break;
                                }
                                case 25:
                                {
                                    cout << setw(4) << "EM" << " ";
                                    break;
                                }
                                case 26:
                                {
                                    cout << setw(4) << "SUB" << " ";
                                    break;
                                }
                                case 27:
                                {
                                    cout << setw(4) << "ESC" << " ";
                                    break;
                                }
                                case 28:
                                {
                                    cout << setw(4) << "FS" << " ";
                                    break;
                                }
                                case 29:
                                {
                                    cout << setw(4) << "GS" << " ";
                                    break;
                                }
                                case 30:
                                {
                                    cout << setw(4) << "RS" << " ";
                                    break;
                                }
                                case 31:
                                {
                                    cout << setw(4) << "US" << " ";
                                    break;
                                }
                                case 127:
                                {
                                    cout << setw(4) << "DEL" << " ";
                                    break;
                                }
                                
                                
                            }
                        }
                        else { //Output a printable character
                            cout << setw(4) << static_cast<char>(curChar + (CHARROW * i)) << " ";
                        }
                    }
                    cout << endl;    
                }
                
                //Exit
                cout << endl;
                break;
            }
            case 6: //Solution to Problem 6
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob20" << endl;
                cout << "RANDOM NUMBER GUESSING GAME" << endl;
                
                //Declaration and Initialization
                short gsNum, //The number the player needs to guess
                        inGsNum; //The number that player has guessed
                
                srand(static_cast<int>(time(0))); //Initialize PRNG
                
                gsNum = rand() % 101; //Generate a random number to guess
                
                cout << "Random Number Guessing Game" << endl;
                do{ //Loop till the player wins
                    //Input Data
                    //Read in the player's guess
                    cout << "Guess a number: ";
                    cin >> inGsNum;
                    
                    //Output if higher or lower
                    if(inGsNum < gsNum){ //Guess is lower than the answer
                        cout << "Too low, try again." << endl;
                    }
                    else if (inGsNum > gsNum){ //Guess is higher than the answer
                        cout << "Too high, try again." << endl;
                    }
                    
                } while(inGsNum != gsNum);
                
                //Output winning text
                cout << "You got it!" << endl;    
                
                //Exit
                cout << endl;
                break;
            }
            case 7: //Solution to Problem 7
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob22" << endl;
                cout << "SQUARE DISPLAY" << endl;
                
                //Declaration and Initialization
                const char X = 'X'; //The character to use for the box
                unsigned short sideLn; //The length of the sides of the box
                
                //Input Data
                do{ //Input Validation
                    //Read in side length  
                    cout << "How long should each side be? ";
                    cin >> sideLn;
                } while (sideLn > 15);
                
                //Output the box
                for(int i = 0; i < sideLn; ++i){ //print box columns
                    for(int j = 0; j < sideLn; ++j){ //print box rows
                        cout << X;
                    }
                    cout << endl;
                }
                
                //Exit
                cout << endl;
                break;
            }
            case 8: //Solution to Problem 8
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob23" << endl;
                cout << "ASCENDING AND DESCENDING PATTERNS" << endl;
                
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
                cout << endl;
                break;
            }
            case 9: //Solution to Problem 9
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob7" << endl;
                cout << "SALARY TABLE" << endl;
                
                //Declaration and Initialization
                unsigned int salary = 1; //Salary Starting at a penny
                float tPay = salary; //Total pay in dollars by summing salaries
                
                //Input Data
                
                //Loop to generate the Salary Table and Total Paid
                cout << fixed << setprecision(2) << showpoint;
                cout << " Day   Salary($)       Total($)" << endl;
                cout << setw(4) << 1 << setw(15) << salary / 100.0f 
                        << setw(15) << tPay / 100.0f << endl;
                for(int day = 2; day <= 31; ++day){
                    salary *= 2;
                    //salary <<= 1; //Bitwise Right Shift equivalent to * 2
                    tPay += salary;
                    cout << setw(4) << day << setw(15) << salary / 100.0 
                            << setw(15) << tPay / 100.0 << endl;
                }
                //Output Results
                
                //Exit
                cout << endl;
                break;
            }
            case 10: //Solution to Problem 10
            {
                //Problem Information
                cout << "Solution to Gaddis 8th Ed. Chap5 Prob9" << endl;
                cout << "HOTEL SIZE CALCULATOR" << endl;
                //Declaration and Initialization
                unsigned short numFlrs, //The number of floors in the hotel
                        numRms, //The number of rooms in the current floor
                        totRms; //The running total of rooms
                
                //Input Data
                //Read in the number of floors
                cout << "How many floors are in your hotel? ";
                cin >> numFlrs;
                
                for(int i = 0; i < numFlrs; ++i){ //Read in the number of rooms for each floor
                    //Read in the rooms on the current floor
                    cout << "How many rooms are on floor " << i + 1 << "? ";
                    cin >> numRms;
                    //Calculate new total rooms
                    totRms += numRms;
                }
                
                //Output Results
                cout << "NUMBER OF FLOORS: " << numFlrs << endl;
                cout << "TOTAL ROOMS:      " << totRms << endl;
                
                //Exit
                cout << endl;
                break;
            }
        }
    } while(choice  > 0 && choice < 11);
    
    //Exit Message
    cout << "Exiting program..." << endl;
    
    //Exit
    return 0;
}

