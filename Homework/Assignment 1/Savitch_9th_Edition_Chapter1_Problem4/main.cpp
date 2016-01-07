/* 
 * File:   main.cpp
 * Author: Alexander
 * Purpose: Calculate how far an object will fall based on a random time
 * Created on January 5, 2016, 6:06 PM
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib> //Random function location
#include <cmath> //Math functions
#include <ctime> //Time for seeding rand()
#include <iomanip> //I/O formatting library
#include <fstream> //File I/O Library

using namespace std;

//User Libraries

//Global Constants
const float GRAVITY = 32.174f; //The acceleration in feet / second^2 at sea level on Earth

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Set PRNG Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration and Initialization
    float time, //The time in seconds
          dist; //The distance in feet
    ofstream out; //The output file stream
            
    //Input Data
    time = rand() % 11 + 10; //Set the time to a random number between 10 and 20 seconds
    const int SIZE = 21;
    char fileNam[SIZE] = "dropdistance.dat";
    
    out.open(fileNam);
    
    //Calculate Output
    dist = (0.5f * GRAVITY) * (time * time); //distance = acceleration * time^2 / 2
    
    //Output Results
    cout << "Acceleration:" << setw(16) <<  GRAVITY << " feet / second" << endl;
    cout << "Drop Time:" << setw(15) << time << " seconds" << endl;
    cout << "Free Fall Distance x2:" << fixed << setprecision(3) << showpoint //Format distance to 3 decimal places
         <<  setw(9) << dist << " feet" << endl;
    cout << endl;
    
    //Calculate Output
    dist = (0.5f * GRAVITY) * pow(time, 2); //distance = acceleration * time^2 / 2
    
    //Output Results
    cout << "Acceleration:" << setw(17) <<  GRAVITY << " feet / second" << endl;
    cout << "Drop Time:" << setw(16) << static_cast<int>(time) 
         << " seconds" << endl;
    cout << "Free Fall Distance pow:" << fixed << setprecision(3) << showpoint //Format distance to 3 decimal places
         <<  setw(9) << dist << " feet" << endl;
    cout << endl;
    
    //Calculate Output
    dist = (0.5f * GRAVITY) * exp(2 * log(time)); //distance = acceleration * time^2 / 2
    
    //Output Results
    cout << "Acceleration:" << setw(22) <<  GRAVITY << " feet / second" << endl;
    cout << "Drop Time:" << setw(21) << static_cast<int>(time) 
         << " seconds" << endl;
    cout << "Free Fall Distance exp(log):" << fixed << setprecision(3) //Format distance to 3 decimal places
         << showpoint <<  setw(9) << dist << " feet" << endl;
    
    //Calculate Output
    dist = (0.5f * GRAVITY) * (time * time); //distance = acceleration * time^2 / 2
    
    //Output Results (to file)
    out << "Acceleration:" << setw(13) <<  GRAVITY << " feet / second" << endl;
    out << "Drop Time:" << setw(12) << time << " seconds" << endl;
    out << "Free Fall Distance:" << fixed << setprecision(3) << showpoint //Format distance to 3 decimal places
        <<  setw(9) << dist << " feet" << endl;
    
    //Exit
    out.close(); //Close files
    return 0;
}

