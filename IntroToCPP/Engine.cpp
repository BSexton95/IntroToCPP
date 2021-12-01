#include "Engine.h"

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		update();
		draw();
	}

	end();
}

void Engine::start()
{
	//Entities that will be fighting
	Entity wompus = Entity('W', 130002000, 578000, -15000);
	Entity redactedLittleSkeleton = Entity('r', 4400000 - 44000, 45500 - 40, 0);
	Entity unclePhil = Entity('U', 1, 0, 6900055);

	//Placed the fighters in the entity array
	m_entities[0] = wompus;
	m_entities[1] = redactedLittleSkeleton;
	m_entities[2] = unclePhil;

	//Who is fighter one and fighter 2
	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void Engine::update()
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
		m_applicationShouldClose = true;
		return;
	}

	//Fighter 2 attacks fighter 1
	m_currentFighter1->attack(m_currentFighter2);
	//Fighter 1 attacks fighter 2
	m_currentFighter2->attack(m_currentFighter1);
}

void Engine::draw()
{

}

void Engine::end()
{
}
