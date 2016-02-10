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
void frmtOpt(string &);
void gChoice(char [], const string [], int);
bool chkFile(const string &);
char gInput(void);
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
char shwMenu(const string [], int);
void plyGame(void);
//Struct Functions
bool battle(Player &, Player &);
vector<Gun> ldGns();
vector<Charm> ldChrms();
vector<Player> ldEnms();
void svGame(const Player &);
void pPlayer(const Player &);
void shHeal(Player &);
void shChrms(const vector<Charm> &, Player &); 
void shGns(const vector<Gun> &, Player &);
int fndGn(const vector<Gun> &, const Gun &);
int fndChrm(const vector<Charm> &, const Charm &);
void svGame(const Player &, const vector<Gun> &, const vector<Charm> &);
void ldGame(Player &, const vector<Gun> &, const vector<Charm> &); 
void pPlayer(const Player &); 
vector<Player> ldEnms(const vector<Gun> &, const vector<Charm> &);
vector<Charm> ldChrms();
vector<Gun> ldGns();
short gMaxHp(unsigned short = 1);
void reload(Player &);
void bBoard(const vector<Player> &, int &);
void ldWrds(string *, int);
bool guess(string, Player &);
string trim(string); 
//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    //Constants
    const int MS = 3; //The length of the menu
    //Variables
    bool quit = false; //Flag to control quitting the game
    //Collections
    string mMenu[] = {"Play", "Help", "Quit"}; //The main menu

    srand(static_cast<int> (time(0))); //Seed PRNG

    //Main Menu
    do { //While Quit is not selected
        dspFile("header.txt"); //Show the game header
        switch (shwMenu(mMenu, MS)) { //Show the menu
            case 'P': //Play Game
            {
                plyGame();
                pause();
                break;
            }
            case 'H': //Display Help
            {
                dspFile("help.dat");
                pause();
                break;
            }
            case 'Q': //Quit
            {
                quit = true;
                break;
            }
        }
    } while (!quit);

    //Exit
    return 0;
}

/******************************************************************************/
/**********************************Check File**********************************/
/******************************************************************************/
//  Check if a file exists on the system
//Inputs
//  &path : The path to check for a file on
//Outputs
//  true if the file exists
//  false otherwise
bool chkFile(const string &path) {
    //Objects
    ifstream file; //File stream for checking the file
    
    file.open(path.c_str()); //Attempt to open the file
    if (file.good()) { //If the file is opened and good
        file.close(); //Close the file
        return true;
    } else { //Otherwise
        file.close(); //close the file
        return false;
    }
}

/******************************************************************************/
/***********************************Shop Heal**********************************/
/******************************************************************************/
//  Processing for the Shaman healing menu
//Inputs
//  &user : The game's player
void shHeal(Player &user) {
    //Constants
    const int MS = 2; //The length of the menu
    //Variables
    bool leave = false; //Whether or not to leave this menu
    //Collections
    string menu[] = {"Yes", "No"}; //The healing menu
    
    dspFile("shamanheal.txt"); //Display flavor text
    do { //While the player doesn't want to leave
        //Output cost of healing
        cout << "Healing costs " << (gMaxHp(user.level) - user.hp) * 10 
             << " gold" << endl;
        cout << "Heal your wounds?" << endl;
        switch (shwMenu(menu, MS)) { //Display menu
            case 'Y': //If you want to heal
            {
                //Check if the player has enough gold to pay
                if (user.gold > (gMaxHp(user.level) - user.hp) * 10) {
                    //Subtract the cost from the player's total gold
                    user.gold -= (gMaxHp(user.level) - user.hp) * 10;
                    //Heal the player
                    user.hp = gMaxHp(user.level);
                } else {
                    cout << "You don't have enough gold" << endl;
                }
                break;
            }
            case 'N': //If you don't want to heal
            {
                leave = true;
                break;
            }
        }
    } while (!leave);
}

