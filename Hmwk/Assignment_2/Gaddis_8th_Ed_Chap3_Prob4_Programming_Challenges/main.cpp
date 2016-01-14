/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on January 14, 2016, 1:04 PM
 */

#include <iostream>


using namespace std;

int main(int argc, char** argv) {
    float month1, 
          month2, 
          month3,
          average;
    string mtName1,
           mtName2,
           mtName3;
    
    cout << "Enter the first month's name: ";
    cin >> mtName1;
    cout << "How much rain fell in " << mtName1 << " in inches? ";
    cin >> month1;
    
    cout << "Enter the second month's name: ";
    cin >> mtName2;
    cout << "How much rain fell in " << mtName2 << " in inches? ";
    cin >> month2;
    
    cout << "Enter the third month's name: ";
    cin >> mtName3;
    cout << "How much rain fell in " << mtName3 << " in inches? ";
    cin >> month3;
    
    average = (month1 + month2 + month3) / 3;
    
    cout << "RAINFALL FOR " << mtName1 << ": " << month1 << " inches" << endl;
    cout << "RAINFALL FOR " << mtName2 << ": " << month2 << " inches" << endl;
    cout << "RAINFALL FOR " << mtName3 << ": " << month3 << " inches" << endl;
    cout << "AVERAGE RAINFUL: " << average << " inches" << endl;
    
    
    return 0;
}

