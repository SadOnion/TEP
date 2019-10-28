#include "CTable.h"
#include <iostream>
#include "Utils.h"


CTable::CTable()
{
	name = DEFAULT_NAME;
	size = DEFAULT_SIZE;
	std::cout << "bezp: " + name << std::endl;
	table = new int[size];
}

CTable::CTable(std::string name, int tableLength)
{
	if (tableLength <= 0) {
		this->name = DEFAULT_NAME;
		size = DEFAULT_SIZE;
	}
	else {
	this->name = name;
	size = tableLength;
	}
	table = new int[size];
	std::cout << "parametr: " + name << std::endl;
}

CTable::CTable(const CTable& other)
{
	name = other.name + "_copy";
	size = other.size;
	table = new int[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = other.table[i];
	}
	std::cout << "kopiuj: " + name << std::endl;
}

CTable::~CTable()
{
	std::cout << "usuwam: " + name << std::endl;
	delete table;
}

void CTable::SetName(std::string newName)
{
	name = newName;
}

bool CTable::SetNewSize(int newSize)
{
	if (newSize == size) return true;

	int* tempTable = new int[newSize];
	if (newSize > size) 
	{
		for (int i = 0; i < newSize; i++)
		{
			tempTable[i] = table[i % size];
		}
	}
	else 
	{
		for (int i = 0; i < newSize; i++)
		{
			tempTable[i] = table[i];
		}
	}
	size = newSize;
	delete table;
	table = tempTable;
	return true;
}

void CTable::SetValueAt(int iOffset, int newValue)
{
	if(iOffset<size && iOffset>=0)
	table[iOffset] = newValue;
}

void CTable::SetValueAt(int newValue)
{
	for (size_t i = 0; i < size; i++)
	{
		table[i] = newValue;
	}
}

void CTable::Print()
{
	std::cout << name << std::endl;
	PrintTable(table, size);
}

void CTable::Double()
{
	SetNewSize(size * 2);
}

CTable* CTable::Clone()
{
	CTable* newTable = new CTable(name,size);
	for (size_t i = 0; i < size; i++)
	{
		newTable->table[i] = table[i];
	}
	return newTable;
}

CTable CTable::operator+(CTable& otherTab)
{
	int* tempTab = table;
	table = new int[size + otherTab.size];
	for (int i = 0; i < size; i++)
	{
		table[i] = tempTab[i];
	}
	for (int i = size; i < size+otherTab.size; i++)
	{
		table[i] = otherTab.table[i];
	}
	delete tempTab;
	return *this;
}
