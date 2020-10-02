//Blackjack
//Plays a simple version of the casino game of blackjack; for 1 - 7 players

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Card.h"
#include "GenericPlayer.h"
#include "Game.h"


//overloads << operator so Card object can be sent to cout
std::ostream& operator<<(std::ostream &os, const Card &aCard) {
	const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "J", "Q", "K" };
	const std::string SUITS[] = { "c", "d", "h", "s" };

	if (aCard.m_IsFaceUp) {
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	} else {
		os << "XX";
	}

	return os;
}



int main() {

	std::cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7) {
		std::cout << "How many players? (1 - 7): ";
		std::cin >> numPlayers;
	}

	std::vector<std::string> names;

	std::string name;

	for (int i = 0; i < numPlayers; ++i) {
		std::cout << "Enter player name: ";
		std::cin >> name;
		names.push_back(name);
	}

	std::cout << std::endl;

	//the game loop
	Game aGame(names);

	char again = 'y';
	while (again != 'n' && again != 'N') {
		aGame.Play();
		std::cout << "\nDo you want to play again? (Y/N): ";
		std::cin >> again;
	}

	return 0;
}


