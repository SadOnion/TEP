#define _CRT_SECURE_NO_DEPRECATE
#include "CErrors.h"
#include <iostream>

CFileThrowEx::CFileThrowEx()
{
	file = NULL;
}

CFileThrowEx::CFileThrowEx(std::string fileName)
{
	file = fopen(&fileName[0], "w+");
}

CFileThrowEx::~CFileThrowEx()
{
	if(file!=NULL)
	fclose(file);
}

void CFileThrowEx::OpenFile(std::string fileName)
{
	file = fopen(&fileName[0], "w+");
	try {
		
		if (file == NULL) {
			std::cout << "e";
			throw 66;
		}

	}
	catch (int e) {
		std::cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::PrintLine(std::string sText)
{
	try {
		if (file == NULL) throw 66;
		
		fprintf(file, &sText[0]);
	}
	catch (int e) {
		std::cout << "An exception # " << e << '\n';
	}
	
}

void CFileThrowEx::PrintManyLines(std::vector<std::string> sText)
{
	try {
		if (file == NULL) throw 1;
		std::vector<std::string>::iterator itr;
		for (itr = sText.begin(); itr != sText.end(); itr++)
		{
			PrintLine(*itr);
		}
	}
	catch (int e) {
		std::cout << "An exception # " << e << '\n';
	}
}


