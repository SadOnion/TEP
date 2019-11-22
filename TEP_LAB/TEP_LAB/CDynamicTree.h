#pragma once
#include <iostream>
#include <vector>

template <typename T>
class CNodeDynamic
{
public:
	CNodeDynamic() { value = 0; parentNode = NULL; };
	~CNodeDynamic();
	void SetValue(T newVal) { value = newVal; };
	int GetChildrenNumber() { return(children.size()); };
	void AddNewChild();
	void AddNewChild(CNodeDynamic<T>* node);
	CNodeDynamic<T>* GetChild(int iChildOffset);
	void Print() { std::cout << " " << value; };
	void PrintAllBelow();
private:
	std::vector<CNodeDynamic*> children;
	CNodeDynamic<T>* parentNode;
	T value;
	template <typename U>
	friend class CTreeDynamic;
};
template <typename T>
class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* GetRoot() { return root; }
	void PrintTree();
	bool MoveSubtree(CNodeDynamic<T> *parentNode,CNodeDynamic<T> *newChildNode);
	bool SameTree(CNodeDynamic<T>* node1,CNodeDynamic<T>* node2);
	
private:
	CNodeDynamic<T>* root;
	template <typename U>
	friend class CNodeDynamic;
};

#include "CDynamicTree.cpp"
