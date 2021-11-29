#pragma once

class Entity
{
public:
	Entity(char icon, float health, float attackPower, float defensePower);

	float getHealth();
	float getAttackPower();
	float getDefensePower();
	float getIcon();

	float takeDamage(float damageAmount);
	float attack(Entity entity);

private:
	float m_health;
	float m_attackPower;
	float m_defensePower;
	char m_icon;
};