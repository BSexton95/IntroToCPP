#include <iostream>

int Add(int num1, int num2)
{
	return num1 + num2;
}

int test;
int numbers[] = { 1, 2, 3 };
//int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
int numbers2D[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

int main()
{
	std::cout << Add(1, 2);

	for (int i = 0; i < 3; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	for (int i : numbers)
	{
		std::cout << i << std::endl;
	}
	/*
	std::cout << "Hello World!" << std::endl;
	std::cout << "26" << std::endl;
	int age;
	int health;
	bool isAlive = health;
	int damage = 10;
	std::cin >> age;
	std::cout << "Your age is: " << age;

	if (health <= 0)
		isAlive = false;
	else if (health == 100)
	{
		damage += 50;
	}
	else if (health == 50)
	{
		std::cout << "Danger! Health Low";
	}

	switch (health)
	{
	case 0:
		isAlive = false;
		break;
	case 50:

	}
	*/

	char firstName[32] = "Brittnie";
	char lastName[35] = "";
	char fullName[64] = "";

	std::cout << firstName << std::endl;
	std::cin >> lastName;

	std::cout << firstName << " " << lastName << std::endl;
	system("pause");

	strcat_s(fullName, firstName);
	strcat_s(fullName, lastName);
	std::cout << fullName << std::endl;
	system("pause");

	strcpy_s(firstName, lastName);
	std::cout << firstName;

	system("pause");
	system("cls");

	return 0;
}