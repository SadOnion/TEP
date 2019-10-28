#pragma once
#include <cstdio>
#include <string>
#include <vector>

class CFileLastError {
public:
	CFileLastError();
	CFileLastError(std::string fileName);
	~CFileLastError();
	void OpenFile(std::string fileName);
	void PrintLine(std::string sText);
	void PrintManyLines(std::vector<std::string> sText);
	bool GetLastError() { return(lastError); }
private:
	FILE* file;
	bool lastError;
};