/******************************************************************************/
/**********************************Shop Charms*********************************/
/******************************************************************************/
//  Processing for the Shaman shopping menu
//Inputs
//  &charms : A vector containing the list of charms that exist in the game
//  &user : The game's player
void shChrms(const vector<Charm> &charms, Player &user) {
    //Variables
    char choice; //The player's choice in the menu
    
    dspFile("shamanshop.txt"); //Display flavor text
    cout << "INVENTORY:" << endl;
    for (int i = 0; i < charms.size(); ++i) { //Show the inventory
        //Display the charm's name
        cout << "(" << i + 1 << ") " << charms[i].name << endl;
        //Display charm attributes
        cout << '\t' << charms[i].dsc << endl;
        cout << '\t' << "DEF:  " << static_cast<int> (charms[i].def) << endl;
        cout << '\t' << "COST: " << charms[i].def * 100 << endl;
    }
    //Special leave option
    cout << "(0) Leave" << endl;
    do { //While the player doesn't want to leave
        cout << "What would you like to buy?" << endl;
        choice = gInput(); //Get the player's choice
        for (int i = 0; i < charms.size(); ++i) { //Search for the selected charm
            if ((choice - 48) == i + 1) { //If the player's choice equals one of the options
                if (user.gold >= charms[i].def * 100) { //If the player can afford their selection
                    //Subtract cost from the player's total gold
                    user.gold -= charms[i].def * 100; 
                    //Equip the newly purchased charm
                    user.eqCharm = charms[i];
                } else { //If the player doesn't have enough gold
                    cout << "You don't have enough gold" << endl;
                }
            }
        }
    } while (choice != '0');
}

/******************************************************************************/
/***********************************Shop Guns**********************************/
/******************************************************************************/
//  Processing for the Gunsmith shopping menu
//Inputs
//  &guns : A vector containing the list of guns that exist in the game
//  &user : The game's player
void shGns(const vector<Gun> &guns, Player &user) {
    //Variables
    char choice; //The player's choice in the menu
    
    dspFile("gunsmith.txt"); //Display flavor text
    cout << "INVENTORY:" << endl;
    for (int i = 0; i < guns.size(); ++i) { //Show inventory
        //Display the gun's name
        cout << "(" << i + 1 << ") " << guns[i].name << endl;
        //Display gun attributes
        cout << '\t' << guns[i].dsc << endl;
        cout << '\t' << "ATK:  " << static_cast<int> (guns[i].atk) << endl;
        cout << '\t' << "AMMO: " << guns[i].ammo << endl;
        cout << '\t' << "COST: " << guns[i].atk * 100 << endl;
    }
    //Special leave option
    cout << "(0) Leave" << endl;
    do { //While the player doesn't want to leave
        cout << "What would you like to buy?" << endl;
        choice = gInput(); //Get the player's choice
        for (int i = 0; i < guns.size(); ++i) {
            if ((choice - 48) == i + 1) { //If the player's choice equals one of the options
                if (user.gold >= guns[i].atk * 100) { //If the player can afford their choice
                    //Subtract cost from the player's total gold
                    user.gold -= guns[i].atk * 100;
                    //Equip the newly purchased charm
                    user.eqGun = guns[i];
                } else { //If the player doesn't have enough gold
                    cout << "You don't have enough gold" << endl;
                }
            }
        }
    } while (choice != '0');
}

/******************************************************************************/
/***********************************Find Gun***********************************/
/******************************************************************************/
//  Linear search a vector for a gun
//Inputs
//  &vec : The vector to search
//  &key : The Gun value to find
//Output
//  An integer representing the position of a Gun value in the vector
//  An output of -1 means not found
int fndGn(const vector<Gun> &vec, const Gun &key) {
    for (int i = 0; i < vec.size(); ++i) { //For every value in a vector
        //Compare all values in a Gun object
        if (vec[i].name == key.name && vec[i].dsc == key.dsc
            && vec[i].ammo == key.ammo && vec[i].atk == key.atk) {
            //Return the position
            return i;
        }
    }
    
    //Return not found
    return -1;
}

