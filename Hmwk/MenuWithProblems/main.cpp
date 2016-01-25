/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: A template program for menus
 * Created on January 24, 2016, 5:53 PM
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
    short choice; //The input choice
    
    do{ //Loop unless input choice is not a list value
        //Output Solution List
        cout << "SOULUTION LIST" << endl;
        cout << "1. Solution to Problem 1" << endl;
        cout << "2. Solution to Problem 2" << endl;
        cout << "3. Solution to Problem 3" << endl;
        cout << "4. Solution to Problem 4" << endl;
        cout << "5. Solution to Problem 5" << endl;
        cout << "6. Solution to Problem 6" << endl;
        cout << "7. Solution to Problem 7" << endl;
        cout << "8. Solution to Problem 8" << endl;
        cout << "9. Solution to Problem 9" << endl;
        cout << "10. Solution to Problem 10" << endl;
        //Read in your choice
        cout << "Enter your choice 1-10 or anything else to quit: ";
        cin >> choice;
        cout << endl;
                
        switch(choice){ //Solution Implementations
            case 1: //Solution to Problem 1
            {
                cout << endl;
                break;
            }
            case 2: //Solution to Problem 2
            {
                cout << endl;
                break;
            }
            case 3: //Solution to Problem 3
            {
                cout << endl;
                break;
            }
            case 4: //Solution to Problem 4
            {
                cout << endl;
                break;
            }
            case 5: //Solution to Problem 5
            {
                cout << endl;
                break;
            }
            case 6: //Solution to Problem 6
            {
                cout << endl;
                break;
            }
            case 7: //Solution to Problem 7
            {
                cout << endl;
                break;
            }
            case 8: //Solution to Problem 8
            {
                cout << endl;
                break;
            }
            case 9: //Solution to Problem 9
            {
                cout << endl;
                break;
            }
            case 10: //Solution to Problem 10
            {
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

