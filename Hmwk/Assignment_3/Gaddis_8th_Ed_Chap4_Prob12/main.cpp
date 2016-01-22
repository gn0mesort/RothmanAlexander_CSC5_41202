/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Apply discounts to software sales
 * Created on January 19, 2016, 7:56 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//GLobal Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
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
    cout << "Gaddis 8th Ed Chap4 Prob12" << endl;
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
    
    //Exit
    return 0;
}

