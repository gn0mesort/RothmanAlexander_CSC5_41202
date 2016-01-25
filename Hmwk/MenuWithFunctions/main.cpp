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
void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();

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
                //Execute Solution 1
                solution1();
                //Exit Solution 1
                cout << endl;
                break;
            }
            case 2: //Solution to Problem 2
            {
                //Execute Solution 2
                solution2();
                //Exit Solution 2
                cout << endl;
                break;
            }
            case 3: //Solution to Problem 3
            {
                //Execute Solution 3
                solution3();
                //Exit Solution 3
                cout << endl;
                break;
            }
            case 4: //Solution to Problem 4
            {
                //Execute Solution 4
                solution4();
                //Exit Solution 4
                cout << endl;
                break;
            }
            case 5: //Solution to Problem 5
            {
                //Execute Solution 5
                solution5();
                //Exit Solution 5
                cout << endl;
                break;
            }
            case 6: //Solution to Problem 6
            {
                //Execute Solution 6
                solution6();
                //Exit Solution 6
                cout << endl;
                break;
            }
            case 7: //Solution to Problem 7
            {
                //Execute Solution 7
                solution7();
                //Exit Solution 7
                cout << endl;
                break;
            }
            case 8: //Solution to Problem 8
            {
                //Execute Solution 8
                solution8();
                //Exit Solution 8
                cout << endl;
                break;
            }
            case 9: //Solution to Problem 9
            {
                //Execute Solution 9
                solution9();
                //Exit Solution 9
                cout << endl;
                break;
            }
            case 10: //Solution to Problem 10
            {
                //Execute Solution 10
                solution10();
                //Exit Solution 10
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

/******************************************************************************/
/*******************************Solution 1*************************************/
/******************************************************************************/
void solution1(){
    
}

/******************************************************************************/
/*******************************Solution 2*************************************/
/******************************************************************************/
void solution2(){
    
}

/******************************************************************************/
/*******************************Solution 3*************************************/
/******************************************************************************/
void solution3(){
    
}

/******************************************************************************/
/*******************************Solution 4*************************************/
/******************************************************************************/
void solution4(){
    
}

/******************************************************************************/
/*******************************Solution 5*************************************/
/******************************************************************************/
void solution5(){
    
}

/******************************************************************************/
/*******************************Solution 6*************************************/
/******************************************************************************/
void solution6(){
    
}

/******************************************************************************/
/*******************************Solution 7*************************************/
/******************************************************************************/
void solution7(){
    
}

/******************************************************************************/
/*******************************Solution 8*************************************/
/******************************************************************************/
void solution8(){
    
}

/******************************************************************************/
/*******************************Solution 9*************************************/
/******************************************************************************/
void solution9(){
    
}

/******************************************************************************/
/*******************************Solution 10************************************/
/******************************************************************************/
void solution10(){
    
}