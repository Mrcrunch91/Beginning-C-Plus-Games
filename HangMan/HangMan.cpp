/*
 * HangMan.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: natedogg
 */

#include "HangMan.h"

using namespace std;

HangMan::HangMan() {
	// TODO Auto-generated constructor stub

}

HangMan::~HangMan() {
	// TODO Auto-generated destructor stub
}

int startGame(const string, int, string, const int);
char playerGuess();
bool checkGuess(const string THE_WORD, char guess);


int main(){

	const int MAX_WRONG = 8;

	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(),'_');
	string used = "";

	cout << "Welcome to Hangman. Good luck!\n" << endl;

	wrong = startGame(THE_WORD, wrong, used, MAX_WRONG);


	if(wrong == MAX_WRONG){
		cout << "\nYou've been hanged";
	}else{
		cout << "\nYou guessed it!";
	}

	cout << "\n The word was " << THE_WORD << endl;
	return 0;
}

int startGame(const string THE_WORD, int wrong, string used, const int MAX_WRONG){

	string soFar(THE_WORD.size(),'_');

	while((wrong < MAX_WRONG) && (soFar != THE_WORD)){
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout <<" incorrect guesses left.\n" << endl;
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout <<"\nSo far, the word is:\n" << soFar << endl;

		char guess;
		guess = toupper(playerGuess()); // make uppercase since secret word in uppercase

		while(used.find(guess) != string::npos){
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if(checkGuess(THE_WORD,guess)){
			cout << "That's right! " << guess << " is in the word.\n";

			//update soFar to include newly guessed letter
			for(string::size_type i = 0; i < THE_WORD.length(); ++i){
				if(THE_WORD[i] == guess){
					soFar[i] = guess;
				}
			}
		}else{
			cout << "Sorry, " << guess << " isn't in the word\n";
			++wrong;
		}
	}

	return wrong;
}

char playerGuess(){

	char guess;
			cout << "\n\nEnter your guess:";
			cin >> guess;
			guess = toupper(guess); // make uppercase since secret word in uppercase
			cout << endl;

			return guess;
}

bool checkGuess(const string THE_WORD, char guess){
	return THE_WORD.find(guess) != string::npos;
}



