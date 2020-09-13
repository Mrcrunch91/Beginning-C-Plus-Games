/*
 * Player.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: natedogg
 */

#include "Player.h"

Player::Player(const std::string &name) :
			GenericPlayer(name) {
	}

bool Player::IsHitting() const {
		std::cout << m_Name << ", do you want a hit? (Y/N): ";
		char response;
		std::cin >> response;
		return (response == 'y' || response == 'Y');
	}

void Player::Win() const {
		std::cout << m_Name << " wins.\n";
	}

void Player::Lose() const {
		std::cout << m_Name << " loses.\n";
	}

void Player::Push() const {
		std::cout << m_Name << " pushes.\n";
	}
