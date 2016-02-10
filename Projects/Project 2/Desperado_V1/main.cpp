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
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

//User Libraries
#include "Game.h" //Game object library

//Global Constants

//Function Prototypes
void frmtOpt(string);
void gChoice(char[], const string[], int);
char gInput(void);
unsigned short gMaxHp(unsigned char);
string gInStr(void);
string trim(string);
void dspFile(string);
void pause(void);
string mask(string);
bool cntns(string, char);
void unmask(string &, string &, char);
//Game Functions
void svGame(string);
void ldGame(string);
char shwMenu(string [], int);
void plyGame(void);
void options(void);
//Struct Functions
bool battle(Player &, Player &);
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

    srand(static_cast<int> (time(0)));

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

bool chkFile(string path) {
    ifstream file;
    file.open(path.c_str());
    if (file.good()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

void shHeal(Player &user) {
    const int MS = 2;
    bool leave = false;
    string menu[] = {"Yes", "No"};
    dspFile("shamanheal.txt");
    do {
        cout << "Healing costs " << (gMaxHp(user.level) - user.hp) * 10 << " gold"
                << endl;
        cout << "Heal your wounds?" << endl;
        switch (shwMenu(menu, MS)) {
            case 'Y':
            {
                if (user.gold > (gMaxHp(user.level) - user.hp) * 10) {
                    user.gold -= (gMaxHp(user.level) - user.hp) * 10;
                    user.hp = gMaxHp(user.level);
                } else {
                    cout << "You don't have enough gold" << endl;
                }
                break;
            }
            case 'N':
            {
                leave = true;
                break;
            }
        }
    } while (!leave);
}

void shChrms(const vector<Charm> &charms, Player &user) {
    char choice;
    dspFile("shamanshop.txt");
    cout << "INVENTORY:" << endl;
    for (int i = 0; i < charms.size(); ++i) {
        cout << "(" << i + 1 << ") " << charms[i].name << endl;
        cout << '\t' << charms[i].dsc << endl;
        cout << '\t' << "DEF:  " << static_cast<int> (charms[i].def) << endl;
        cout << '\t' << "COST: " << charms[i].def * 100 << endl;
    }
    cout << "(0) Leave" << endl;
    do {
        cout << "What would you like to buy?" << endl;
        choice = gInput();
        for (int i = 0; i < charms.size(); ++i) {
            if ((choice - 48) == i + 1) {
                if (user.gold >= charms[i].def * 100) {
                    user.gold -= charms[i].def * 100;
                    user.eqCharm = charms[i];
                } else {
                    cout << "You don't have enough gold" << endl;
                }
            }
        }
    } while (choice != '0');
}

void shGns(const vector<Gun> &guns, Player &user) {
    char choice;
    dspFile("gunsmith.txt");
    cout << "INVENTORY:" << endl;
    for (int i = 0; i < guns.size(); ++i) {
        cout << "(" << i + 1 << ") " << guns[i].name << endl;
        cout << '\t' << guns[i].dsc << endl;
        cout << '\t' << "ATK:  " << static_cast<int> (guns[i].atk) << endl;
        cout << '\t' << "AMMO: " << guns[i].ammo << endl;
        cout << '\t' << "COST: " << guns[i].atk * 100 << endl;
    }
    cout << "(0) Leave" << endl;
    do {
        cout << "What would you like to buy?" << endl;
        choice = gInput();
        for (int i = 0; i < guns.size(); ++i) {
            if ((choice - 48) == i + 1) {
                if (user.gold >= guns[i].atk * 100) {
                    user.gold -= guns[i].atk * 100;
                    user.eqGun = guns[i];
                } else {
                    cout << "You don't have enough gold" << endl;
                }
            }
        }
    } while (choice != '0');
}

int fndGn(const vector<Gun> &vec, const Gun &key) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].name == key.name && vec[i].dsc == key.dsc
                && vec[i].ammo == key.ammo && vec[i].atk == key.atk) {
            return i;
        }
    }

    return -1;
}

