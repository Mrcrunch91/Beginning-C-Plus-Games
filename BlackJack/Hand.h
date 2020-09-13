/*
 * Hand.h
 *
 *  Created on: Sep 7, 2020
 *      Author: natedogg
 */

#ifndef HAND_H_
#define HAND_H_
#include "Card.h"
#include <vector>

class Hand {

protected:

	static std::vector<Card> m_Cards;

public:

	Hand();
	~Hand();

	void Add(Card);
	void Clear();
	int GetTotal() const;

private:



};

#endif /* HAND_H_ */
