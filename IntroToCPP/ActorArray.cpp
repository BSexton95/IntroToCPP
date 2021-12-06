#include "ActorArray.h"

/// <summary>
/// Adds an actor to the scenes list of actors.
/// </summary>
/// <param name="actor">The actor to add to the scene</param>
void ActorArray::AddActor(Actor* actor)
{
	
	//Create a temporary array larger than the original 
	Actor** tempArray = new Actor * [m_actorCount + 1];

	//Copy all values from the original array into the temporary array and increments the actor count
	for (int i = 0; i < m_actorCount; i++)
	{
		tempArray[i] = m_actors[i];

		m_actorCount++;
	}

	//Add the new actor to the end of the new array
	tempArray[m_actorCount] = actor;

	//Set the old array to be the new array
	m_actors = tempArray;
	
}

/// <summary>
/// Removes an actor from the scenes list of actors.
/// </summary>
/// <param name="actor">The actor to remove</parm>
/// <returns>False if the actor was not in the scene array</returns>
bool ActorArray::removeActor(Actor* actor)
{
	
	//Create a variable to store if the removal was successful
	bool actorRemoved = false;

	//Create a new array that is smaller than the original
	Actor** tempArray = new Actor * [m_actorCount - 1];

	//Copy all values except the actor we don't want into the new array
	int j = 0;
	for (int i = 0; i < m_actorCount - 1; i++)
	{
		//If the actor that the loop is on is not the one to remove...
		if (m_actors[i] != actor)
		{
			//...add the actor into the new array and increment the temp array counter
			tempArray[j] = m_actors[i];
			j++;
		}
		//Otherwise if this actor is the one to remove...
		else
		{
			//...set actorRemoved to true
			actorRemoved = true;
		}
	}


	//If the actor removal was successful...
	if (actorRemoved)
	{
		delete m_actors;

		//...set the old array to be the new array
		m_actors = tempArray;
	}

	//Decrement the actor count
	m_actorCount--;

	return actorRemoved;
}

Actor* ActorArray::getActor(int index)
{
	if (index < 0 || index >= m_actorCount)
		return nullptr;

	return m_actors[index];
}

bool ActorArray::contains(Actor* actor)
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (m_actors[i] == actor)
			return true;
	}

	return false;
}