int fndChrm(const vector<Charm> &vec, const Charm &key) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].name == key.name && vec[i].dsc == key.dsc
                && vec[i].def == key.def) {
            return i;
        }
    }

    return -1;
}

void svGame(const Player &user, const vector<Gun> &guns,
        const vector<Charm>&charms) {
    string path = user.name + ".sav";
    ofstream oFile;
    oFile.open(path.c_str());
    oFile << user.name << endl;
    oFile << static_cast<int> (user.level) << endl;
    oFile << static_cast<int> (user.hp) << endl;
    oFile << fndGn(guns, user.eqGun) << endl;
    oFile << fndChrm(charms, user.eqCharm) << endl;
    oFile << user.gold << endl;
    oFile.close();
}

void ldGame(Player &user, const vector<Gun> &guns,
        const vector<Charm> &charms) {
    string path = user.name + ".sav",
            level,
            hp;
    short tLevel;
    int gun,
            charm;
    ifstream iFile;
    iFile.open(path.c_str());
    iFile >> user.name;
    iFile >> level;
    istringstream cnvLvl(level);
    cnvLvl >> user.level;
    iFile >> hp;
    istringstream cnvHp(hp);
    cnvHp >> user.hp;
    iFile >> gun;
    user.eqGun = guns[gun];
    iFile >> charm;
    user.eqCharm = charms[charm];
    iFile >> user.gold;
    iFile.close();
}

void pPlayer(const Player &p) {
    cout << "NAME:  " << p.name << endl;
    cout << "LEVEL: " << static_cast<int> (p.level) << endl;
    cout << "HP:    " << static_cast<int> (p.hp) << "/"
            << static_cast<int> (gMaxHp(p.level)) << endl;
    cout << "GUN:   " << p.eqGun.name << endl;
    cout << "AMMO:  " << p.eqGun.cAmmo << "/" << p.eqGun.ammo << endl;
    cout << "ATK:   " << static_cast<int> (p.eqGun.atk) << endl;
    cout << "CHARM: " << p.eqCharm.name << endl;
    cout << "DEF:   " << static_cast<int> (p.eqCharm.def) << endl;
    cout << "GOLD:  " << p.gold << endl;
}

vector<Player> ldEnms(vector<Gun> guns, vector<Charm> charms) {
    string level,
            gold,
            charm,
            gun;
    Player temp;
    ifstream iFile;
    vector<Player> enemies;

    iFile.open("enemies.dat");
    while (iFile.good()) {
        getline(iFile, temp.name);
        temp.name = trim(temp.name);
        getline(iFile, level);
        istringstream cnvLvl(level);
        cnvLvl >> temp.level;
        getline(iFile, gold);
        getline(iFile, charm);
        getline(iFile, gun);
        temp.hp = gMaxHp(temp.level);
        istringstream cnvGold(gold);
        cnvGold >> temp.gold;
        temp.eqCharm = charms[charm.at(0) - 48];
        temp.eqGun = guns[gun.at(0) - 48];
        enemies.push_back(temp);
    }
    iFile.close();

    return enemies;
}

vector<Charm> ldChrms() {
    string def;
    Charm temp;
    ifstream iFile;
    vector<Charm> charms;

    iFile.open("charms.dat");
    while (iFile.good()) {
        getline(iFile, temp.name);
        getline(iFile, temp.dsc);
        getline(iFile, def);
        istringstream convert(def);
        convert >> temp.def;
        charms.push_back(temp);
    }
    iFile.close();

    return charms;
}

