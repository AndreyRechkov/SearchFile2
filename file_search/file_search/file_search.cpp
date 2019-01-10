// file_search.cpp : Этот файл содержит функцию "main". Здесь начинается и

#include "pch.h"
#include <iostream>
#include "SearchEngine.h"
#include "FileInformation.h"
#include "ListMenu.h"
#include "Menu.h"
#include<Windows.h>

SearchEngine ListMenu::Example;
int main() {
	setlocale(LC_ALL, "Rus");
	SearchEngine testFile;
	std::list<FileInformation> foundFils;
	testFile.Search(foundFils);
	ListMenu menu;

 if (foundFils.empty()) {
    std::cout << "Empty list";
 }
 else {
	 for (auto i : foundFils) {
		 std::cout << i.Print() << std::endl;
	 }
 }
}
