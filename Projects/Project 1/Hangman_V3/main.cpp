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
bool isword(const char[], int); //Determine if a string is a word
bool contains(const char[], int, char); //Determine if a string contains a character
void displayfile(const char[]); //Display file data line by line
int countlines(const char[]); //Count the number of lines in a file
void mask(int, const char[], char[], char); //Creates a masked version of the input word
void unmask(int, const char[], char[], char); //Unmasks a specific character based on the original word
bool isequal(const char[], const char[], int);
//Game Functions
void readoptions(unsigned char&, unsigned char&, const char[]);
void saveoptions(unsigned char, unsigned char, const char[]);
void showscores(short, short, short, float, const char[]);
void savescores(short, short, short, float, const char[]);
char menu(void); //Do the basic game menu processing
bool playgame(unsigned char, unsigned char); //Do the game processing
void options(unsigned char&, unsigned char&);
void getword(unsigned char, char[], int&); //Get a word from the corresponding word list at random

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    const char SCORES[] = "scores.dat",
               CONFIG[] = "config.dat";
    const unsigned char DIFF_E = 1, //Easy Difficulty
                        DIFF_M = 2, //Medium Difficulty
                        DIFF_H = 4; //Hard Difficulty
    bool quit = false; //Determine whether or not to quit the game
    unsigned char diff = DIFF_E, //Current difficulty
                  mChar = '_';
    unsigned short win, //Number of wins
                   lose, //Number of losses
                   tGames; //Total number of games
    float wlr = 0.0f;
    
    srand(static_cast<int>(time(0))); //Seed PRNG
    readoptions(diff, mChar, CONFIG);
    
    //Game Loop
    do{
        switch(menu()){ //Choose the input from the menu display
            case 'P': //Play the game
            {
                playgame(diff, mChar) ? ++win : ++lose;
                ++tGames;
                wlr =  lose != 0 ? static_cast<float>(win) / lose 
                                 : static_cast<float>(win) / (lose + 1);
                break;
            }
            case 'S': //Display Scores
            {
                showscores(win, lose, tGames, wlr, SCORES);
                break;
            }
            case 'O': //Display Options
            {
                options(diff, mChar);
                break;
            }
            case 'Q': //Quit
            {
                saveoptions(diff, mChar, CONFIG);
                savescores(win, lose, tGames, wlr, SCORES);
                quit = true;
            }
        }
    } while(!quit);
    
    //Exit
    return 0;
}

void readoptions(unsigned char &diff, unsigned char &mChar, const char path[]){
    char input[3] = {0};
    ifstream iFile;
    
    iFile.open(path);
    iFile.getline(input, 3, '\n');
    diff = input[0];
    iFile.getline(input, 3, '\n');
    mChar = input[0];
}

void saveoptions(unsigned char diff, unsigned char mChar, const char path[]){
    ofstream oFile;
    
    oFile.open(path);
    oFile << diff << endl;
    oFile << mChar << endl;
    oFile.close();
}

void options(unsigned char &diff, unsigned char &mChar){
    char choice;
    char input[15] = {0};
    cout << "Options:" << setw(20) << "(D)ifficulty" 
         << setw(20) << "(M)ask Character" << setw(10) << "(H)elp" << endl;
    do{
        cout << "> ";
        cin >> input;
        choice = toupper(input[0]);
    } while(choice != 'D' && choice != 'M' && choice != 'H');
    switch(choice){
        case 'D':
        {
            char temp;
            cout << "CURRENT DIFFICULTY: ";
            if(diff == 1){
                cout << "EASY" << endl;
            }
            else if (diff == 2){
                cout << "MEDIUM" << endl;
            }
            else{
                cout << "HARD" << endl;
            }
            cout << "Modes: " << "(E)asy (M)edium (H)ard" << endl; 
            do{
                cout << "> ";
                cin >> input;
                temp = toupper(input[0]);
            }while(temp != 'E' && temp != 'M' && temp != 'H');
                switch(temp){
                    case 'E':
                    {
                        diff = 1;
                        break;
                    }
                    case 'M':
                    {
                        diff = 2;
                        break;
                    }
                    case 'H':
                    {
                        diff = 4;
                        break;
                    }
                }
            cout << "CURRENT DIFFICULTY: ";
            if(diff == 1){
                cout << "EASY" << endl;
            }
            else if (diff == 2){
                cout << "MEDIUM" << endl;
            }
            else{
                cout << "HARD" << endl;
            }
            break;
        }
        case 'M':
        {
            cout << "CURRENT MASK CHARACTER: " << mChar << endl;
            do{
                cout << "> ";
                cin >> input;
                if((input[0] > ' ' && input[0] < 'A') || 
                   (input[0] > 'Z' && input[0] < 'a') || 
                   (input[0] > 'z' && input[0] < 127)){
                    mChar = input[0];
                }
                else{
                    cout << "> INVALID INPUT" << endl;
                }
            } while((input[0] < ' ' && input[0] > 'A') || 
                    (input[0] < 'Z' && input[0] > 'a') || 
                    (input[0] < 'z' && input[0] > 127));
            cout << "CURRENT MASK CHARACTER: " << mChar << endl;
            break;
        }
        case 'H':
        {
            displayfile("help.dat");
            break;
        }
    }
}

