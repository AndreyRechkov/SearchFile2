#include "pch.h"
#include "SearchEngine.h"
#include<iostream>
#include<fstream>
#include <Windows.h>
#include "FileInformation.h"
#include <algorithm>
#include <string>
#include<vector>
#include <cstring>

SearchEngine::SearchEngine()
{
}


SearchEngine::~SearchEngine()
{
}
bool SearchEngine::Search(std::list<FileInformation> &Out) { return false; }


void SearchEngine::SearchDirectory(const std::string &PathRoot, std::list<FileInformation> &Out, std::string userName)
{
	std::string tmp = PathRoot + "\\*";
	HANDLE hFind;
	WIN32_FIND_DATAA PathRoot2;
	hFind = FindFirstFileA(tmp.c_str(), &PathRoot2);
	if (hFind == INVALID_HANDLE_VALUE) {
		std::cout << ("Invalid file handle. Error  \n", GetLastError());

	}
	else {
		std::list<std::string> Example;

		do
		{
			//std::cout << tmp << std::endl;
			if (PathRoot2.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpA(PathRoot2.cFileName, ".")) || (!lstrcmpA(PathRoot2.cFileName, "..")))
					continue;
			}
			tmp = PathRoot + "\\" + PathRoot2.cFileName;
			if (PathRoot2.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				Example.push_back(tmp);
		} while (FindNextFileA(hFind, &PathRoot2));
		FindClose(hFind);
		for (std::list<std::string>::iterator iter = Example.begin(), end = Example.end(); iter != end; ++iter)
			SearchDirectory(*iter, Out, userName);
		if (strstr(tmp.c_str(), userName.c_str())) {
			Out.push_back(tmp);
		}
	}
}

void SearchEngine::SearchInFile(const std::string &PathRoot, std::string you)
{
	setlocale(LC_ALL, "Russian");
	std::string tmp = "D:\\" + PathRoot + "\\*";
	HANDLE hFind;
	WIN32_FIND_DATAA PathRoot2;
	hFind = FindFirstFileA(tmp.c_str(), &PathRoot2);
	std::string data;
	if (hFind == INVALID_HANDLE_VALUE) {
		std::cout << ("Invalid file handle. Error  \n", GetLastError());

	}
	else {
		do
		{
			if (PathRoot2.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpA(PathRoot2.cFileName, ".")) || (!lstrcmpA(PathRoot2.cFileName, "..")))
					continue;
			}
			tmp = "D:\\" + PathRoot + "\\" + PathRoot2.cFileName;

			std::ifstream fin(tmp);
			while (getline(fin, data)) {
				if (strstr(data.c_str(), you.c_str())) {
					std::cout << tmp << std::endl;
					std::cout << you << " " << "The position: " << data.find(you) << std::endl;
					std::cout << data << std::endl;
				}

			}

			fin.close();

		} while (FindNextFileA(hFind, &PathRoot2));
		FindClose(hFind);

	}
}
