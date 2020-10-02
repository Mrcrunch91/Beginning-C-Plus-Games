/*
 * House.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: natedogg
 */

#include "House.h"

House::House(const std::string &name) :
		GenericPlayer(name) {
}

bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

//flips over first card
void House::FlipFirstCard() {
	if (!(m_Cards.empty())) {
		m_Cards[0]->Flip();
	} else {
		std::cout << "No card to flip!\n";
	}
}
