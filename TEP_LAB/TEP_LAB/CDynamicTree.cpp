#include "CDynamicTree.h"

CNodeDynamic::~CNodeDynamic()
{
	for (size_t i = 0; i < children.size(); i++)
	{
		delete children.at(i);
	}
}

void CNodeDynamic::AddNewChild()
{
	CNodeDynamic* newNode = new CNodeDynamic();
	newNode->parentNode = this;
	children.push_back(newNode);
}

CTreeDynamic* CNodeDynamic::GetChild(int iChildOffset)
{
	if(iChildOffset >= children.size()) return NULL;
	CTreeDynamic* tree;
	CNodeDynamic* node = children.at(iChildOffset);
	tree->GetRoot()->SetValue(node->value);
	tree->GetRoot()->children = node->children;
	return tree;
	
}

void CNodeDynamic::PrintAllBelow()
{
	Print();
	for (size_t i = 0; i < children.size(); i++)
	{
		children.at(i)->PrintAllBelow();
	}
}

CTreeDynamic::CTreeDynamic()
{
	root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic()
{
	delete root;
}

void CTreeDynamic::PrintTree()
{
	root->PrintAllBelow();
}

bool CTreeDynamic::MoveSubtree(CNodeDynamic* parentNode, CNodeDynamic* newChildNode)
{
	parentNode->AddNewChild();
	CNodeDynamic* newNode = new CNodeDynamic();
	newNode->
	delete newChildNode;
	parentNode->GetChild(parentNode->GetChildrenNumber() - 1)->root = newChildNode;
	delete newChildNode;
	return false;
}
