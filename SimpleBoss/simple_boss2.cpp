//Simple Boss 2.0
//Demonstrates access control under inheritance

#include <iostream>


class Enemy
{
public:
    Enemy();  
    void Attack() const;

protected:
    int m_Damage;
};

Enemy::Enemy(): 
    m_Damage(10)
{}    

void Enemy::Attack() const
{ 
    std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}  

class Boss : public Enemy
{
public:
    Boss();
    void SpecialAttack() const;

protected:
    int m_DamageMultiplier;
};

Boss::Boss(): 
    m_DamageMultiplier(3)
{}  

void Boss::SpecialAttack() const
{
    std::cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
    std::cout << " damage points!\n";
}


class FinalBoss : public Boss
{
public:
	FinalBoss();
    void MegaAttack() const;
private:
    int m_FinalDamageMultiplier;
};

FinalBoss::FinalBoss():
	m_FinalDamageMultiplier(10)
{}

void FinalBoss::MegaAttack() const{
    std::cout << "Mega Attack inflicts " << ((m_DamageMultiplier * m_Damage) * m_FinalDamageMultiplier);
    std::cout << " damage points!\n";
}

int main()
{ 
    std::cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.Attack();

    std::cout << "\nCreating a boss.\n";
    Boss boss1;
    boss1.Attack();
    boss1.SpecialAttack();

    std::cout << "\nCreating a Mega boss.\n";
    FinalBoss boss2;
    boss2.Attack();
    boss2.SpecialAttack();
    boss2.MegaAttack();

    return 0;
} 

