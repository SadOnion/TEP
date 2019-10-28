#pragma once
#include <string>
#include <vector>
#include <cstdio>

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