/******************************************************************************/
/**********************************Find Charm**********************************/
/******************************************************************************/
//  Linear search a vector for a charm
//Inputs
//  &vec : The vector to search
//  &key : The Charm value to find
//Output
//  An integer representing the position of a Charm value in the vector
//  An output of -1 means not found
int fndChrm(const vector<Charm> &vec, const Charm &key) {
    for (int i = 0; i < vec.size(); ++i) { //For every value in a vector
        //Compare all values in a Charm object
        if (vec[i].name == key.name && vec[i].dsc == key.dsc
            && vec[i].def == key.def) {
            //Return the position
            return i;
        }
    }

    //Return not found
    return -1;
}

/******************************************************************************/
/***********************************Save Game**********************************/
/******************************************************************************/
//  Save game data to a file
//Inputs
//  &user : The game's player
//  &guns : The vector containing the list of guns in the game
//  &charms : The vector containing the list of charms in the game
void svGame(const Player &user, const vector<Gun> &guns,
            const vector<Charm> &charms) {
    //Objects
    string path = user.name + ".sav"; //The path to save to
    ofstream oFile; //The output file
    
    oFile.open(path.c_str()); //Open the file
    oFile << user.name << endl; //Output the user's name
    oFile << static_cast<int> (user.level) << endl; //Output the user's level
    oFile << static_cast<int> (user.hp) << endl; //Output the user's hp
    oFile << fndGn(guns, user.eqGun) << endl; //Output the user's gun
    oFile << fndChrm(charms, user.eqCharm) << endl; //Output the user's charm
    oFile << user.gold << endl; //Output the user's current gold
    oFile.close(); //Close the file
}

/******************************************************************************/
/***********************************Load Game**********************************/
/******************************************************************************/
//  Load game data from a file
//Inputs
//  &user : The game's player
//  &guns : The vector containing the list of guns in the game
//  &charms : The vector containing the list of charms in the game
void ldGame(Player &user, const vector<Gun> &guns, 
            const vector<Charm> &charms) {
    //Variables
    int gun, //The gun to equip to the player
        charm; //The charm to equip to the player
    //Objects
    string path = user.name + ".sav", //The file path
           level, //The player's level as a string
           hp; //The player's hp as a string 
    ifstream iFile; //The input file
    
    iFile.open(path.c_str()); //Open the file
    iFile >> user.name; //Read in the player's name
    iFile >> level; //Read in the level
    //Convert the Level to an integer type
    istringstream cnvLvl(level);
    cnvLvl >> user.level;
    iFile >> hp; //Read in the player's hp
    //Convert the HP to an integer type
    istringstream cnvHp(hp);
    cnvHp >> user.hp;
    iFile >> gun; //Read in gun
    user.eqGun = guns[gun]; //Equip the gun
    iFile >> charm; //Read in charm
    user.eqCharm = charms[charm]; //Equip the charm
    iFile >> user.gold; //Read in the player's gold
    iFile.close(); //Close the file
}

/******************************************************************************/
/***********************************Print Player*******************************/
/******************************************************************************/
//  Print the player's attributes
//Inputs
//  &p : The game's player
void pPlayer(const Player &p) {
    //Output the player's name
    cout << "NAME:  " << p.name << endl;
    //Output the player's level
    cout << "LEVEL: " << static_cast<int> (p.level) << endl;
    //Output the player's hp
    cout << "HP:    " << static_cast<int> (p.hp) << "/"
         << static_cast<int> (gMaxHp(p.level)) << endl;
    //Output the player's current gun
    cout << "GUN:   " << p.eqGun.name << endl;
    //Output the player's ammo
    cout << "AMMO:  " << p.eqGun.cAmmo << "/" << p.eqGun.ammo << endl;
    //Output the player's atk
    cout << "ATK:   " << static_cast<int> (p.eqGun.atk) << endl;
    //Output the player's current charm
    cout << "CHARM: " << p.eqCharm.name << endl;
    //Output the player's def
    cout << "DEF:   " << static_cast<int> (p.eqCharm.def) << endl;
    //Output the player's gold
    cout << "GOLD:  " << p.gold << endl;
}

