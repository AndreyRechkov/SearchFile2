#include "pch.h"
#include "ListMenu.h"
#include <iostream>
#include<Windows.h>
#include "FileInformation.h"


void ListMenu::SearchInFile()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string you;
	std::string PathRoot;
	std::cout << "Insert catalog: "; 
	std::cin >> PathRoot;
	std::cout << "Insert depth: ";	
	std::cin >> you;
	Example.SearchInFile(PathRoot, you); 
}

void ListMenu::SearchDirectory()
{
	std::string userName;
	std::cout << "Please insert text: ";
	std::cin>> userName;
	std::list<FileInformation> foundFils;
	Example.SearchDirectory("d:\\Example", foundFils, userName);
	if (foundFils.empty()) {
		std::cout << "Empty list";
	}
	else {
		for (auto i : foundFils) {
			std::cout << i.Print() << std::endl;
		}
	}
}

void ListMenu::exxit()
{
	char r;
	std::cout << "Do you really want to leave? y/n" << std::endl;
	std::cin >> r;
	switch (r) {
	case 'y':exit(0);
	case 'n': ListMenu();
	}
}

	ListMenu::ListMenu()
{
	enu.addItem((char*)"Find a file.", &SearchDirectory);
	enu.addItem((char*)"Search file by content.", &SearchInFile);
	enu.addItem((char*)"Exit", &exxit);
	enu.menu();
}

