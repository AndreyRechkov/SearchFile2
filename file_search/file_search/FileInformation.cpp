#include "pch.h"
#include "FileInformation.h"
#include<iostream>
#include<string>

std::string FileInformation::Print() {
    return nameFile;
}


FileInformation::FileInformation(std::string in) {
	nameFile = in;
}


FileInformation::~FileInformation()
{
}