/******************************************************************************/
/***********************************Load Enemies*******************************/
/******************************************************************************/
//  Load enemy data from a file
//Inputs
//  &guns : The list of guns in the game
//  &charms : The list of charms in the game
//Outputs
//  enemies : a vector containing the loaded enemy data
vector<Player> ldEnms(const vector<Gun> &guns, const vector<Charm> &charms) {
    //Objects 
    string level, //The character's level
           gold, //The character's gold
           charm, //The character's charm
           gun; //The character's gun
    Player temp; //A temporary player value
    ifstream iFile; //The file stream
    //Collection
    vector<Player> enemies; //The vector to return

    iFile.open("enemies.dat"); //Open the file
    while (iFile.good()) { //While the file is good
        getline(iFile, temp.name); //Read in the character's name
        temp.name = trim(temp.name); //Trim the name
        getline(iFile, level); //Read in the level
        //Convert the level from a string to an integer type
        istringstream cnvLvl(level); 
        cnvLvl >> temp.level;
        getline(iFile, gold); //Read in gold
        getline(iFile, charm); //Read in charm
        getline(iFile, gun); //Read in gun
        temp.hp = gMaxHp(temp.level); //Set hp
        //Convert gold from a string to an integer type
        istringstream cnvGold(gold); 
        cnvGold >> temp.gold;
        temp.eqCharm = charms[charm.at(0) - 48]; //Equip the gun
        temp.eqGun = guns[gun.at(0) - 48]; //Equip the charm
        enemies.push_back(temp); //Copy temp to the back of enemies
    }
    iFile.close(); //Close the file

    return enemies;
}

/******************************************************************************/
/***********************************Load Charms********************************/
/******************************************************************************/
//  Load charm data from a file
//Outputs
//  charms : a vector containing the loaded charms data
vector<Charm> ldChrms() {
    //Objects
    string def; //The def value of a charm
    Charm temp; //A temporary charm value
    ifstream iFile; //The file stream
    //Collections
    vector<Charm> charms; //The collection of charms to return

    iFile.open("charms.dat"); //Open the file
    while (iFile.good()) { //While the file is good
        getline(iFile, temp.name); //Read in the name
        getline(iFile, temp.dsc); //Read in the description
        getline(iFile, def); //Read in the def value
        //Convert def from a string to an integer type
        istringstream convert(def);
        convert >> temp.def;
        charms.push_back(temp); //Copy temp to the list of charms
    }
    iFile.close(); //Close the file

    return charms;
}

/******************************************************************************/
/***********************************Load Guns**********************************/
/******************************************************************************/
//  Load gun data from a file
//Outputs
//  guns : a vector containing the loaded gun data
vector<Gun> ldGns() {
    //Objects
    string ammo, //The maximum ammo value
           atk; //The atk value
    Gun temp; //A temporary gun value
    ifstream iFile; //The file stream
    //Collections
    vector<Gun> guns; //The list of guns to return

    iFile.open("guns.dat"); //Open the file
    while (iFile.good()) { //While the file is good
        getline(iFile, temp.name); //Read in the name
        getline(iFile, temp.dsc); //Read in the description
        getline(iFile, ammo); //Read in the ammo
        getline(iFile, atk); //Read in the atk
        //Convert ammo from a string to an integer type
        istringstream cnvAmmo(ammo);
        cnvAmmo >> temp.ammo;
        temp.cAmmo = temp.ammo; //Set current ammo to max ammo
        //Convert atk from a string to an integer type
        istringstream cnvAtk(atk);
        cnvAtk >> temp.atk;
        guns.push_back(temp); //Copy temp to the back of the guns collection
    }
    iFile.close(); //Close file

    return guns;
}

/******************************************************************************/
/*********************************Get Max Hp***********************************/
/******************************************************************************/
//  Get the maximum hp value for the current level of a character
//Inputs
//  level : The level to find the max hp for
//Outputs
//  The max hp for the input level as calculated by the formula
//  100 * (1 + 0.5)^level
short gMaxHp(unsigned short level) {
    const unsigned char BASEHP = 100; //The minimum hp value
    const float RATE = 0.05f; //The growth rate per level

    return BASEHP * (pow((1 + RATE), level));
}

/******************************************************************************/
/*********************************Get Input************************************/
/******************************************************************************/
//  Get a single character of input from the user
//Outputs
//  The character input by the user uppercased if possible
char gInput() {
    //Objects
    string input; //The user's input
    
    //Basic input processing
    cout << "> ";
    cin >> input;

    //Return the first character of the input uppercased
    return toupper(input.at(0));
}

