/*
 * Player.h
 *
 *  Created on: Sep 13, 2020
 *      Author: natedogg
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GenericPlayer.h"

class Player: public GenericPlayer {

public:

	Player(const std::string &name);

	//returns whether or not the player wants another hit
	bool IsHitting() const;

	//announces that the player wins
	void Win() const;

	//announces that the player loses
	void Lose() const;

	virtual ~Player() {}

	//announces that the player pushes
	void Push() const;

};

#endif /* PLAYER_H_ */
