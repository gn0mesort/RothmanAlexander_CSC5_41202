/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: ASCII between 0 and 127
 * Created on January 22, 2016, 2:30 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
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
    return 0;
}

