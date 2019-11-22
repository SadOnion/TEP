#include "CDynamicTree.h"

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	for (size_t i = 0; i < children.size(); i++)
	{
		delete children.at(i);
	}
}

template <typename T>
void CNodeDynamic<T>::AddNewChild()
{
	CNodeDynamic* newNode = new CNodeDynamic();
	newNode->parentNode = this;
	children.push_back(newNode);
}
template <typename T>
void CNodeDynamic<T>::AddNewChild(CNodeDynamic<T>* node)
{
	children.push_back(node);
}
template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::GetChild(int iChildOffset)
{
	if (iChildOffset >= children.size()) return NULL;
	return children.at(iChildOffset);
}
template <typename T>
void CNodeDynamic<T>::PrintAllBelow()
{
	Print();

	for (size_t i = 0; i < children.size(); i++)
	{
		children.at(i)->PrintAllBelow();
	}
}
template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	root = new CNodeDynamic<T>();
};
template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete root;
};
template <typename T>
void CTreeDynamic<T>::PrintTree()
{
	root->PrintAllBelow();
}
template <typename T>
bool CTreeDynamic<T>::MoveSubtree(CNodeDynamic<T> * parentNode, CNodeDynamic<T> * newChildNode)
{
	if (parentNode == NULL || newChildNode == NULL) return false;
	parentNode->AddNewChild(newChildNode);

	CNodeDynamic<T> * parent = newChildNode->parentNode;

	for (size_t i = 0; i < parent->GetChildrenNumber(); i++)
	{
		if (parent->children.at(i) == newChildNode) parent->children.erase(parent->children.begin() + i);
	}
	return true;
}
template <typename T>
bool CTreeDynamic<T>::SameTree(CNodeDynamic<T> * node1, CNodeDynamic<T> * node2)
{
	CNodeDynamic<T>* root1 = node1;
	CNodeDynamic<T>* root2 = node2;
	if (root1 == NULL) return false;
	if (root2 == NULL) return false;
	while (root1->parentNode != NULL) {
		root1 = root1->parentNode;
	}
	while (root2->parentNode != NULL) {
		root2 = root2->parentNode;
	}
	return root1 == root2;

}






















