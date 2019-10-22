#include <iostream>
#include "CTable.h"
#include "Utils.h"


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

void List4() {

}
int main()
{
	List3();
}
