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
	this->name = name;
	size = tableLength;
	std::cout << "parametr: " + name << std::endl;
	table = new int[size];
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
		for (int i = 0; i < size; i++)
		{
			tempTable[i] = table[i];
		}

		for (int i = size; i < newSize; i++)
		{
			tempTable[i] = 0;
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

void CTable::Print()
{
	PrintTable(table, size);
}

CTable* CTable::Clone()
{
	CTable* newTable = new CTable(*this);
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
