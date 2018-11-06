#include "BST.h"
#include<iostream>



BST::BST()
{
	root = nullptr;
}


void BST::Insert(NodePtr Item)
{
	if ()

		return;
}



void BST::InorderTraverse(NodePtr node) {
	if (node == nullptr)
		return;

	InorderTraverse(node->left);
	std::cout << node->key << " ";
	InorderTraverse(node->right);
}