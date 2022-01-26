//Critter Caretaker
//Simulates caring for a virtual pet

#include "Critter.hpp"

Critter::Critter(int hunger = 4, int boredom = 2) :
		m_Hunger(hunger), m_Boredom(boredom) {
}

inline int Critter::GetMood() const {
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time) {
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk() {
	std::cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15) {

		if (m_Hunger >= 7)
			std::cout << "Hey man...I'm like super hungry!!" << std::endl;

		if (m_Boredom >= 7)
			std::cout << "I desperately need something to do....please! "
					<< std::endl;

	} else if (mood > 10) {

		if (m_Hunger >= 5)
			std::cout << "I need a Snicker, cause I'm grumpy right now."
					<< std::endl;

		if (m_Boredom >= 5)
			std::cout << "I need a new activity." << std::endl;

	} else if (mood > 5) {

		if (m_Hunger >= 5)
			std::cout
					<< "Eh...I'm not hungry, but I wouldn't be opposed to a snack?"
					<< std::endl;

		if (m_Boredom >= 5)
			std::cout << "I'm good for now, you can leave me alone. Haha"
					<< std::endl;
	} else {
		if (m_Hunger >= 5)
			std::cout << "I need a Snicker, cause I'm grumpy right now."
					<< std::endl;

		if (m_Boredom >= 5)
			std::cout << "I need a new activity." << std::endl;
	}

	PassTime();
}

void Critter::Eat(int food) {
	std::cout << "Brruppp.\n";

	m_Hunger -= food;
	if (m_Hunger < 0) {
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun) {
	std::cout << "Wheee!\n";

	m_Boredom -= fun;
	if (m_Boredom < 0) {
		m_Boredom = 0;
	}

	PassTime();
}

void Critter::Status() {
	std::cout << "Hunger Level: " << m_Hunger << "\nBoredom Level: "
			<< m_Boredom;
}

int main() {

	Critter crit;
	crit.Talk();

	int choice;
	do {
		std::cout << "\n\nCritter Caretaker\n\n" << std::endl;
		std::cout << "0 - Quit\n" << std::endl;
		std::cout << "1 - Listen to your critter\n" << std::endl;
		std::cout << "2 - Feed your critter\n" << std::endl;
		std::cout << "3 - Play with your critter\n" << std::endl;

		std::cout << "Choice: " << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			std::cout << "\nSorry, but " << choice
					<< " isn't a valid choice.\n";
			crit.Status();
		}
	} while (choice != 0);

	return 0;
}
