/*
 * Card.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: natedogg
 */

#include "Card.h"


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







