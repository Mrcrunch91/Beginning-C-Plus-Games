/*
 * GenericPlayer.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: natedogg
 */

#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string &name) :
m_Name(name) {}

bool GenericPlayer::IsBusted() const {
	return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {
	std::cout << m_Name << " busts.\n";
}

//overloads << operator so a GenericPlayer object can be sent to cout
std::ostream& operator<<(std::ostream &os, const GenericPlayer &aGenericPlayer) {

	os << aGenericPlayer.m_Name << ":\t";

	std::vector<Card*>::const_iterator pCard = m_Cards.begin();

	if (!m_Cards.empty()) {

		for (; pCard != m_Cards.end(); ++pCard) {
					os << *(*pCard) << "\t";
		}

		if (aGenericPlayer.GetTotal() != 0) {
			std::cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	} else {
		os << "<empty>";
	}

	return os;
}
