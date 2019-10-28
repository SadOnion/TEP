#include <iostream>
#include "CTable.h"
#include "Utils.h"
#include "CErrors.h"




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
	
}
