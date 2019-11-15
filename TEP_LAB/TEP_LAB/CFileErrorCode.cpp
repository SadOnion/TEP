#define _CRT_SECURE_NO_DEPRECATE
#include "CErrors.h"

CFileErrorCode::CFileErrorCode()
{
	file = NULL;
}

CFileErrorCode::CFileErrorCode(std::string fileName)
{
	file = fopen(fileName.c_str(), "w+");
	
}

CFileErrorCode::~CFileErrorCode()
{
	if (file != NULL)
		fclose(file);
}

bool CFileErrorCode::OpenFile(std::string fileName)
{
	file = fopen(fileName.c_str(), "w+");
	if (file == NULL)return false;
	else return true;
}

bool CFileErrorCode::PrintLine(std::string sText)
{
	if (file == NULL) return false;
	int result = fprintf(file,sText.c_str());
	if (result < 0) return false;
	else return true;
}

bool CFileErrorCode::PrintManyLines(std::vector<std::string> sText)
{
	std::vector<std::string>::iterator itr;
	for (itr = sText.begin(); itr != sText.end(); itr++)
	{
		bool result = PrintLine(*itr);
		bool result2 = PrintLine("\n");
		if (result == false || result2==false) return false;
	}
	return true;
}
bool CFileErrorCode::CloseFile() {
	if (file != NULL) {
		int result = fclose(file);
		if (result < 0) return false;
		return true;
	}
	return true;
}
