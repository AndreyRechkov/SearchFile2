#pragma once
#include <iostream>
#include <string>
#include<vector>
#include <iostream>
class Menu
{
public:
	typedef void(*ptr)();
	struct Item {
		char *name;
		ptr pointer;
	};
	std::vector <Item> example;
	void addItem(char *name, ptr func);
	void menu();
	Menu();
	~Menu();
};

