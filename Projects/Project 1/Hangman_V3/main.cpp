/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 *
 * Created on January 28, 2016, 9:28 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//User Libraries

//Global Constants

//Function 
void gsort(char[], int);
void savescores(string, unsigned short, unsigned short);
unsigned char choosedifficulty();
bool playgame(char, string);
void displayfile(string);
void clearbuffer(void); //Blank a terminal window by printing 1000 new lines
bool isword(string); //Check if a string contains only alphabetic characters
bool contains(string, char); //Check if a string contains a character
string tocaps(string); //Convert a whole string to upper case
string mask(string, char); //mask a string with a specific character
string unmask(string, string, char); //unmask characters one by one
string replace(string, int, char); //replace a character in a string at a position
string getword(string);
char getguess(void);
int countfilelines(string);
char menu(void);

//Begin Execution

int main(int argc, char** argv) {
    //Declaration and Initialization
    const char SCORES[] = "scores.dat",
               HELP[] = "help.txt",
               WORDS[] = "words.txt";
    
    bool quit = false;
    char diff;
    unsigned short wins = 0,
                   tGames = 0;
    float wlr;

    srand(static_cast<int> (time(0))); //Seed PRNG

    //Game Loop
    do {
        switch (menu()) {
            case 'P':
            {

                wins += playgame(choosedifficulty(), WORDS);
                ++tGames;
                wlr = static_cast<float> (wins) / tGames;
                break;
            }
            case 'S':
            {
                cout << "CURRENT SCORE: " << wins << " WINS " << tGames - wins
                        << " LOSSES" << endl;
                cout << "TOTAL GAMES:   " << tGames << endl;
                cout << "RATIO:         " << wlr << endl;
                displayfile(SCORES);
                break;
            }
            case 'H':
            {
                displayfile(HELP);
                break;
            }
            case 'Q':
            {
                savescores(SCORES, wins, tGames);
                quit = true;
                break;
            }
        }
    } while (!quit);

    //Exit
    return 0;
}

void gsort(char cArr[], int length){
    for(int pos = 1, last = 0; pos < length;){
        if(cArr[pos] >= cArr[pos - 1] && cArr[pos] != '\0'){
            if(last != 0){
                pos = last;
                last = 0;
            }
            ++pos;
        }
        else{
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
            cArr[pos - 1] = cArr[pos] ^ cArr[pos -1];
            cArr[pos] = cArr[pos] ^ cArr[pos - 1];
        }
    }
}

void savescores(string path, unsigned short wins, unsigned short tGames) {
    ofstream ofile;

    if (tGames != 0) {
        ofile.open(path, fstream::app);
        ofile << "SCORE: " << wins << " : " << tGames - wins << endl;
        ofile.close();
    }
}

unsigned char choosedifficulty() {
    const unsigned char DIFF_E = 1,
                        DIFF_M = 2,
                        DIFF_H = 4;
    char choice;
    char input[7];
    cout << "CHOOSE A DIFFICULTY: " << endl;
    cout << "(E)ASY" << endl;
    cout << "(M)edium" << endl;
    cout << "(H)ard" << endl;
    do {
        cout << "> ";
        cin >> input;
        choice = toupper(input[0]);
    } while (!(choice != 'E' || choice != 'M' || choice != 'H'));
    switch (choice) {
        case 'E': return DIFF_E;
        case 'M': return DIFF_M;
        case 'H': return DIFF_H;
    }
}

int countfilelines(string path) {
    int counter = 0;
    string temp;
    ifstream ifile;

    ifile.open(path);
    while (ifile >> temp) {
        ++counter;
    }
    ifile.close();

    return counter;
}

bool playgame(char diff, string wdlist) {
    const unsigned char DGUESS = 24,
                        ALPHALEN = 27;
    unsigned char gCount;
    char guess,
         usedPos = 0;
    string oWord,
           mWord;
    char cUsed[ALPHALEN] = {};

    oWord = getword(wdlist);
    mWord = mask(oWord, '_');
    gCount = DGUESS / diff;

    do {
        cout << mWord << endl;
        cout << "REMAINING GUESSES: " << static_cast<int> (gCount) << endl;
        cout << "USED CHARACTERS:" << endl;
        cout << cUsed << endl;
        guess = getguess();
        if (contains(oWord, guess)) {
            mWord = unmask(mWord, oWord, guess);
        } else {
            --gCount;
        }
        cUsed[usedPos] = guess;
        if(usedPos++ > 0){
        gsort(cUsed, ALPHALEN);
        }
    } while (gCount > 0 && mWord != oWord);

    cout << oWord << endl;
    if (gCount > 0) {
        cout << "YOU WIN!" << endl;
        return true;
    } else {
        cout << "YOU LOSE!" << endl;
        return false;
    }
}

void displayfile(string path) {
    string next;
    ifstream ifile;

    ifile.open(path);
    while (getline(ifile, next, '\n')) {
        cout << next << endl;
    }
    ifile.close();
}

bool isword(string word) {
    word = tocaps(word);
    for (int i = 0; i < word.length(); ++i) {
        if (word.at(i) < 65 || word.at(i) > 90) {
            return false;
        }
    }
    return true;
}

string tocaps(string word) {
    string upCase;

    for (int i = 0; i < word.length(); ++i) {
        upCase += toupper(word.at(i));
    }

    return upCase;
}

void clearbuffer() {
    for (int i = 0; i < 1000; ++i) {
        cout << endl;
    }
}

string mask(string word, char mChar) {
    string masked;

    for (int i = 0; i < word.length(); ++i) {
        masked += mChar;
    }

    return masked;
}

bool contains(string word, char cChar) {
    for (int i = 0; i < word.length(); ++i) {
        if (word.at(i) == cChar) {
            return true;
        }
    }

    return false;
}

string unmask(string mWord, string aWord, char gChar) {
    for (int i = 0; i < aWord.length(); ++i) {
        if (aWord.at(i) == gChar) {
            mWord = replace(mWord, i, gChar);
        }
    }

    return mWord;
}

string replace(string word, int pos, char repChar) {
    string r;
    for (int i = 0; i < word.length(); ++i) {
        if (i == pos) {
            r += repChar;
        } else {
            r += word.at(i);
        }
    }

    return r;
}

string getword(string path) {
    int fLnCnt;
    string word;
    ifstream iwords;

    fLnCnt = countfilelines(path);
    iwords.open(path);
    for (int i = 0; i < rand() % fLnCnt; ++i) {
        iwords >> word;
    }
    iwords.close();

    return tocaps(word);
}

char getguess() {
    char input[2];
    do {
        cout << "GUESS: ";
        cin >> input;
        input[0] = toupper(input[0]);
    } while (input[0] < 'A' && input[0] > 'Z');

    return input[0];
}

char menu() {
    char choice;
    string input;
    cout << "(P)lay (S)cores (H)elp (Q)uit" << endl;
    do {
        cout << "> ";
        cin >> input;
        choice = toupper(input.at(0));
    } while (!(choice != 'P' || choice != 'S' || choice != 'H' || choice != 'Q'));

    return choice;
}


