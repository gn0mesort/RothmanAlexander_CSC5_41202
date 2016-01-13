/* 
 * File:   main.cpp
 * Author: Alexander Rothman
 * Purpose: Don't bother playing the lottery
 * Created on January 11, 2016, 10:36 AM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
	//Declaration and Initialization
	char isMry; //Y or y if married otherwise not married
	unsigned int jackpot, //The current jackpot in dollars
                     actVal; //The actual value you will receive
	float lmpSum, //The lump sum penalty
	      tax, //The percentage collected as taxes
	      marPen; //The split if you're married
	
	//Input Data
	cout << "Input the current jackpot: $";
	cin >> jackpot;
	cout << "Input the lump sum penalty: ";
	cin >> lmpSum;
	cout << "Input the tax penalty: ";
	cin >> tax;
	cout << "Are you married? (Y/N) ";
	cin >> isMry;
	if (isMry == 'y' || isMry == 'Y'){ //Check if married
		cout << "Input the percentage your spouse will receive: ";
		cin >> marPen;
	}
	
	//Calculate Output
	actVal = lmpSum * tax * jackpot; //Calculation if not married
	if (isMry == 'y' || isMry == 'Y'){ //Extra calculation if married
		actVal *= marPen;
	}
	
	//Output results
	cout << "The total you will receive is: $" << actVal;
	
	//Exit
	return 0;
}

