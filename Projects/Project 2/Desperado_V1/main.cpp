/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Desperado Game
 * Created on February 4, 2016, 7:33 AM
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const int ISIZEY = 12;
const int ISIZEX = 2;

using namespace std;
void frmtOpt(string);
void gChoice(char[], string[], int);
char gInput(void);
string gInStr(void);
void pause(void);
void dspFile(string);
//Game Functions
void svGame(string);
void ldGame(string);
char shwMenu(string[], int);
void plyGame(string, char, unsigned char[ISIZEY][ISIZEX], bool);
void options(void);

int main(int argc, char** argv) {
    //Player Data
    bool loaded = false;
    unsigned char level = 1;
    string pName = "No Name";
    //inv[ITEM ID][0] gets the quantity of an item
    //inv[ITEM ID][1] gets whether or not the item is equipped
    unsigned char inv[ISIZEY][ISIZEX]; 
    //End Player Data
    bool quit = false;
    const int MAIN_MENU_SIZE = 3;
    string mMenu[] = {"Play", "Options", "Quit"}; 

    do {
        dspFile("header.txt");
        switch (shwMenu(mMenu, MAIN_MENU_SIZE)) {
            case 'P':
            {
                plyGame(pName, level, inv);
                pause();
                break;
            }
            case 'O':
            {
                //options();
                pause();
                break;
            }
            case 'Q':
            {
                quit = true;
                break;
            }
        }
    } while (!quit);

    return 0;
}

char gInput() {
    string input;
    cout << "> ";
    cin >> input;

    return toupper(input.at(0));
}

string gInStr() {
    string input;
    cout << "> ";
    cin >> input;
    
    return input;
}

void gChoice(char output[], string input[], int length) {
    for (int i = 0; i < length; ++i) {
        output[i] = toupper(input[i].at(0));
    }
}

void pause() {
    cin.ignore();
    cout << "Press Enter to continue...";
    cin.get();
}

string fmrtOpt(const string opt) {
    string r = opt;

    r.insert(0, 1, '(');
    r.insert(2, 1, ')');

    return r;
}

char shwMenu(string opts[], int length) {
    bool invalid = true;
    char input;
    char choices[length] = {0};
    gChoice(choices, opts, length);
    for (int i = 0; i < length; ++i) {
        cout << setw(opts[i].length() + 5) << fmrtOpt(opts[i]);
    }
    cout << endl;
    do {
        input = gInput();
        for (int i = 0; i < length; ++i) {
            if (choices[i] == input) {
                invalid = false;
            }
        }
    } while (invalid);
    
    return input;
}

void plyGame(string pName, char level, unsigned char inv[ISIZEY][ISIZEX], 
             bool loaded) {
    const int PLAY_GAME_MENU_SIZE = 2;
    string pgMenu[] = {"New Game", "Load"};
    
    switch(shwMenu(pgMenu, PLAY_GAME_MENU_SIZE)){
        case 'N':
        {
            if(loaded){
                //TODO Save game before overwriting
            }
            dspFile("titlecrawl.txt");
            pause();
            cout << "Enter your name" << endl;
            pName = gInStr();
            level = 1;
            for(int i = 0; i < ISIZEY; ++i){
                inv[i][0] = 0;
                inv[i][1] = 0;
            }
        }
        case 'L':
        {
            //TODO Load game
        }
    }
}

/******************************************************************************/
/********************************Display File**********************************/
/******************************************************************************/
//  Write the text from a file to standard out one line at a time
//Inputs
//  path : the path to the file to display
void dspFile(string path){
    string next; //input buffer
    ifstream iFile; //input file stream

    iFile.open(path.c_str()); //open file
    while (getline(iFile, next)) { //read each line
        cout << next << endl; //output line
    }
    iFile.close(); //close file
}