/******************************************************************************/
/*****************************Get String Input*********************************/
/******************************************************************************/
//  Get a string as input from the user
//Outputs
//  The input string
string gInStr() {
    //Objects
    string input; //The input value
    
    //Basic input processing
    cout << "> ";
    cin >> input;

    return input;
}

/******************************************************************************/
/*********************************Get Choices**********************************/
/******************************************************************************/
//  Get an array of valid choices given an array of strings
//Inputs
//  output[] : The array to output to
//  input[] : The list of strings to process
//  length : The length of the input and output arrays
//Outputs
//  output[] : The output array filled with the first letter of each string value
void gChoice(char output[], const string input[], int length) {
    for (int i = 0; i < length; ++i) { //For each string value
        output[i] = toupper(input[i].at(0)); //Set the output to the uppercase of the first character of the input
    }
}

/******************************************************************************/
/************************************Pause*************************************/
/******************************************************************************/
//  Pause the game and wait for user input to continue
void pause() {
    cin.ignore(); //Clear the input
    cout << "Press Enter to continue..."; //Display instructions
    cin.get(); //Wait for input
}

/******************************************************************************/
/*******************************Format Option**********************************/
/******************************************************************************/
//  Format menu options for display
//Inputs
//  &opt : The string to format
//Outputs
//  r : The string formated so that the first character is wrapped in ()s
string frmtOpt(const string &opt) {
    string r = opt; //Set the return to the input string

    r.insert(0, 1, '('); //Insert an open paren
    r.insert(2, 1, ')'); //Insert a close paren

    return r;
}

/******************************************************************************/
/************************************Reload************************************/
/******************************************************************************/
//  Reload a player's weapon
//Inputs
//  &p : The player to reload
void reload(Player &p) {
    p.eqGun.cAmmo = p.eqGun.ammo; //Set current ammo to max ammo
}

/******************************************************************************/
/**********************************Show Menu***********************************/
/******************************************************************************/
//  Display a menu and record input on that menu
//Inputs
//  opts[] : The options to display
//  length : The length of the option array
//Outputs
//  input : the user input choice
char shwMenu(const string opts[], int length) {
    //Variables
    bool invalid = true; //Whether the input is valid or not
    char input; //The input character
    char choices[length] = {0}; //The array of valid choices
    
    gChoice(choices, opts, length); //Initialize choices
    for (int i = 0; i < length; ++i) { //For each option
        //Output the option formatted and sized correctly
        cout << setw(opts[i].length() + 5) << frmtOpt(opts[i]);
    }
    cout << endl;
    do { //While the input is not valid
        input = gInput();
        for (int i = 0; i < length; ++i) { //For each choice
            if (choices[i] == input) { //If the input is a choice
                invalid = false; //The input is valid
            }
        }
    } while (invalid);

    return input;
}

/******************************************************************************/
/********************************Bounty Board**********************************/
/******************************************************************************/
//  Display the bounty board menu and process it
//Inputs
//  &enemies : The list of enemies in the game
//  &bounty : The position of the chosen bounty in the enemies list
//Outputs
//  &bounty : The position after being set
void bBoard(const vector<Player> &enemies, int &bounty) {
    //Variables
    char choice; //The player's choice of bounty
    //Collections
    string menu[enemies.size()]; //The menu array

    for (int i = 0; i < enemies.size() - 1; ++i) { //Fill the menu array
        menu[i] = enemies[i].name + '\n'; //Format the menu to display vertically
    }
    choice = shwMenu(menu, enemies.size() - 1); //Display menu and get choice
    for (int i = 0; i < enemies.size() - 1; ++i) { //Check to see if the input is a choice
        if (choice == toupper(menu[i].at(0))) {
            //Show your choice
            cout << "You choose to hunt " << enemies[i].name << endl;
            //Set bounty
            bounty = i;
        }
    }
}

