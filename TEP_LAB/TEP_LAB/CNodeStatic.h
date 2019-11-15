#pragma once
#include <iostream>
#include <vector>
class CNodeStatic {
public:
	CNodeStatic() { value = 0; parentNode = NULL; };
	~CNodeStatic();
	void SetValue(int newValue) { value = newValue; };
	int GetChildrenNumber() { return children.size(); };
	void AddNewChild();
	CNodeStatic* GetChild(int childOffset);

	void Print() { std::cout << " " << value; }
	void PrintAllBelow();
	void PrintUp();
private:
	std::vector<CNodeStatic> children;
	CNodeStatic* parentNode;
	int value;
};	
