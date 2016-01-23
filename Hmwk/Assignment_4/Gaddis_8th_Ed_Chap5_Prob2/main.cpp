/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: ASCII between 0 and 127
 * Created on January 22, 2016, 2:30 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    const unsigned char NUMCHAR = 128,
            CHARROW = 16,
            NUMROW = NUMCHAR / CHARROW;
    
    cout << "THE ASCII TABLE 0 to 127" << endl;
    for(int i = 0; i < NUMROW; ++i){
        for(int curPos = 0; curPos < CHARROW; ++curPos){
            cout << setw(4) << static_cast<int>(curPos + (CHARROW * i)) 
                    << " ";
        }
        cout << endl;
        for(int curChar = 0; curChar < CHARROW; ++curChar){
            if(curChar + (CHARROW * i) < 32 || curChar + (CHARROW * i) == 127){
                switch(curChar + (CHARROW * i)){
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
            else {
                cout << setw(4) << static_cast<char>(curChar + (CHARROW * i)) << " ";
            }
        }
        cout << endl;    
    }
    
    return 0;
}

