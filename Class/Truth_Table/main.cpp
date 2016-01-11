/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: To display a truth table and compare swaps
 * Created on January 11, 2016, 8:57 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Declare and Initialize variables
    bool x = true,
         y = true;
    
    //Create Heading
    cout << "Truth Table:" << endl;
    cout << "X Y !X !Y X && Y X || Y X ^ Y (X ^ Y) ^ Y (X ^ Y) ^ X !(X && Y)"
         <<"!X || !Y !(X || Y) !X && !Y" << endl;
    
    //First Line
    cout << (x ? 'T' : 'F') << " " << (y ? 'T' : 'F') << "  "
         << (!x ? 'T' : 'F') << "  " << (!y ? 'T' : 'F') << "   "
         << (x && y ? 'T' : 'F') << "      "
         << (x || y ? 'T' : 'F') << "      "
         << (x ^ y ? 'T' : 'F') << "          "
         << ((x ^ y) ^ y ? 'T' : 'F') << "           "
         << ((x ^ y) ^ x ? 'T' : 'F') << "        "
         << (!(x && y) ? 'T' : 'F') << "       "
         << (!x || !y ? 'T' : 'F') << "         "
         << (!(x || y) ? 'T' : 'F') << "        "
         << (!x && !y ? 'T' : 'F') << endl;
    
    //Second Line
    y = false;
    cout << (x ? 'T' : 'F') << " " << (y ? 'T' : 'F') << "  "
         << (!x ? 'T' : 'F') << "  " << (!y ? 'T' : 'F') << "   "
         << (x && y ? 'T' : 'F') << "      "
         << (x || y ? 'T' : 'F') << "      "
         << (x ^ y ? 'T' : 'F') << "          "
         << ((x ^ y) ^ y ? 'T' : 'F') << "           "
         << ((x ^ y) ^ x ? 'T' : 'F') << "        "
         << (!(x && y) ? 'T' : 'F') << "       "
         << (!x || !y ? 'T' : 'F') << "         "
         << (!(x || y) ? 'T' : 'F') << "        "
         << (!x && !y ? 'T' : 'F') << endl;
    
    //Third Line
    x = false;
    y = true;
    cout << (x ? 'T' : 'F') << " " << (y ? 'T' : 'F') << "  "
         << (!x ? 'T' : 'F') << "  " << (!y ? 'T' : 'F') << "   "
         << (x && y ? 'T' : 'F') << "      "
         << (x || y ? 'T' : 'F') << "      "
         << (x ^ y ? 'T' : 'F') << "          "
         << ((x ^ y) ^ y ? 'T' : 'F') << "           "
         << ((x ^ y) ^ x ? 'T' : 'F') << "        "
         << (!(x && y) ? 'T' : 'F') << "       "
         << (!x || !y ? 'T' : 'F') << "         "
         << (!(x || y) ? 'T' : 'F') << "        "
         << (!x && !y ? 'T' : 'F') << endl;
    
    //Fourth Line
    y = false;
    cout << (x ? 'T' : 'F') << " " << (y ? 'T' : 'F') << "  "
         << (!x ? 'T' : 'F') << "  " << (!y ? 'T' : 'F') << "   "
         << (x && y ? 'T' : 'F') << "      "
         << (x || y ? 'T' : 'F') << "      "
         << (x ^ y ? 'T' : 'F') << "          "
         << ((x ^ y) ^ y ? 'T' : 'F') << "           "
         << ((x ^ y) ^ x ? 'T' : 'F') << "        "
         << (!(x && y) ? 'T' : 'F') << "       "
         << (!x || !y ? 'T' : 'F') << "         "
         << (!(x || y) ? 'T' : 'F') << "        "
         << (!x && !y ? 'T' : 'F') << endl;
    
    //Temp Swap
    cout << endl << "Swap using temporary variables: " << endl;
    char a = 2, 
         b = 3, 
         temp;
    
    cout << "A: " << static_cast<int>(a) << endl;
    cout << "B: " << static_cast<int>(b) << endl;
    
    //Swap here
    temp = a;
    a = b;
    b = temp;
    
    cout << "A: " << static_cast<int>(a) << endl;
    cout << "B: " << static_cast<int>(b) << endl;
    
    //XOR swap
    cout << endl << "Swap using XOR: " << endl;
    
    cout << "A: " << static_cast<int>(a) << endl;
    cout << "B: " << static_cast<int>(b) << endl;
    
    //Swap here
    b = b ^ a;
    a = b ^ a;
    b = b ^ a;
    
    cout << "A: " << static_cast<int>(a) << endl;
    cout << "B: " << static_cast<int>(b) << endl;
    
    //Exit
    return 0;
}

