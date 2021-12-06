#include "StartScene.h"
#include <iostream>
#include "Engine.h"

void StartScene::draw()
{
	//Displays players options
	std::cout << "Welcome to the battle simulation!" << std::endl;
	std::cout << "1. Sart" << std::endl;
	std::cout << "2. Exit" << std::endl;
}

void StartScene::update()
{
	char input;

	//Players input
	std::cin >> input;

	//If player chooses to start game...
	if (input == '1')
		//...set current scene to 1
		Engine::setCurrentScene(1);
	//If player chooses to exit game...
	else if (input == '2')
		//...set current scene to 2
		Engine::getApplicationShouldClose();
	//Otherwise...
	else
		//...display message stating that the player as inputed an invalid input
		std::cout << "Invalid Input" << std::endl;
	
		
}
