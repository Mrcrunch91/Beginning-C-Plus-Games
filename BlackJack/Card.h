/*
 * Card.h
 *
 *  Created on: Sep 7, 2020
 *      Author: natedogg
 */

#ifndef CARD_H_
#define CARD_H_
#include <iostream>

enum rank {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

enum suit {
	CLUBS, DIAMONDS, HEARTS, SPADES
};


class Card {

public:
	Card(rank r, suit s, bool ifu = false);
	virtual ~Card(){};
	int GetValue() const;
	void Flip();



private:

	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;

	//overloading << operator so can send Card object to standard output
	friend std::ostream& operator<<(std::ostream &os, const Card &aCard);

};

#endif /* CARD_H_ */