vector<Gun> ldGns() {
    string ammo,
            atk;
    Gun temp;
    ifstream iFile;
    vector<Gun> guns;

    iFile.open("guns.dat");
    while (iFile.good()) {
        getline(iFile, temp.name);
        getline(iFile, temp.dsc);
        getline(iFile, ammo);
        getline(iFile, atk);
        istringstream cnvAmmo(ammo);
        cnvAmmo >> temp.ammo;
        temp.cAmmo = temp.ammo;
        istringstream cnvAtk(atk);
        cnvAtk >> temp.atk;
        guns.push_back(temp);
    }
    iFile.close();

    return guns;
}

unsigned short gMaxHp(unsigned char level) {
    const unsigned char BASEHP = 100;
    const float RATE = 0.05f;

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

void reload(Player &p) {
    p.eqGun.cAmmo = p.eqGun.ammo;
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

void bBoard(const vector<Player> enemies, int &bounty) {
    char choice;
    string menu[enemies.size()];

    for (int i = 0; i < enemies.size() - 1; ++i) {
        menu[i] = enemies[i].name + '\n';
    }
    choice = shwMenu(menu, enemies.size() - 1);
    for (int i = 0; i < enemies.size() - 1; ++i) {
        if (choice == toupper(menu[i].at(0))) {
            cout << "You choose to hunt " << enemies[i].name << endl;
            bounty = i;
        }
    }
}

void ldWrds(string *words, int length) {
    ifstream iFile;

    iFile.open("wdlcur.txt");
    for (int i = 0; iFile >> *(words + i); ++i);
    iFile.clear();
}

bool guess(string word, Player &p) {
    const int ALPHAS = 26,
            LS = 2;
    string mWord = mask(word);
    ifstream iFile;
    unsigned short gCount = p.eqCharm.def,
            total;
    unsigned short lfreq[ALPHAS][LS];

    iFile.open("freq.dat");
    for (int i = 0; i < ALPHAS; ++i) {
        lfreq[i][0] = i;
        iFile >> lfreq[i][1];
    }
    iFile.close();

    /*
    for(int i = 0; i < ALPHAS; ++i){
        cout << static_cast<char>(lfreq[i][0] + 97) << ":" << lfreq[i][1] << endl;
    }
     */

    for (int i = 0; i < ALPHAS; ++i) {
        total += lfreq[i][1];
    }

    char *gList = new char[total];

    for (int i = 0; i < total; ++i) {
        gList[i] = 0;
    }

    string temp;
    for (int i = 0; i < ALPHAS; ++i) {

        for (int j = 0; j < lfreq[i][1]; ++j) {
            temp += static_cast<char> (lfreq[i][0] + 97);
        }
    }
    strcpy(gList, temp.c_str());

    for (int i = gCount; i > 0; --i) {
        char guess = gList[rand() % total];
        cout << guess;
        if (cntns(word, guess)) {
            unmask(word, mWord, guess);
        }
        if (mWord == word) {
            cout << endl;
            delete [] gList;
            return true;
        }
    }
    cout << endl;

    delete [] gList;
    return false;
}

string trim(string str) {
    string r;

    for (int i = 0; i < str.size(); ++i) {
        if (str.at(i) > 31 && str.at(i) < 127) {
            r += str.at(i);
        }
    }

    return r;
}

/******************************************************************************/
/************************************Mask**************************************/
/******************************************************************************/
//  Puts a string on equal length to an input string into a new array
//  Fills the new string with the given character

string mask(string oWord) {
    string r;

    for (int i = 0; i < oWord.size(); ++i) { //loop through the words
        r += '*';
    }

    return r;
}

/******************************************************************************/
/**********************************Contains************************************/
/******************************************************************************/
//  A function to determine if a string contains a character

bool cntns(string word, char key) {
    for (int i = 0; i < word.length(); ++i) { //loop through word
        if (word.at(i) == key) {
            return true;
        } //if a character matches the key return true
    }
    //Otherwise return false
    return false;
}

/******************************************************************************/
/*********************************Gnome Sort***********************************/
/******************************************************************************/
//  Sort a character array. Weights null characters as higher than all others
//Inputs
//  cArr : the character array to sort
//  length : the length of the array to sort

void gSort(char cArr[], int length) {
    for (int pos = 1; pos < length;) { //Gnome Sort modified to handle null terminators
        if (cArr[pos] >= cArr[pos - 1] || cArr[pos] == '\0') { //if the current character is greater than the previous one or null
            ++pos; //move one position forward
        } else if (cArr[pos] <= cArr[pos - 1]) { //If the current character is less than or equal to the previous
            //Swap the current character and the last
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos - 1] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            if (pos > 1) { //If the position is greater than one
                --pos; //Move back one position
            }
        }
    }
}

/******************************************************************************/
/*********************************Unmask***************************************/
/******************************************************************************/
//  Unmask a single character in a masked string based on an unmasked string

void unmask(string &oWord, string &mWord, char key) {
    for (int i = 0; i < oWord.size(); ++i) { //loop through all characters
        if (oWord.at(i) == key) { //compare each character to the guess character
            mWord.at(i) = key; //Unmask the character if they match
        }
    }
}

bool battle(Player &user, Player &opnt) {
    const int WS = 125;
    bool btlOver = false,
            r;
    unsigned short gCount = user.eqCharm.def,
            usedPos = 0;
    string uWord,
            oWord,
            mWord;
    char used[26] = {0};
    string words[WS];

    ldWrds(words, WS);

    do {
        //Player Turn
        cout << user.name << "'s turn!" << endl;
        if (user.eqGun.cAmmo > 0) {
            cout << "PLAYER HP:   " << user.hp << "/" << gMaxHp(user.level)
                    << endl;
            cout << "OPPONENT HP: " << opnt.hp << "/" << gMaxHp(opnt.level)
                    << endl;
            cout << "AMMO: " << user.eqGun.cAmmo << "/" << user.eqGun.ammo
                    << endl;
            cout << "Choose a word to fire" << endl;
            uWord = gInStr();
            if (!guess(uWord, opnt)) {
                opnt.hp -= user.eqGun.atk;
                cout << opnt.name << " was hit!" << endl;
                cout << opnt.name << " took " << user.eqGun.atk << " damage"
                        << endl;
            } else {
                cout << opnt.name << " dodged your shot!" << endl;
            }
            user.eqGun.cAmmo--;
        } else {
            reload(user);
            cout << user.name << " reloaded!" << endl;
        }
        //Opponent Turn
        if (opnt.hp > 0) {
            cout << opnt.name << "'s turn!" << endl;
            if (opnt.eqGun.cAmmo > 0) {
                oWord = words[rand() % WS];
                mWord = mask(oWord);
                //cout << oWord << endl;
                do {
                    char guess;
                    cout << mWord << endl;
                    cout << "REMAINING GUESSES: " << gCount << endl;
                    cout << "USED CHARACTERS:   " << used << endl;
                    guess = tolower(gInput());
                    if (cntns(oWord, guess)) {
                        unmask(oWord, mWord, guess);
                    } else {
                        --gCount;
                    }
                    if (!cntns(string(used), guess)) {
                        used[usedPos++] = guess;
                    }
                    gSort(used, 26);

                } while (gCount > 0 && mWord != oWord);
                cout << oWord << endl;
                if (gCount <= 0) {
                    user.hp -= opnt.eqGun.atk;
                    cout << user.name << " was hit!" << endl;
                    cout << user.name << " took " << opnt.eqGun.atk << " damage"
                            << endl;
                } else if (mWord == oWord) {
                    cout << user.name << " dodged the shot!" << endl;
                }
                gCount = user.eqCharm.def;
                for (int i = 0; i < 26; ++i) {
                    used[i] = 0;
                }
                usedPos = 0;

                opnt.eqGun.cAmmo--;
            } else {
                reload(opnt);
                cout << opnt.name << " reloaded!" << endl;
            }
        }
        if (user.hp <= 0) {
            cout << "YOU DIED" << endl;
            r = false;
            btlOver = true;
        } else if (opnt.hp <= 0) {
            cout << opnt.name << " was defeated" << endl;
            cout << "You were awarded " << opnt.gold << " gold" << endl;
            r = true;
            user.gold += opnt.gold;
            btlOver = true;
        }
    } while (!btlOver);
    opnt.hp = gMaxHp(opnt.level);

    return r;
}

void plyGame() {
    const int PGMS = 2,
            GMS = 6;
    bool qGame = false;
    int bounty = -1;
    unsigned short wins = 0;
    Player pUser;
    vector<Gun> guns(ldGns());
    vector<Charm> charms(ldChrms());
    vector<Player> enemies(ldEnms(guns, charms));

    string pgMenu[] = {"New Game", "Load"};
    string gMenu[] = {"Bounty Board", "Hunt Bounty",
        "Gunsmith", "Shaman", "Character", "Quit"};

    switch (shwMenu(pgMenu, PGMS)) {
        case 'N':
        {
            dspFile("titlecrawl.txt");
            pause();
            cout << "Enter your name" << endl;
            pUser.name = gInStr();
            pUser.eqGun = guns[0];
            pUser.eqCharm = charms[0];
            pUser.gold = 1000;
            pUser.level = 1;
            pUser.hp = gMaxHp(pUser.level);
            break;
        }
        case 'L':
        {
            cout << "Enter the name of a character to load" << endl;
            pUser.name = gInStr();
            if (chkFile(pUser.name + ".sav")) {
                ldGame(pUser, guns, charms);
            } else {
                cout << "Save not found" << endl;
                cout << "Creating new game..." << endl;
                dspFile("titlecrawl.txt");
                pause();
                pUser.eqGun = guns[0];
                pUser.eqCharm = charms[0];
                pUser.gold = 1000;
                pUser.level = 1;
                pUser.hp = gMaxHp(pUser.level);
            }
            break;
        }
    }
    do {
        dspFile("town.txt");
        switch (shwMenu(gMenu, GMS)) {
            case 'B':
            {
                dspFile("bountyboard.txt");
                bBoard(enemies, bounty);
                pause();
                break;
            }
            case 'H':
            {
                if (bounty != -1) {
                    reload(pUser);
                    battle(pUser, enemies[bounty]);
                } else {
                    cout << "You have to choose a bounty first" << endl;
                    cout << "Go to the bounty board" << endl;
                }
                if (pUser.hp <= 0) {
                    cout << "GAME OVER" << endl;
                    qGame = true;
                } else {
                    if (wins % 5 == 0 && wins != 0) {
                        pUser.level++;
                        cout << "LEVEL UP!" << endl;
                        cout << "HP increased by "
                                << gMaxHp(pUser.level) - gMaxHp(pUser.level - 1)
                                << endl;
                        pUser.hp = gMaxHp(pUser.level);
                    }
                    pause();
                }
                break;
            }
            case 'G':
            {
                shGns(guns, pUser);
                pause();
                break;
            }
            case 'S':
            {
                const int SHMS = 2;
                string shMenu[] = {"Heal", "Shop"};
                dspFile("shaman.txt");
                switch (shwMenu(shMenu, SHMS)) {
                    case 'H':
                    {
                        shHeal(pUser);
                        break;
                    }
                    case 'S':
                    {
                        shChrms(charms, pUser);
                        break;
                    }
                }
                pause();
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
    } while (!qGame);
    if (pUser.hp > 0) {
        svGame(pUser, guns, charms);
    }
}

/******************************************************************************/
/********************************Display File**********************************/
/******************************************************************************/
//  Write the text from a file to standard out one line at a time
//Inputs
//  path : the path to the file to display

void dspFile(string path) {
    string next; //input buffer
    ifstream iFile; //input file stream

    iFile.open(path.c_str()); //open file
    while (getline(iFile, next)) { //read each line
        cout << next << endl; //output line
    }
    iFile.close(); //close file
}