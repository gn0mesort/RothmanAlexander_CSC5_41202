/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Star Search
 * Created on February 3, 2016, 8:20 AM
 */

#include <iostream>
#include <iomanip>


using namespace std;

void gJdgDat(float[], char);
void calcScr(float[], char);
int fndHigh(float[], char);
int fndLow(float[], char);

int main(int argc, char** argv) {
    const char JUDGES = 5;
    float scores[JUDGES];
    
    gJdgDat(scores, JUDGES);
    calcScr(scores, JUDGES);
    
    return 0;
}

void gJdgDat(float scores[], char length){
    cout << "Input the scores for each judge. Scores are between 0 and 10" 
         << endl;
    for(int i = 0; i < length; ++i){
        do{
            cout << "JUDGE " << i + 1 << ": ";
            cin >> scores[i];
        } while(scores[i] < 0.0f && scores[i] > 10.0f);
    }
}

void calcScr(float scores[], char length){
    const float NOCOUNT = -1.0f;
    float total = 0.0f;
    
    scores[fndHigh(scores, length)] = NOCOUNT;
    scores[fndLow(scores, length)] = NOCOUNT;
    
    for(int i = 0; i < length; ++i){
        if(scores[i] != NOCOUNT){
            total += scores[i];
        }
    }
    cout << fixed << setprecision(2) << showpoint;
    cout << "FINAL SCORE: " << total / (length - 2) << endl;
    
}

int fndHigh(float scores[], char length){
    float highest = 0;
    int highPos = 0;
    for (int i = 0; i < length; ++i){
        if(scores[i] >= highest){
            highest = scores[i];
            highPos = i;
        }
    }
    
    return highPos;
}

int fndLow(float scores[], char length){
    float lowest = 0;
    int lowPos = 0;
    for (int i = 0; i < length; ++i){
        if(scores[i] <= lowest){
            lowest = scores[i];
            lowPos = i;
        }
    }
    
    return lowPos;
}