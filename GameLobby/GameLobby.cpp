//Game Lobby
//Simulates a game lobby where players wait

#include <iostream>
#include <string>
#include "GameLobby.h"

using namespace std;

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

class Lobby {

private:

	Player* m_pHead = 0;
	string name = 0;
	Player* m_pTail = 0;

public:

	friend ostream& operator<<(ostream& os, Lobby& aLobby);

	~Lobby();
	Lobby(const string &name):name(name){}

	void AddPlayer() {

		//create a new player node
		cout << "Please enter the name of the new player: ";
		string name;
		cin >> name;
		Player* pNewPlayer = new Player(name);

		//if list is empty, make head of list this new player
		if ((m_pHead == 0) | (m_pTail == 0)) {
			m_pHead = m_pTail = pNewPlayer;
		}

		//otherwise find the end of the list and add the player there
		else {

			Player* pIter = m_pTail;

			pIter->SetNext(pNewPlayer);
		}
	}

	void RemovePlayer() {
		if (m_pHead == 0) {
			cout << "The game lobby is empty.  No one to remove!\n";
		} else {
			Player *pTemp = m_pHead;
			m_pHead = m_pHead->GetNext();
			delete pTemp;
		}
	}

	void Clear() {
		while (m_pHead != 0) {
			RemovePlayer();
		}
	}

	string getName(){
		return this->name;
	}
};


ostream& operator<<(ostream& os, Lobby& aLobby) {

	Player *pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0) {
		os << "The lobby is empty.\n";
	} else {
		while (pIter != 0) {
			cout << *pIter << endl;
			pIter = pIter->GetNext();
		}
	}

	return os;
}

ostream& operator<<(ostream& os, Player& aPlayer) {

	os << aPlayer.m_Name;
	return os;
}


int main() {

	Lobby* myLobby = new Lobby("Path of Exile Lobby");
	int choice;

	cout << myLobby->getName() << "\n" << endl;

	do {
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cout << endl << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			myLobby->AddPlayer();
			break;
		case 2:
			myLobby->RemovePlayer();
			break;
		case 3:
			myLobby->Clear();
			break;
		default:
			cout << "That was not a valid choice.\n";
		}
		cout << *myLobby << endl;
	} while (choice != 0);

	return 0;
}
