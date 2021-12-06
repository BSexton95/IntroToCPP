#pragma once
#include "Actor.h"

class Scene
{
public:
	~Scene();
	bool getStarted() { m_started = true; }
	void addActor(Actor* actor);
	bool removeActor(Actor* actor);

	virtual void start();
	virtual void update();
	virtual void draw();
	virtual void end();

private:
	Actor** m_actors;
	bool m_started;
	int m_actorCount;
};
