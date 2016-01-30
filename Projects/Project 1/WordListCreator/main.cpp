/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Create word lists
 * Created on January 30, 2016, 12:42 AM
 */

//Systemn Library
#include <iostream>
#include <fstream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int charcount(char[], int); //Calculate printable characters in an array

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    char easy[] = "wdleasy.txt", //Easy word list
         medium[] = "wdlmedium.txt", //Medium word list
         hard[] = "wdlhard.txt", //Hard word list
         dict[] = "dictionary.txt", //The complete dictionary
         word[26] = {0}; //The current word
    ifstream iFile;  //Input stream
    ofstream oEas, //Output easy list
             oMed, //Output medium list
             oHar; //Output hard list
    
    //Open files
    iFile.open(dict);
    oEas.open(easy);
    oMed.open(medium);
    oHar.open(hard);
     //Create lists of each size of word
    while(iFile >> word){ //read a word from the dictionary
        int count = charcount(word, 26); //count the characters
        if(count >= 12){ //If it's a long word
            oHar << word << endl;
        }
        else if (count >= 7){ //If it's a medium sized word
            oMed << word << endl;
        }
        else { //If it's a short word
            oEas << word << endl;
        }
    }
    //Close files
    iFile.close();
    oEas.close();
    oMed.close();
    oHar.close();
    
    //Exit
    return 0;
}

//int charcount(char[], int)
//Character Count
//Input:
//  word[] : an array of characters to be counted
//  size : the size of the input array
//Output:
//  count : the number of printable characters in the input array
int charcount(char word[], int size){
    int count = 0; //The number of printable characters counted
    for(int i = 0; i < size; ++i){ //Loop through array
        if(word[i] > 31 && word[i] < 127) { ++count; } //If printable count it
    }
    //Return
    return count; 
}

