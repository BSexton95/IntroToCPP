#include "Engine.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;

	m_scenes = 0;
	m_currentSceneIndex = 0;
}

Engine::~Engine()
{
	delete m_currentFighter1;
	delete m_currentFighter2;
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
	m_scenes[m_currentSceneIndex]->start();
}

void Engine::update()
{
	m_scenes[m_currentFighterIndex]->update();
}

void Engine::draw()
{
	m_currentFighter1->printStats();
	m_currentFighter2->printStats();
	system("pause");
	system("cls");
}

void Engine::end()
{
}

/// <summary>
/// Adds a scene to the engine's scene array
/// </summary>
/// <param name="scene">The cene that will be added to the scene array
void Engine::addScene(Scene* scene)
{
	//Create a new temporary array
	Scene** tempArray = new Scene*[m_sceneCount + 1];

	//Copy all values from old array into the new array
	for (int i = 0; i < m_sceneCount; i++)
	{
		tempArray[i] = m_scenes[i];
		m_sceneCount++;
	}

	//Deallocate the memory for the old array
	delete m_scenes;

	//Set the last index to be the new scene
	tempArray[m_sceneCount] = scene;

	//Set the old array to be the new array
	m_scenes = tempArray;

}

Scene* Engine::getCurrentScene()
{
	return nullptr;
}

/// <summary>
/// Sets the current scene
/// </summary>
void Engine::setCurrentScene(int index)
{
	if (index == 1)
		m_currentSceneIndex = 1;
	if (index == 2)
		m_applicationShouldClose = true;
}

