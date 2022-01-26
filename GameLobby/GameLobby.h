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


class GameLobby {

public:
	GameLobby();
	virtual ~GameLobby();
};

class Player {

private:

	std::string m_Name = 0;
	Player* m_pNext = 0;  //Pointer to next player in list

public:

	friend std::ostream& operator<<(std::ostream& os, Player& aPlayer);

	void printPlayer(Player& thePlayer);

	Player(std::string name);


	std::string getName();

	Player* getNext() const;

	void setNext(Player *next);

	void printPlayer();

};


class Lobby {

private:

	Player* m_pHead = 0;
	std::string name = 0;
	Player* m_pTail = 0;

public:

	friend std::ostream& operator<<(std::ostream& os, Lobby& aLobby);

	Lobby(const std::string &name);
	~Lobby();



	void AddPlayer();

	void RemovePlayer();

	void Clear();

	std::string getName();
};


#endif /* GAMELOBBY_H_ */
