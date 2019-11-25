#include <iostream>
#include "CStaticTree.h"
#include "CDynamicTree.h"
#include "CMySmartPointer.h"



int main()
{
	CMySmartPointer<CTreeDynamic<int>> ptr(new CTreeDynamic<int>());

}
