//Game Lobby
//Simulates a game lobby where players wait


#include "GameLobby.h"


Player::Player(std::string name):
		m_Name(name), m_pNext(0) {}

std::string Player::getName(){
	return m_Name;
}

Player* Player::getNext() const {
	return this->m_pNext;
}

void Player::setNext(Player *next) {
	this->m_pNext = next;
}

void Player::printPlayer(){
	std::cout << this->m_Name<< std::endl;
}


Lobby::Lobby(const std::string &name):name(name){}

void Lobby::AddPlayer() {

	//create a new player node
	std::cout << "Please enter the name of the new player: ";
	std::string name;

	//The name needs to be greater than 2 characters, so iterate until the user does so
	do{
		getline(std::cin,name);
	}while(name.length() < 2);

	Player* pNewPlayer = new Player(name);

	//if list is empty, make head of list this new player
	if ((m_pHead == 0) || (m_pTail == 0)) {
		m_pHead = m_pTail = pNewPlayer;
	}
	//otherwise find the end of the list and add the player there
	else {

		Player* pIter = m_pTail;

		pIter->setNext(pNewPlayer);

		m_pTail = pNewPlayer;
	}
}

void Lobby::RemovePlayer() {
	if (m_pHead == 0) {
		std::cout << "The game lobby is empty.  No one to remove!\n";
	} else {
		Player *pTemp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete pTemp;
	}
}

void Lobby::Clear() {
	while (m_pHead != 0) {
		RemovePlayer();
	}
}

std::string Lobby::getName(){
		return this->name;
}


std::ostream& operator<<(std::ostream& os, Lobby& aLobby) {

	Player *pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0) {
		os << "The lobby is empty.\n";
	} else {
		while (pIter != 0) {
			std::cout << *pIter << std::endl;
			pIter = pIter->getNext();
		}
	}

	return os;
}


std::ostream& operator<<(std::ostream& os, Player& aPlayer) {

	os << aPlayer.m_Name << std::endl;
	return os;
}


int main() {

	Lobby* myLobby = new Lobby("Path of Exile Lobby");
	int choice;

	std::cout << myLobby->getName() << "\n" << std::endl;

	do {
		std::cout << "0 - Exit the program.\n";
		std::cout << "1 - Add a player to the lobby.\n";
		std::cout << "2 - Remove a player from the lobby.\n";
		std::cout << "3 - Clear the lobby.\n";
		std::cout << std::endl << "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << "Good-bye.\n";
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
			std::cout << "That was not a valid choice.\n";
		}
		std::cout << *myLobby << std::endl;
	} while (choice != 0);

	return 0;
}
