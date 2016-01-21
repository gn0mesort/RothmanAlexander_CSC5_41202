/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Find the best time of 3 times
 * Created on January 20, 2016, 9:13 PM
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    string name1,
            name2,
            name3,
            winner;
    
    float time1,
            time2,
            time3,
            max = 0.0f;
    
    cout << "Enter the first runner's name: ";
    cin >> name1;
    cout << "Enter the second runner's name: ";
    cin >> name2;
    cout << "Enter the third runner's name: ";
    cin >> name3;
    
    cout << "All times are in seconds." << endl;
    do{
        cout << "Enter the first runner's time: ";
        cin >> time1;
        cout << "Enter the second runner's time: ";
        cin >> time2;
        cout << "Enter the third runner's time: ";
        cin >> time3;
    } while (time1 < 0 || time2 < 0 || time3 < 0);
    
    if(time1 <= time2 && time1 <= time3){
        cout << "FIRST PLACE:  " << name1 << endl;
        if(time2 <= time3){
            cout << "SECOND PLACE: " << name2 << endl;
            cout << "THIRD PLACE:  " << name3 << endl;
        }
        else{
            cout << "SECOND PLACE: " << name3 << endl;
            cout << "THIRD PLACE:  " << name2 << endl;
        }
    }
    else if(time2 <= time1 && time2 <= time3) {
        cout << "FIRST PLACE:  " << name2 << endl;
        if(time1 <= time3){
            cout << "SECOND PLACE: " << name1 << endl;
            cout << "THIRD PLACE:  " << name3 << endl;
        }
        else{
            cout << "SECOND PLACE: " << name3 << endl;
            cout << "THIRD PLACE:  " << name1 << endl;
        }
    }
    else if (time3 <= time1 && time3 <= time2){
        cout << "FIRST PLACE:  " << name3 << endl;
        if(time1 <= time2){
           cout << "SECOND PLACE: " << name1 << endl;
           cout << "THIRD PLACE:  " << name2 << endl;
        }
        else{
            cout << "SECOND PLACE: " << name2 << endl;
            cout << "THIRD PLACE:  " << name1 << endl;
        }
        
    }
    
    return 0;
}