void savescores(short win, short lose, short tGames, float wlr, 
                const char path[]){
    ofstream oFile;
    time_t rawTime;
    if(tGames > 0){
        time(&rawTime);
    
        oFile.open(path, fstream::app);
        oFile << ctime(&rawTime) << "SCORES: " << win << " : " << lose << endl;
        oFile << "TOTAL GAMES: " << tGames << endl;
        oFile << "RATIO: " << wlr << endl;
        oFile.close();
    }
}

void showscores(short win, short lose, short tGames, float wlr, 
                const char path[]){
    cout << "CURRENT GAME:" << endl;
    cout << "SCORES: " << win << " : " << lose <<  endl;
    cout << "TOTAL GAMES: " << tGames << endl;
    cout << "RATIO: " << wlr << endl;
    displayfile(path);
}

bool isequal(const char word1[], const char word2[], int length){
    for(int i = 0; i < length; ++i){
        if(word1[i] != word2[i] && word1[i] != '\0'){
            return false;
        }
    }
    return true;
}

void unmask(int length, const char word[], char mWord[], char guess){
    for(int i = 0; i < length; ++i){
        if(word[i] == guess){
            mWord[i] = guess;
        }
    }
}

int countlines(const char path[]){
    int counter = 0;
    char temp[256];
    ifstream ifile;

    ifile.open(path);
    while (ifile >> temp) {
        ++counter;
    }
    ifile.close();

    return counter;
}

void mask(int length, const char word[], char mWord[], char mChar){
    for(int i = 0; i < length; ++i){
        if(word[i] != '\0'){
        mWord[i] = mChar;
        }
    }
}

void getword(unsigned char diff, char buffer[], int& length){
    const unsigned char E_LNGTH = 7,
                        M_LNGTH = 12,
                        H_LNGTH = 14;
    const char E_LIST[] = "wdleasy.txt",
               M_LIST[] = "wdlmedium.txt",
               H_LIST[] = "wdlhard.txt";
    int lnCount;
    ifstream iFile;
    
    if (diff == 1){
        iFile.open(E_LIST);
        lnCount = countlines(E_LIST);
        int target = rand() % lnCount;
        for(int i = 0; i < target; ++i){
            iFile >> buffer;
        }
        iFile.close();
        length = E_LNGTH;
    }
    else if (diff == 2){
        iFile.open(M_LIST);
        lnCount = countlines(M_LIST);
        int target = rand() % lnCount;
        for(int i = 0; i < target; ++i){
            iFile >> buffer;
        }
        iFile.close();
        length = M_LNGTH;
    }
    else{
        iFile.open(H_LIST);
        lnCount = countlines(H_LIST);
        int target = rand() % lnCount;
        for(int i = 0; i < target; ++i){
            iFile >> buffer;
        }
        iFile.close();
        length = H_LNGTH;
    }
}

bool playgame(unsigned char diff, unsigned char mChar){
    const unsigned char GMAX = 24,
                        WDLNGTH = 20,
                        ALPHA = 28;
    char gCount = GMAX / diff,
         usedPos = 0,
         guess;
    int length;
    char word[WDLNGTH] = {0},
         mWord[WDLNGTH] = {0},
         used[ALPHA] = {0};
         
    getword(diff, word, length);
    mask(length, word, mWord, mChar);
    
    do{
        char input[2];
        cout << mWord << endl;
        cout << "REMAINING GUESSES:" << static_cast<int>(gCount) << endl;
        cout << "USED CHARACTERS: " << used << endl;
        cout << "> ";
        cin >> input;
        guess = tolower(input[0]);
        if(contains(word, WDLNGTH, guess)){
            unmask(length, word, mWord, guess);
        }
        else{
            --gCount;
        }
        if(!contains(used, ALPHA, guess)){
            used[usedPos++] = guess;
            gsort(used, ALPHA);
        }
    } while(!isequal(word, mWord, WDLNGTH) && gCount > 0);
    cout << "ANSWER: " << word << endl;
    if(isequal(word, mWord, WDLNGTH)){
        cout << "YOU WIN!" << endl;
        return true;
    }
    else{
        cout << "YOU LOSE!" << endl;
        return false;
    }
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
    const char TITLE[] = "gametitle.txt"; //File containing game title text
    char choice; //The user's choice
    char input[8] = {0}; //The string input by the user to cut the choice from
    
    displayfile(TITLE); //Display the title file
    //Display the game menu
    cout << "Menu:" << setw(15) << "(P)lay" << setw(15) << "(S)cores" 
         << setw(15) << "(O)ptions" << setw(10) << "(Q)uit" << endl;
    
    do{ //Input validation
        //Read in input
        cout << "> ";
        cin >> input;
        //Chop choice from input
        choice = toupper(input[0]);
        //Display error message
        if(choice != 'P' && choice != 'S' && choice != 'O' && choice != 'Q'){
            cout << "> Invalid Input. Please input (P), (S), (O), or (Q) without parentheses" 
                 << endl;
        }
    } while(choice != 'P' && choice != 'S' && choice != 'O' && choice != 'Q');

    
    return choice;
}

bool contains(const char word[], int length, char key){
    for(int i = 0; i < length; ++i){
        if(word[i] == key){ return true; }
    }
    return false;
}

bool isword(const char word[], int length){
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
