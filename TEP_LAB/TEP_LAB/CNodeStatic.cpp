#include "CNodeStatic.h"

CNodeStatic::~CNodeStatic()
{
}

void CNodeStatic::AddNewChild()
{
	CNodeStatic newChild;
	newChild.parentNode = this;
	children.push_back(newChild);
}

CNodeStatic* CNodeStatic::GetChild(int childOffset)
{
	if (childOffset >= children.size()) return NULL;
	CNodeStatic* child = &children.at(childOffset);
	return child;
}

void CNodeStatic::PrintAllBelow()
{
	Print();
	for (size_t i = 0; i < children.size(); i++)
	{
		children.at(i).PrintAllBelow();
	}
}

void CNodeStatic::PrintUp()
{
	Print();
	if(parentNode != NULL) parentNode->PrintUp();
}
