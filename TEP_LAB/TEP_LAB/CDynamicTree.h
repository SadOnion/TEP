#pragma once
#include <iostream>
#include <vector>

class CNodeDynamic
{
public:
	CNodeDynamic() { value = 0; parentNode = NULL; };
	~CNodeDynamic();
	void SetValue(int iNewVal) { value = iNewVal; };
	int GetChildrenNumber() { return(children.size()); };
	void AddNewChild();
	CTreeDynamic* GetChild(int iChildOffset);
	void Print() { std::cout << " " << value; };
	void PrintAllBelow();
private:
	std::vector<CNodeDynamic*> children;
	CNodeDynamic* parentNode;
	int value;
};
class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* GetRoot() { return(root); }
	void PrintTree();
	bool MoveSubtree(CNodeDynamic *parentNode,CNodeDynamic *newChildNode);
private:
	CNodeDynamic* root;
};