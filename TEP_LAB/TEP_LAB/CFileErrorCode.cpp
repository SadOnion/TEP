#define _CRT_SECURE_NO_DEPRECATE
#include "CErrors.h"

CFileErrorCode::CFileErrorCode()
{
	file = NULL;
}

CFileErrorCode::CFileErrorCode(std::string fileName)
{
	file = fopen(&fileName[0], "w+");
	
}

CFileErrorCode::~CFileErrorCode()
{
	if (file != NULL)
		fclose(file);
}

bool CFileErrorCode::OpenFile(std::string fileName)
{
	file = fopen(&fileName[0], "w+");
	if (file == NULL)return false;
	else return true;
}

bool CFileErrorCode::PrintLine(std::string sText)
{
	int result = fprintf(file,&sText[0]);
	if (result < 0) return false;
	else return true;
}

bool CFileErrorCode::PrintManyLines(std::vector<std::string> sText)
{
	std::vector<std::string>::iterator itr;
	for (itr = sText.begin(); itr != sText.end(); itr++)
	{
		int result = PrintLine(*itr);
		if (result == false) return false;
	}
	return true;
}
