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

static std::vector<Card*> m_Cards;

class Hand {

public:

	Hand();
	~Hand();

	void Add(Card*);
	void Clear();
	int GetTotal() const;

};

#endif /* HAND_H_ */
