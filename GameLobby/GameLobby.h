/*
 * GameLobby.h
 *
 *  Created on: Jan 25, 2020
 *      Author: natedogg
 */

#ifndef GAMELOBBY_H_
#define GAMELOBBY_H_

#include <iostream>
#include <string>

using namespace std;

class GameLobby {

public:
	GameLobby();
	virtual ~GameLobby();
};

class Player {

private:
	string m_Name = 0;
	Player* m_pNext = 0;  //Pointer to next player in list

public:

	friend ostream& operator<<(ostream& os, Player& aPlayer);

	void printPlayer(Player& thePlayer);

	Player(string name) :
			m_Name(name), m_pNext(0) {
	}

	string GetName(){
		return m_Name;
	}

	Player* GetNext() const {
		return this->m_pNext;
	}

	void SetNext(Player *next) {
		this->m_pNext = next;
	}

	void printPlayer(){
			cout << this->m_Name<< endl;
	}
};


#endif /* GAMELOBBY_H_ */
