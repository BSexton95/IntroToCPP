#include "SimulationManager.h"
#include "Entity.h"
#include "Engine.h"

void SimulationManager::start()
{
	m_entityCount = 0;
	m_currentFighterIndex = 0;

	//Entities that will be fighting
	Entity wompus = Entity('W', 30, 1, 1);
	Entity redactedLittleSkeleton = Entity('r', 2, 1, 0);
	Entity unclePhil = Entity('U', 1, 0, 0);

	//Placed the fighters in the entity array
	m_entities[0] = wompus;
	m_entities[1] = redactedLittleSkeleton;
	m_entities[2] = unclePhil;
	m_entityCount = 3;

	int test = 5;
	Entity* entityPtrs[5];
	Entity** entities = new Entity * [test];

	//Who is fighter one and fighter 2
	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void SimulationManager::update()
{
	//If fighter 1 dies to fighter 2, fighter 1 is replaced with a different player
	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter1 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter2 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if (m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex >= m_entityCount)
	{
		Engine::getApplicationShouldClose();
		return;
	}

	//Fighter 2 attacks fighter 1
	m_currentFighter1->attack(m_currentFighter2);
	//Fighter 1 attacks fighter 2
	m_currentFighter2->attack(m_currentFighter1);
}
