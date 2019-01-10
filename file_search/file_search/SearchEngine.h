#pragma once
#include<string>
#include<list>
#include "FileInformation.h"

class SearchEngine
{
public:
	 SearchEngine();
     void SearchDirectory(const std::string &PathRoot, std::list<FileInformation> &Out, std::string userName);
	 void SearchInFile(const std::string &PathRoot, std::string you);
     bool Search(std::list<FileInformation> &Out);
	 ~SearchEngine();
};


