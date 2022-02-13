/*
 * Card.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: natedogg
 */

#include "Card.h"

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

	Card::Card(rank r, suit s, bool ifu) :
			m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {
	}

	//returns the value of a card, 1 - 11
	int Card::GetValue() const {
		//if a card is face down, its value is 0
		int value = 0;
		if (m_IsFaceUp) {
			//value is number showing on card
			value = m_Rank;
			//value is 10 for face cards
			if (value > 10) {
				value = 10;
			}
		}
		return value;
	}

	//flips a card; if face up, becomes face down and vice versa
	void Card::Flip() {
		m_IsFaceUp = !(Card::m_IsFaceUp);
	}







