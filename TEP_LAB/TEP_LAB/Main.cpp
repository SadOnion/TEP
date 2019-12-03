#include <iostream>
#include "CStaticTree.h"
#include "CDynamicTree.h"
#include "CMySmartPointer.h"
#include "CTable.h"


int main()
{
	CTable tab1;
	CTable tab2;
	CTable tab3;
	tab1.SetValueAt(0,1);
	tab1.SetValueAt(1,2);
	tab1.SetValueAt(2,3);

	tab2.SetValueAt(0,10);
	tab2.SetValueAt(1,20);
	tab2.SetValueAt(2,30);
	
	tab3 = tab1+tab2;
	tab1.Print();
	tab2.Print();
	tab3.Print();
	int x;
	std::cin>>x;
}
