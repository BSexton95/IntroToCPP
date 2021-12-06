#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	m_name = '\0';
	m_health = 0;
	m_attackPower = 0;
	m_defensePower = 0;
}

Entity::Entity(char name, float health, float attackPower, float defensePower)
{
	m_name = name;
	m_health = health;
	m_attackPower = attackPower;
	m_defensePower = defensePower;
}

float Entity::takeDamage(float damageAmount)
{
	float damageTaken = damageAmount - getDefensePower();

	if (damageTaken < 0)
		damageTaken = 0;

	m_health -= damageTaken;

	if (m_health <= 0)
		m_health = 0;

	return damageTaken;
}

float Entity::attack(Entity* entity)
{
	return entity->takeDamage(getAttackPower());
}

void Entity::printStats()
{
	std::cout << m_name << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "Attak Power: " << getAttackPower() << std::endl;
	std::cout << "Defense Power: " << getDefensePower() << std::endl;
}
