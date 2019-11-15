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
	file = fopen(fileName.c_str(), "w+");
		if (file == NULL) {
			throw 66;
		}

}

void CFileThrowEx::PrintManyLines(std::vector<std::string> sText)
{
	
		if (file == NULL) throw 1;
		std::vector<std::string>::iterator itr;
		for (itr = sText.begin(); itr != sText.end(); itr++)
		{
			PrintLine(*itr);
			PrintLine("\n");
		}
	
}
void CFileThrowEx::PrintLine(std::string sText)
{
	
		if (file == NULL) throw 66;
		
		int result = fprintf(file, sText.c_str());
		if (result < 0) throw 66;
	
}

void CFileThrowEx::CloseFile() {
	if (file != NULL) {
		int result = fclose(file);
		if (result < 0) throw 10;
	}
}


