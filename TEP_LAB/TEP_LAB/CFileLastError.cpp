#define _CRT_SECURE_NO_DEPRECATE
#include "CErrors.h"

CFileLastError::CFileLastError()
{
	lastError = false;
	file = NULL;
}

CFileLastError::CFileLastError(std::string fileName)
{
	lastError = false;
	file = fopen(&fileName[0], "w+");
	if (file == NULL) lastError = true;
}

CFileLastError::~CFileLastError()
{
	if(file!=NULL)
	fclose(file);
}

void CFileLastError::OpenFile(std::string fileName)
{
	lastError = false;
	file = fopen(&fileName[0], "w+");
	if (file == NULL)
		lastError = true;
}

void CFileLastError::PrintLine(std::string sText)
{
	lastError = false;
	if (file == NULL) {
		lastError = true;
		return;
	}
	else {
	fprintf(file, &sText[0]);
	}
}

void CFileLastError::PrintManyLines(std::vector<std::string> sText)
{
	lastError = false;
	if (file == NULL) {
		lastError = true;
		return;
	}

	std::vector<std::string>::iterator itr;
	for ( itr= sText.begin(); itr != sText.end(); itr++)
	{
		PrintLine(*itr);
	}
}
