/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Claculate book club points
 * Created on January 19, 2016, 8:14 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Executions
int main(int argc, char** argv) {
    //Declaration and Initialization
    const unsigned char PNTT1 = 5, //Points for tier 1
                        PNTT2 = 15, //Points for tier 2
                        PNTT3 = 30, //Points for tier 3
                        PNTT4 = 60; //Points for tier 4
    unsigned char points; //The number of points earned
    unsigned short purBook; //The number of books purchased
    
    //Problem Information
    cout << "Gaddis 8th Ed. Chap4 Prob13" << endl;
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
    
    //Exit
    return 0;
}

