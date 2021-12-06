#include "Scene.h"

/// <summary>
/// Calls start for all actors in the actors array
/// </summary>
void Scene::start()
{
}

/// <summary>
/// Calls update for every actor in the scene.
/// Calls start for the actor if it hasn't already been called
/// </summary>
void Scene::update()
{
	//Loops through actory array
	for (int i = 0; i < m_actorCount; i++)
	{
		//If actors start is false...
		if (m_actors.getActor(i)->getStarted())
		{
			//...call actors start function
			m_actors.getActor(i)->start();
		}

		//Call actors update function
		m_actors.getActor(i)->update();
	}
}

/// <summary>
/// Calls draw for every actor in the array
/// </summary>
void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors.getActor(i)->draw();
}

/// <summary>
/// Calls end for every actor in the array
/// </summary>
void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors.getActor(i)->end();
}

/// <summary>
/// Initalizes the actor count and the actors array
/// </summary>
Scene::Scene()
{
	m_actorCount = 0;
	m_actors = ActorArray();
}

Scene::~Scene()
{
}

/// <summary>
/// Adds an actor to the scenes list of actors.
/// </summary>
/// <param name="actor">The actor to add to the scene</param>
void Scene::addActor(Actor* actor)
{
	m_actors.AddActor(actor);
}

/// <summary>
/// Removes an actor from the scenes list of actors.
/// </summary>
/// <param name="actor">The actor to remove</parm>
/// <returns>False if the actor was not in the scene array</returns>
bool Scene::removeActor(Actor* actor)
{
	return m_actors.removeActor(actor);
}