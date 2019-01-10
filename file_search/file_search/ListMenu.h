#pragma once
#include "Menu.h"
#include "SearchEngine.h"
#include "FileInformation.h"
class ListMenu
{
public:
	Menu enu;
	static SearchEngine Example;
	std::list<FileInformation> foundFils;
	static void SearchInFile();
	static void SearchDirectory();
	static void exxit();
	ListMenu();
};
