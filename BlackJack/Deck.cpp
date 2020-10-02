/*
 * Deck.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: natedogg
 */

#include "Deck.h"
#include "GenericPlayer.h"



Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck() {
}

void Deck::Populate() {

	Clear();

	for (int s = suit::CLUBS; s <= suit::SPADES; ++s) {
		for (int r = rank::ACE; r <= rank::KING; ++r) {
			Card* theCard = new Card(static_cast<rank>(r), static_cast<suit>(s));
			Hand::Add(theCard);
		}
	}
}

void Deck::Shuffle() {
	std::random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand) {
	if (!m_Cards.empty()) {
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	} else {
		std::cout << "Out of cards. Unable to deal.";
	}
}


void Deck::AdditionalCards(GenericPlayer &aGenericPlayer) {



	std::cout << std::endl;
	//continue to deal a card as long as generic player isn't busted and
	//wants another hit
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {

		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;

		if (aGenericPlayer.IsBusted()) {
			aGenericPlayer.Bust();
		}
	}
}

