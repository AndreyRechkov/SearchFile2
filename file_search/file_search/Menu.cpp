#include "pch.h"
#include "Menu.h"
#include<iostream>


void Menu::addItem(char *name, ptr func)
{
	Item new_i;
	new_i.name = name;
	new_i.pointer = func;
	example.push_back(new_i);
}

void Menu::menu()
{
	int k;
	while (true)
	{
		std::cout << std::endl;
		for (int i = 0; i < (int)example.size(); i++)
			std::cout << i + 1 << ". " << example[i].name << std::endl;
		std::cout << std::endl;
		std::cin >> k;
		example[k - 1].pointer();
	}
}

Menu::Menu()
{
}


Menu::~Menu()
{
}
