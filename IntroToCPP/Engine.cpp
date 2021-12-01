#include "Engine.h"

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
}

void Engine::update()
{
}

void Engine::draw()
{
}

void Engine::end()
{
}
