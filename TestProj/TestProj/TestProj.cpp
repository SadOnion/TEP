
#include <iostream>
#include "CTable.h"


template<typename T>
void PrintTable(T* tab, T size);


void AllocTableAdd5(int iSize) {

	if (iSize <= 0) {
		return;
	}
	const int OFFSET_PLUS = 5;

	int* pi_table;
	pi_table = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		pi_table[i] = i + OFFSET_PLUS;
	}

	PrintTable(pi_table,iSize);
	
	delete[] pi_table;

	
}
template<typename T>
void PrintTable(T* tab,T size) {

	for (int i = 0; i < size; i++)
	{
		std::cout << tab[i] << std::endl;
	}
}

bool AllocTable2Dim(int*** piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY < 0) return false;
	
	*piTable = new int* [iSizeX];

	for (int i = 0; i < iSizeX; i++)
	{
		(*piTable)[i] = new int[iSizeY];
	}

	
	return true;
}

bool DeallocTable2Dim(int** piTable, int iSizeX) {

	if (iSizeX <= 0)return false;

	for (int i = 0; i < iSizeX; i++)
	{
		delete[] piTable[i];
	}

	delete[] piTable;
	return true;
}
void List1() {

	AllocTableAdd5(5);

	int** pi_table;

	if (AllocTable2Dim(&pi_table, 5, 3)) {

		DeallocTable2Dim(pi_table, 5);

	}
}

void ModifyTable(CTable* tab, int newSize) {
	tab->SetNewSize(newSize);
}

void ModifyTable(CTable tab, int newSize) {
	tab.SetNewSize(newSize);
}

void List2() {
	CTable table("Table1",3);
	CTable table1("Table2",4);
	ModifyTable(table, 5);
	
	ModifyTable(&table1, 5);

	CTable* tabTab = new CTable[3];

	delete[] tabTab;

	CTable tabTable[4];

	
	
}

int main()
{
	//List1();

	List2();
	
	
	
}



