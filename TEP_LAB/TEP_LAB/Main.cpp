#include <iostream>
#include "CStaticTree.h"
#include "CDynamicTree.h"




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
	std::cout << std::endl;
	CTreeDynamic<int> tree;
	tree.GetRoot()->AddNewChild();
	tree.GetRoot()->AddNewChild();
	tree.GetRoot()->GetChild(0)->SetValue(10);
	tree.GetRoot()->GetChild(1)->SetValue(20);
	tree.GetRoot()->GetChild(0)->AddNewChild();
	tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(30);
	tree.PrintTree();
	CTreeDynamic<int> tree2;
	tree.GetRoot()->AddNewChild();
	tree.GetRoot()->AddNewChild();
	tree.GetRoot()->GetChild(0)->SetValue(100);
	tree.GetRoot()->GetChild(1)->SetValue(200);
	tree.GetRoot()->GetChild(0)->AddNewChild();
	tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(300);
	tree.PrintTree();
	std::cout << std::endl;
	std::cout << " same: " << tree.SameTree(tree.GetRoot(), tree2.GetRoot()) << std::endl;
	std::cout << " same: " << tree.MoveSubtree(tree.GetRoot()->GetChild(0), tree2.GetRoot()->GetChild(0)) << std::endl;
	tree.PrintTree();
	std::cout <<  std::endl;
	tree2.PrintTree();
	std::cout << " same: " << tree.SameTree(tree.GetRoot()->GetChild(2), tree.GetRoot()->GetChild(0)) << std::endl;
}
