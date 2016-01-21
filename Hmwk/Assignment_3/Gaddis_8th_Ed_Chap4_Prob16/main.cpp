/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Find the best time of 3 times
 * Created on January 20, 2016, 9:13 PM
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
    string name1, //The name of the first runner
           name2, //The name of the second runner
           name3; //The name of the third runner
    
    float time1, //The first runner's time
          time2, //The second runner's time
          time3; //The third runner's time
    
    //Problem Information
    cout << "Gaddis 8th Ed. Chap4 Prob16" << endl;
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
    
    //Exit
    return 0;
}

