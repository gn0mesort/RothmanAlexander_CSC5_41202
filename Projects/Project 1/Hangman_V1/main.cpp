/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 *
 * Created on January 26, 2016, 10:27 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void clearbuffer(void); //Blank a terminal window by printing 1000 new lines
bool isword(string); //Check if a string contains only alphabetic characters
bool contains(string, char); //Check if a string contains a character
string tocaps(string); //Convert a whole string to upper case
string mask(string, char); //mask a string with a specific character
string unmask(string, string, char); //unmask characters one by one
string replace(string, int, char); //replace a character in a string at a position

//Begin Execution
int main(int argc, char** argv) {
    //Declaration and Initialization
    char cPlay, //Indicates whether or not to continue playing
         guess; //The current guess
    unsigned char gCount = 6; //The number of guesses remaining
    string word, //The actual word
            dsp; //The displayed string
    
    //Game Loop
    do {
        //Word Input
        do {
            cout << "INPUT A WORD: ";
            cin >> word;
        } while (!isword(word));
        dsp = mask(word, '_');
        
        //Clear the screen
        clearbuffer();
        
        //Guess Loop
        do {
            cout << "REMAINING GUESSES: " << static_cast<int> (gCount) << endl;
            cout << dsp << endl;
            cout << "GUESS: ";
            cin >> guess;
            if (contains(word, guess)) {
                dsp = unmask(dsp, word, guess);
            } else {
                --gCount;
            }
        } while (gCount > 0 && dsp != word);
        //Check if the program should continue
        cout << dsp << endl;
        cout << "CONTINUE PLAYING? (Y/N) ";
        cin >> cPlay;

    } while (toupper(cPlay) == 'Y');

    //Exit
    return 0;
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
