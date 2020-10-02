/*
 * GenericPlayer.h
 *
 *  Created on: Sep 13, 2020
 *      Author: natedogg
 */

#ifndef GENERICPLAYER_H_
#define GENERICPLAYER_H_

#include "Hand.h"

class GenericPlayer: public Hand {

	friend std::ostream& operator<<(std::ostream &os,
			const GenericPlayer &aGenericPlayer);

public:

	//indicates whether or not generic player wants to keep hitting
	virtual bool IsHitting() const = 0;

	//returns whether generic player has busted - has a total greater than 21
	bool IsBusted() const;

	//announces that the generic player busts
	void Bust() const;

	GenericPlayer(const std::string &name = "");

	virtual ~GenericPlayer() {}



protected:
	std::string m_Name;
};

#endif /* GENERICPLAYER_H_ */
