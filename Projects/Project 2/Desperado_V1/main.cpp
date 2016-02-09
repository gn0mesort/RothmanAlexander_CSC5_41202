/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Desperado Game
 * Created on February 4, 2016, 7:33 AM
 */


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

const int ISIZEY = 12;
const int ISIZEX = 2;

using namespace std;
void frmtOpt(string);
void gChoice(char[], const string[], int);
char gInput(void);
unsigned char gMaxHp(unsigned char);
string gInStr(void);
void dspFile(string);
void pause(void);
//Game Functions
void svGame(string);
void ldGame(string);
char shwMenu(string [], int);
void plyGame(void);
void options(void);

struct Gun{
    unsigned char atk,
                  ammo;
    string name,
           dsc;
};

struct Charm{
    unsigned char def;
    string name,
           dsc;
};

struct Player{
    unsigned char hp, 
                  level;
    unsigned short gold;
    string name;
    Charm eqCharm;
    Gun eqGun;
};

void battle(Player &, Player &);
vector<Gun> ldGns();
vector<Charm> ldChrms();
vector<Player> ldEnms();

int main(int argc, char** argv) {
    bool quit = false, 
         loaded = false;
    const int MAIN_MENU_SIZE = 3;
    string mMenu[] = {"Play", "Options", "Quit"}; 
    
    do {
        dspFile("header.txt");
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

vector<Gun> ldGns(){
    string ammo,
           atk;
    Gun temp;
    ifstream iFile;
    vector<Gun> guns;
    
    iFile.open("guns.dat");
    while(iFile.good()){
        getline(iFile, temp.name);
        getline(iFile, temp.dsc);
        getline(iFile, ammo);
        getline(iFile, atk);
        temp.ammo = ammo.at(0) - 48;
        temp.atk = atk.at(0) - 48;
        guns.push_back(temp);
    }
    iFile.close();
    
    return guns;
}

unsigned char gMaxHp(unsigned char level){
    const unsigned char BASEHP = 10;
    const float RATE = 0.05;
   
    return BASEHP * (pow((1 + RATE), level));
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

void plyGame() {
    const int PGMS = 2;
    Player pUser;
    vector<Gun> guns(ldGns());
    vector<Charm> charms(ldChrms());
    vector
    
    string pgMenu[] = {"New Game", "Load"};
    
    switch(shwMenu(pgMenu, PGMS)){
        case 'N':
        {
            dspFile("titlecrawl.txt");
            pause();
            cout << "Enter your name" << endl;
            pUser.name = gInStr();
            pUser.eqGun = guns[0];
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