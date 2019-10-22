#include <iostream>
#include "CTable.h"
#include "Utils.h"



int* AllocTableAdd5(int iSize) {

	if (iSize <= 0) {
		return 0;
	}
	const int OFFSET_PLUS = 5;

	int* pi_table;
	pi_table = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		pi_table[i] = i + OFFSET_PLUS;
	}

	return pi_table;
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

	delete piTable;
	return true;
}
void Show2DimTable(int** table, int xSize, int ySize) {

	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			std::cout << table[i][j] << "; ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Fill2DimTable(int** table, int xSize, int ySize, int value) {

	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			table[i][j] = value;
		}

	}
}

void FillBorderTable2Dim(int** table, int xSize, int ySize, int value) {

	for (int i = 0; i < ySize; i++)
	{
		table[0][i] = value;
		table[xSize - 1][i] = value;
	}
	for (int i = 0; i < xSize; i++)
	{
		table[i][0] = value;
		table[i][ySize - 1] = value;
	}
}
void List1() {

	int size = 5;

	int* tablePtr = AllocTableAdd5(size);
	if (tablePtr != 0) {
		PrintTable(tablePtr, size);
		delete tablePtr;
	}
	int** pi_table;

	int xSize = 10;
	int ySize = 4;

	if (AllocTable2Dim(&pi_table, xSize, ySize)) {

		Fill2DimTable(pi_table, xSize, ySize, 10);
		Show2DimTable(pi_table, xSize, ySize);
		FillBorderTable2Dim(pi_table, xSize, ySize, 99);
		Show2DimTable(pi_table, xSize, ySize);
		DeallocTable2Dim(pi_table, xSize);

	}
}

void ModifyTable(CTable* tab, int newSize) {
	tab->SetNewSize(newSize);
}

void ModifyTable(CTable tab, int newSize) {
	tab.SetNewSize(newSize);
}

void List2() {

	CTable table("Table1", 3);
	CTable table1("Table2", 4);
	ModifyTable(table, 5);

	ModifyTable(&table1, 5);

	CTable* tabTab = new CTable[3];

	delete[] tabTab;

	CTable tabTable[4];
}

void List3() {
	
	CTable tab0, tab1;
	tab0.SetNewSize(6);
	tab1.SetNewSize(4);

	tab0.SetValueAt(0, 1);
	tab0.SetValueAt(1, 2);
	tab0.SetValueAt(2, 3);
	tab0.SetValueAt(3, 4);
	tab1.SetValueAt(0, 51);
	tab1.SetValueAt(1, 52);
	tab1.SetValueAt(2, 53);
	tab1.SetValueAt(3, 54);
	tab0 = tab1;
	tab1.SetValueAt(2, 123);
	tab0.Print();
	tab1.Print();

}

int main()
{
	List3();
}
