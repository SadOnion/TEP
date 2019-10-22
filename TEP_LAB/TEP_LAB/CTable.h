#pragma once
#include <string>

class CTable {

private:
	int DEFAULT_SIZE = 3;
	std::string DEFAULT_NAME = "DefaultName";
	std::string name;
	int size;
	int* table;
public:

	CTable();
	CTable(std::string name, int tableLength);
	CTable(const CTable& other);
	~CTable();

	void SetName(std::string newName);
	bool SetNewSize(int newSize);
	void SetValueAt(int iOffset, int newValue);
	void Print();
	CTable* Clone();

	CTable operator+(CTable& otherTab);
};