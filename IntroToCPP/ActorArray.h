#pragma once

class Actor;

class ActorArray
{
public:
	void AddActor(Actor* actor);
	bool removeActor(Actor* actor);
	
	Actor* getActor(int index);

	int getLength();

	bool contains(Actor* actor);

private:
	Actor** m_actors;
	int m_actorCount;
};

