/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Hangman game
 * Created on January 30, 2016, 4:12 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void gsort(char[], int); //Gnome Sort a character array
bool isword(char[], int); //Determine if a string is a word
bool contains(char[], int, char); //Determine if a string contains a character
void displayfile(const char[]); //Display file data line by line
//Game Functions
char menu(void); //Do the basic game menu processing

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    bool quit = false; //Determine whether or not to quit the game
    
    //Game Loop
    do{
        switch(menu()){ //Choose the input from the menu display
            case 'P': //Play the game
            {
                
                break;
            }
            case 'S': //Display Scores
            {
                break;
            }
            case 'O': //Display Options
            {
                break;
            }
            case 'Q': //Quit
            {
                quit = true;
            }
        }
    } while(!quit);
    
    //Exit
    return 0;
}

void displayfile(const char path[]){
    char next[256];
    ifstream iFile;

    iFile.open(path);
    while (iFile.getline(next, 256, '\n')) {
        cout << next << endl;
    }
    iFile.close();
}

char menu(){
    const char TITLE[] = "gametitle.txt";
    char choice;
    char input[8] = {0};
    
    displayfile(TITLE);
    cout << "Menu:" << setw(15) << "(P)lay" << setw(15) << "(S)cores" 
         << setw(15) << "(O)ptions" << setw(10) << "(Q)uit" << endl;
    
    do{
        cout << "> ";
        cin >> input;
        choice = toupper(input[0]);
        if(choice != 'P' && choice != 'S' && choice != 'O' && choice != 'Q'){
            cout << "> Invalid Input. Please input (P), (S), (O), or (Q) without parentheses" 
                 << endl;
        }
    } while(choice != 'P' && choice != 'S' && choice != 'O' && choice != 'Q');

    
    return choice;
}

bool contains(char word[], int length, char key){
    for(int i = 0; i < length; ++i){
        if(word[i] == key){ return true; }
    }
    return false;
}

bool isword(char word[], int length){
    for(int i = 0; i < length; ++i){
        if(word[i] > 126 || word[i] < 33) { return false; }
    }
    return true;
}

void gsort(char cArr[], int length){
    for(int pos = 1; pos < length;){ //Gnome Sort modified to handle null terminators
        if(cArr[pos] >= cArr[pos - 1] || cArr[pos] == '\0'){
            ++pos;
        }
        else if (cArr[pos] <= cArr[pos - 1]){
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos - 1] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            if(pos > 1){
                --pos;
            }
        }
    }
}
