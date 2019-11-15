#include "CTree.h"

CTreeStatic::CTreeStatic()
{
	root = CNodeStatic();
}

CTreeStatic::~CTreeStatic()
{
}

void CTreeStatic::PrintTree()
{
	root.PrintAllBelow();
}
