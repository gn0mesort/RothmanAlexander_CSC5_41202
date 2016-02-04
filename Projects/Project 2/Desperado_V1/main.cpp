/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Desperado Game
 * Created on February 4, 2016, 7:33 AM
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
void frmtOpt(string);
void gChoice(char[], string[], int);
char gInput(void);
void pause(void);
//Game Functions
void svGame(string);
void ldGame(string);
char shwMenu(string[], int);
void plyGame(void);
void options(void);

int main(int argc, char** argv) {
    bool quit = false;
    const int MAIN_MENU_SIZE = 3;
    string mMenu[] = {"Play", "Options", "Quit"}; 

    do {
        switch (shwMenu(mMenu, MAIN_MENU_SIZE)) {
            case 'P':
            {
                plyGame();
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
        cout << setw(10) << fmrtOpt(opts[i]);
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

void plyGame() {
    const int PLAY_GAME_MENU_SIZE = 2;
    string pgMenu[] = {"New Game", "Load"};
    
    switch(shwMenu(pgMenu, PLAY_GAME_MENU_SIZE)){
        case 'N':
        {
            
        }
        case 'L':
        {
            
        }
    }
}

