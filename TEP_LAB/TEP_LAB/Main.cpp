#include <iostream>
#include "CTable.h"
#include "Utils.h"
#include "CErrors.h"
#include "CNodeStatic.h"



void List3() {
	
	CTable tab0, tab1,tab2,tab3;
	/*
	tab0.SetNewSize(6);
	tab1.SetNewSize(4);

	tab0.SetValueAt(0, 1);
	tab0.SetValueAt(1, 2);
	tab0.SetValueAt(2, 3);
	tab0.SetValueAt(3, 4);
	tab0.SetValueAt(4, 5);
	tab0.SetValueAt(5, 6);
	tab1.SetValueAt(0, 51);
	tab1.SetValueAt(1, 52);
	tab1.SetValueAt(2, 53);
	tab1.SetValueAt(3, 54);
	tab1.SetValueAt(2, 123);
	*/

	tab0.Print();
	tab1.Print();
	tab2.Print();
	tab2 = tab1 =tab0;
	std::cout << "Print after tab2 = tab1 =tab0 : " << std::endl;
	tab2.Print();
	tab3 = tab2 -= 2;
	std::cout << "Print after tab3 = tab2-=2 : " << std::endl;
	tab3.Print();
	tab3 -= 2;
	tab3.Print();
	CTable t = tab1 + tab2;
}

void ThrowEx() {
	std::string fileName = "TestFile.txt";
	CFileThrowEx cFileThrowEx;
	
	
	
	std::vector<std::string> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(std::to_string(i));
		try {
			cFileThrowEx.OpenFile("*dasd");
			cFileThrowEx.CloseFile();
		}
		catch (int e) {
			
			std::cout << i<<".Exception code:" << e<<std::endl;
		}
		try {
			cFileThrowEx.OpenFile("TestFile.txt");
			cFileThrowEx.PrintManyLines(vec);
			cFileThrowEx.CloseFile();
		}
		catch (int e) {
			std::cout << ".Exception code:" << e << std::endl;
		}
		
	}
	
}
void LastError() {
	std::string fileName = "TestFile.txt";
	CFileLastError cFileLastError;

	std::vector<std::string> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(std::to_string(i*2));
		cFileLastError.OpenFile("*das");
		if (cFileLastError.GetLastError()) std::cout << i << ".Unable to open file" << std::endl;
		else cFileLastError.CloseFile();
		cFileLastError.OpenFile(fileName);
		if (!cFileLastError.GetLastError()) cFileLastError.PrintManyLines(vec);
		cFileLastError.CloseFile();
	}
}
void ErrorCode() {
	std::string fileName = "TestFile.txt";
	CFileErrorCode cFileErrorCode;

	std::vector<std::string> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(std::to_string(i * 3));
		
		if (cFileErrorCode.OpenFile("*das") == false) 
		{
			std::cout << i << ".Unable to open file" << std::endl;
		}
		else {
			cFileErrorCode.CloseFile();
		}

		if (cFileErrorCode.OpenFile(fileName)) 
		{
			cFileErrorCode.PrintManyLines(vec);
			cFileErrorCode.CloseFile();
		}
	}
}
int main()
{
	CNodeStatic c_root;
	c_root.AddNewChild();
	c_root.AddNewChild();
	c_root.GetChild(0)->SetValue(1);
	c_root.GetChild(1)->SetValue(2);
	c_root.GetChild(0)->AddNewChild();
	c_root.GetChild(0)->AddNewChild();
	c_root.GetChild(0)->GetChild(0)->SetValue(11);
	c_root.GetChild(0)->GetChild(1)->SetValue(12);
	c_root.GetChild(1)->AddNewChild();
	c_root.GetChild(1)->AddNewChild();
	c_root.GetChild(1)->GetChild(0)->SetValue(21);
	c_root.GetChild(1)->GetChild(1)->SetValue(22);
	c_root.PrintAllBelow();

	c_root.GetChild(0)->GetChild(1)->PrintUp();
}
