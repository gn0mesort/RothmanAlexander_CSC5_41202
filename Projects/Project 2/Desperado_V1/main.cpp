/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Desperado Game
 * Created on February 4, 2016, 7:33 AM
 */

//System Libraries
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//User Libraries
#include "Game.h"; //Game object library

//Global Constants

//Function Prototypes
void frmtOpt(string);
void gChoice(char[], const string[], int);
char gInput(void);
unsigned char gMaxHp(unsigned char);
string gInStr(void);
void dspFile(string);
void pause(void);
unsigned char stouc(string);
//Game Functions
void svGame(string);
void ldGame(string);
char shwMenu(string [], int);
void plyGame(void);
void options(void);
//Struct Functions
void battle(Player &, Player &);
vector<Gun> ldGns();
vector<Charm> ldChrms();
vector<Player> ldEnms();
void svGame(const Player &);
void pPlayer(const Player &);

//Begin Execution
int main(int argc, char** argv) {
    bool quit = false, 
         loaded = false;
    const int MAIN_MENU_SIZE = 3;
    string mMenu[] = {"Play", "Options", "Quit"}; 
    
    srand(static_cast<int>(time(0)));
    
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
                //TODO Options Menu
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
    
    //Exit
    return 0;
}

int fndGn(const vector<Gun> &vec, const Gun &key){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i].name == key.name && vec[i].dsc == key.dsc 
           && vec[i].ammo == key.ammo && vec[i].atk == key.atk){
            return i;
        }
    }
    
    return -1;
}

int fndChrm(const vector<Charm> &vec, const Charm &key){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i].name == key.name && vec[i].dsc == key.dsc 
           && vec[i].def == key.def){
            return i;
        }
    }
    
    return -1;
}

void svGame(const Player &user, const vector<Gun> &guns, 
            const vector<Charm>&charms){
    string path = user.name + ".sav";
    ofstream oFile;
    oFile.open(path.c_str());
    oFile << user.name << endl;
    oFile << static_cast<int>(user.level) << endl;
    oFile << static_cast<int>(user.hp) << endl;
    oFile << fndGn(guns, user.eqGun) << endl;
    oFile << fndChrm(charms, user.eqCharm) << endl;
    oFile << user.gold << endl;
    oFile.close();
}

void ldGame(Player &user, const vector<Gun> &guns, 
            const vector<Charm> &charms){
    string path = user.name + ".sav",
            level,
            hp;
    int gun, 
        charm;
    ifstream iFile;
    iFile.open(path.c_str());
    iFile >> user.name;
    iFile >> level;
    user.level = stouc(level);
    iFile >> hp;
    user.hp = stouc(hp);
    iFile >> gun;
    user.eqGun = guns[gun];
    iFile >> charm;
    user.eqCharm = charms[charm];
    iFile >> user.gold;
    iFile.close();
}

void pPlayer(const Player &p){
    cout << "NAME:  " << p.name << endl;
    cout << "LEVEL: " << static_cast<int>(p.level) << endl;
    cout << "HP:    " << static_cast<int>(p.hp) << "/" 
         << static_cast<int>(gMaxHp(p.level)) << endl;
    cout << "GUN:   " << p.eqGun.name << endl;
    cout << "ATK:   " << static_cast<int>(p.eqGun.atk) << endl;
    cout << "CHARM: " << p.eqCharm.name << endl;
    cout << "DEF:   " << static_cast<int>(p.eqCharm.def) << endl;
    cout << "GOLD:  " << p.gold << endl;
}

unsigned char stouc(string num){
    unsigned char r = 0;
    
    for (int i = 0; i < num.size(); ++i){
        r += (num.at(i) - 48) * pow(10, ((num.size() - 1) - i));
    }
    
    return r;
}

//String to Unsigned Short
//Assumes string is numeric and fits in the size of an unsigned short
unsigned short stous(string num){
    unsigned short r = 0; //Return value
    
    for(int i = 0; i < num.size(); ++i){ //Loop through each character in the string
        r += (num.at(i) - 48) * pow(10, ((num.size() - 1) - i));
    }
    
    return r;
}

vector<Player> ldEnms(vector<Gun> guns, vector<Charm> charms){
    string level,
           gold,
           charm,
           gun;
    Player temp;
    ifstream iFile;
    vector<Player> enemies;
    
    iFile.open("enemies.dat");
    while(iFile.good()){
        getline(iFile, temp.name);
        getline(iFile, level);
        getline(iFile, gold);
        getline(iFile, charm);
        getline(iFile, gun);
        temp.hp = gMaxHp(level.at(0));
        temp.gold = stous(gold);
        temp.eqCharm = charms[charm.at(0) - 48];
        temp.eqGun = guns[gun.at(0) - 48];
        enemies.push_back(temp);
    }
    iFile.close();
    
    return enemies;
}

vector<Charm> ldChrms(){
    string def;
    Charm temp;
    ifstream iFile;
    vector<Charm> charms;
    
    iFile.open("charms.dat");
    while(iFile.good()){
        getline(iFile, temp.name);
        getline(iFile, temp.dsc);
        getline(iFile, def);
        temp.def = stouc(def);
        charms.push_back(temp);
    }
    iFile.close();
    
    return charms;
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
        temp.ammo = stouc(ammo);
        temp.cAmmo = temp.ammo;
        temp.atk = stouc(atk);
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
    const int PGMS = 2,
              GMS = 6;
    bool qGame = false;
    Player pUser;
    vector<Gun> guns(ldGns());
    vector<Charm> charms(ldChrms());
    //vector<Player> enemies(ldEnms(guns, charms));
    
    string pgMenu[] = {"New Game", "Load"};
    string gMenu[] = {"Bounty Board", "Hunt Bounty", 
                      "Gunsmith", "Shaman", "Character", "Quit"};
    
    switch(shwMenu(pgMenu, PGMS)){
        case 'N':
        {
            dspFile("titlecrawl.txt");
            pause();
            cout << "Enter your name" << endl;
            pUser.name = gInStr();
            pUser.eqGun = guns[0];
            pUser.eqCharm = charms[0];
            pUser.gold = 100;
            pUser.level = 1;
            pUser.hp = gMaxHp(pUser.level);
            break;
        }
        case 'L':
        {
            cout << "Enter the name of a character to load" << endl;
            pUser.name = gInStr();
            ldGame(pUser, guns, charms);
            //TODO Load game
            break;
        }
    }
    do{
        switch(shwMenu(gMenu, GMS)){
            case 'B':
            {
                break;
            }
            case 'H':
            {
                break;
            }
            case 'G':
            {
                break;
            }
            case 'S':
            {
                break;
            }
            case 'C':
            {
                pPlayer(pUser);
                pause();
                break;
            }
            case 'Q':
            {
                qGame = true;
                break;
            }
        }
    } while(!qGame);
    svGame(pUser, guns, charms);
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