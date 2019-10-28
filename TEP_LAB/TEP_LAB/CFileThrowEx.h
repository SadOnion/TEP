#include <cstdio>
#include <string>
#include <vector>
#pragma once
class CFileThrowEx {
public:
	CFileThrowEx();
	CFileThrowEx(std::string fileName);
	~CFileThrowEx();
	void OpenFile(std::string fileName);
	void PrintLine(std::string sText);
	void PrintManyLines(std::vector<std::string> sText);
private:
	FILE* file;
};
