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
	file = fopen(fileName.c_str(), "w+");
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
	file = fopen(fileName.c_str(), "w+");
	if (file == NULL)
		lastError = true;
}

void CFileLastError::PrintLine(std::string sText)
{
	lastError = false;
	if (file == NULL) {
		lastError = true;
	}
	else {
	 int result = fprintf(file, sText.c_str());
	 if (result < 0) lastError = true;
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
		PrintLine("\n");
	}
}
void CFileLastError::CloseFile() 
{
	lastError = false;
	if (file != NULL) {
		int result = fclose(file);
		if (result < 0) lastError = true;
	}
}
