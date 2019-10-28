#include <iostream>
#include "CTable.h"
#include "Utils.h"
#include "CErrors.h"


void ModifyTable(CTable* tab, int newSize) {
	tab->SetNewSize(newSize);
}

void ModifyTable(CTable tab, int newSize) {
	tab.SetNewSize(newSize);
}

void List2() {

	CTable table1("Table1", 3);
	CTable table2("Table2", 4);
	

	table2.SetValueAt(0, 1);
	table2.SetValueAt(1, 2);
	table2.SetValueAt(2, 3);
	table2.SetValueAt(3, 4);
	table1.Print();
	table2.Print();
	table2.SetNewSize(7);
	table2.Print();
	table2.Double();
	table2.SetValueAt(10);
	table2.Print();
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

void List4() {
	CFileErrorCode cFileError;
	CFileLastError cFileLastError;
	CFileThrowEx cFileThrowEx;
	std::string fileName = "TestFile.txt";
	
	
	
	
	for (size_t i = 0; i < 10; i++)
	{
		cFileLastError.OpenFile(fileName);
		std::cout << cFileLastError.GetLastError()<<std::endl;
		std::cout << cFileError.OpenFile(fileName) << std::endl;
		cFileThrowEx.OpenFile(fileName);
	}
	
}
int main()
{
	List2();
}