/******************************************************************************/
/***********************************Load Words*********************************/
/******************************************************************************/
//  Load a word list
//Inputs
//  *words : A pointer to an array of strings
//  length : The length of the pointed to array
//Outputs
//  *words : The array after being filled with words
void ldWrds(string *words, int length) {
    //Objects
    ifstream iFile; //The file stream

    iFile.open("wdlcur.txt"); //Open the file
    for (int i = 0; iFile >> *(words + i); ++i); //Input the current file line into the array
    iFile.close(); //Close the file
}

/******************************************************************************/
/**************************************Guess***********************************/
/******************************************************************************/
//  Play hangman from the computer player's perspective
//Inputs
//  word : The word to try to guess
//  &p : The computer character guessing the word
//Outputs
// true if guessed or false if failed
bool guess(string word, Player &p) {
    //Constants
    const int ALPHAS = 26, //Alphabet size
              LS = 2; //List size
    //Variables
    unsigned short gCount = p.eqCharm.def, //The number of guesses the character gets
                   total; //The total number of letters in the frequency list
    //Objects
    string mWord = mask(word); //The masked version of the word to guess
    ifstream iFile; //The file stream
    unsigned short lFreq[ALPHAS][LS]; //2d array of letters and frequencies

    //Read the frequency data
    iFile.open("freq.dat"); //Open frequency data file
    for (int i = 0; i < ALPHAS; ++i) { //For each cell in lFreq
        lFreq[i][0] = i; //Set the first value to the current value of i
        iFile >> lFreq[i][1]; //Set the second value to the frequency of the corresponding letter
    }
    iFile.close(); //Close the frequency data file

    //Calculate total of frequency data
    for (int i = 0; i < ALPHAS; ++i) {
        total += lFreq[i][1];
    }
    
    //Dyanmically allocate a character array to pick guesses from
    char *gList = new char[total];

    //Initialize the guess list
    for (int i = 0; i < total; ++i) {
        gList[i] = 0;
    }

    //Fill the guess list
    string temp; //Create a temporary string
    for (int i = 0; i < ALPHAS; ++i) { //For each letter in the alphabet
        for (int j = 0; j < lFreq[i][1]; ++j) { //For the frequency of that character
            temp += static_cast<char> (lFreq[i][0] + 97); //Write that character to the temporary string
        }
    }
    strcpy(gList, temp.c_str()); //Copy the temporary string to the guess list
    temp.clear(); //Clear the temporary string

    //Preform guesses
    cout << "OPPONENTS GUESSES: ";
    for (int i = gCount; i > 0;) {
        char guess = gList[rand() % total]; //Guess a random character from the guess list
        cout << guess; //Output the guess
        if (cntns(word, guess)) { //If the word contains the guess
            unmask(word, mWord, guess); //Unmask the character
        } else { //Else subtract for guess
            --i;
        }
        if (mWord == word) { //If the masked word and the guess word match
            cout << endl;
            delete [] gList; //Delete the guess list
            return true;
        }
    }
    cout << endl;

    delete [] gList; //Delete the guess list
    return false;
}

/******************************************************************************/
/*************************************Trim*************************************/
/******************************************************************************/
// Trim a string so that it does not contain nonprinting characters
//Inputs
//  str : The string to trim
//Outputs
// r : The trimmed string
string trim(string str) {
    string r;

    for (int i = 0; i < str.size(); ++i) { //For each character in str
        if (str.at(i) > 31 && str.at(i) < 127) { //Copy the character if it is printable
            r += str.at(i);
        }
    }

    return r;
}

/******************************************************************************/
/***********************************Is Word************************************/
/******************************************************************************/
//  Checks if a string only contains alphabetic characters
//Inputs
//  word : the string to check
//  length : the length of the input string
//Outputs
//  true if the string only contains alphabetic characters
//  false if the string contains non alphabetic characters

bool isWord(string word) {
    for (int i = 0; i < word.size(); ++i) { //loop through every character in word
        if (word.at(i) < 96 || word.at(i) > 123) {
            return false;
        } //if word only contains alphabetic characters
    }
    return true;
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

void toLCase(string &word) {
    for (int i = 0; i < word.size(); ++i) {
        word.at(i) == tolower(word.at(i));
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
            do {
                uWord = gInStr();
                toLCase(uWord);
            } while (!isWord(uWord));
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