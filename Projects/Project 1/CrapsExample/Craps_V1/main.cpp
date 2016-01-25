/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Craps Game
 * Created on January 25, 2016, 11:01 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declaration and Initialization
    const ;unsigned short GAMES = 36000;
    unsigned char die1, //The first die
            die2, //The second die
            sum; //The sum of both dies
    unsigned short frq2 = 0, //Frequencies
            wins = 0,
            losses = 0,
            total;


    srand(static_cast<int> (time(0))); //Seed PRNG

    //Calculate Output
    for (int i = 0; i < GAMES; ++i) {
        die1 = (rand() % 6) + 1; //Generate die 1
        die2 = (rand() % 6) + 1; //Generate die 2

        sum = die1 + die2;

        if (sum == 7 || sum == 11) { //First round win
            ++wins;
        } else if (sum == 2 || sum == 3 || sum == 12) { //First round loss
            ++losses;
        } else {
            bool cont = true; //Loop control
            unsigned short sum2; //The sum of the next dice roll
            do { //Keep rolling
                die1 = (rand() % 6) + 1; //Generate die 1
                die2 = (rand() % 6) + 1; //Generate die 2

                sum2 = die1 + die2; //Calculate the sum of the next roll

                if (sum == sum2) { //Nth round win
                    ++wins;
                    cont = false;
                }
                else if (sum2 == 7) { //Nth round loss
                    ++losses;
                    cont = false;
                }

            } while (cont);
        }
    }

    //Calculate total wins
    total = wins + losses;
    //Output Results
    cout << "TOTAL GAMES: " << total << endl;

    //Win Frequencies
    cout << "WINS:   " << wins << endl;
    cout << "LOSSES: " << losses << endl;
    cout << fixed << setprecision(2) << showpoint;
    cout << "RATIO:  " << (1.0f * wins) / total;

    //Exit
    return 0;
}

