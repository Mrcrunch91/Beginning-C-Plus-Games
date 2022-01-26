/*
 * Critter.h
 *
 *  Created on: Dec 1, 2019
 *      Author: natedogg
 */

#ifndef CRITTER_HPP_
#define CRITTER_HPP_

#include <iostream>

class Critter {

public:
	int m_Hunger;
	int m_Boredom;

	Critter(int, int);

	inline int GetMood() const;

	void PassTime(int = 1);

	void Talk();

	void Eat(int = 4);

	void Play(int = 4);

	void Status();

};

#endif /* CRITTER_HPP_ */
