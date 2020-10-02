/*
 * Game.h
 *
 *  Created on: Sep 20, 2020
 *      Author: natedogg
 */

#ifndef GAME_H_
#define GAME_H_
#include "Deck.h"
#include "Player.h"
#include "House.h"

class Game {

public:

	Game(const std::vector<std::string> &names);

	~Game(){};

	//plays the game of blackjack
	void Play();

private:
	Deck m_Deck;
	House m_House;
	std::vector<Player*> m_Players;
};

#endif /* GAME_H_ */
