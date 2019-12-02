//Critter Caretaker
//Simulates caring for a virtual pet

#include <iostream>

using namespace std;

class Critter{

private:
    int m_Hunger;
    int m_Boredom;

public:

    Critter(int hunger = 4, int boredom = 2):
        m_Hunger(hunger),
        m_Boredom(boredom){}

    inline int GetMood() const
    {
        return (m_Hunger + m_Boredom);
    }

    void PassTime(int time = 1)
    {
        m_Hunger += time;
        m_Boredom += time;
    }

    void Talk()
    {
        cout << "I'm a critter and I feel ";

        int mood = GetMood();
        if (mood > 15)
    	{
            cout << "mad.\n";
    	}
        else if (mood > 10)
    	{
            cout << "frustrated.\n";
    	}
        else if (mood > 5)
    	{
            cout << "okay.\n";
    	}
        else
    	{
            cout << "happy.\n";
    	}

        PassTime();
    }

    void Eat(int food = 4)
    {
        cout << "Brruppp.\n";

        m_Hunger -= food;
        if (m_Hunger < 0)
    	{
            m_Hunger = 0;
    	}

        PassTime();
    }

    void Play(int fun = 4)
    {
        cout << "Wheee!\n";

        m_Boredom -= fun;
        if (m_Boredom < 0)
    	{
            m_Boredom = 0;
    	}

        PassTime();
    }



};

int main(){

	Critter crit;
	crit.Talk();

	int choice;
	do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
			case 0:
				cout << "Good-bye.\n";
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
				cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
	} while (choice != 0);

    return 0;
}
