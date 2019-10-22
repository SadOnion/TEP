#include "CFileLastError.h"

CFileLastError::CFileLastError()
{
	lastError = false;
}

CFileLastError::CFileLastError(std::string sFileName)
{
	lastError = false;

}

CFileLastError::~CFileLastError()
{
}

void CFileLastError::OpenFile(std::string sFileName)
{
	lastError = false;
}

void CFileLastError::PrintLine(std::string sText)
{
	lastError = false;
}

void CFileLastError::PrintManyLines(std::vector<std::string> sText)
{
	lastError = false;
}
