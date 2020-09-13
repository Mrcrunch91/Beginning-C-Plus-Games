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

