/*
 * Scrabble.cpp
 *
 *  Created on: Oct 5, 2019
 *      Author: natedogg
 */

#include "Scrabble.h"


using namespace std;



Scrabble::Scrabble() {
	// TODO Auto-generated constructor stub

}

Scrabble::~Scrabble() {
	// TODO Auto-generated destructor stub
}

int getUserInput(int userInput, int z = 5){
	cout << "Enter a number: " <<endl;
	cin>>userInput;
	cout<<"Your number is: " << userInput << endl;
	cout<<"We've modified it to: " << userInput*z << endl;
	return userInput;
}

int main(){

	cout << getUserInput(7) << endl;
}



