#include <string>
#include <vector>
#pragma once

class CFileErrorCode {
public:
	CFileErrorCode();
	CFileErrorCode(std::string fileName);
	~CFileErrorCode();
	bool OpenFile(std::string fileName);
	bool PrintLine(std::string sText);
	bool PrintManyLines(std::vector<std::string> sText);
private:
	FILE* file;
};
