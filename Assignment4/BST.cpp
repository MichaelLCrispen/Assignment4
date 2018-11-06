#include "BST.h"
#include<iostream>



BST::BST()
{
	root = nullptr;
}


void BST::Insert(int key)
{
	if()
}



void BST::InorderTraverse(NodePtr node) {
	if (node == nullptr)
		return;

	InorderTraverse(node->left);
	std::cout << node->key << " ";
	InorderTraverse(node->right);
}