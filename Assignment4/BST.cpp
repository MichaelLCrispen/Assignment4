#include "BST.h"
#include<iostream>



BST::BST()
{
	root = nullptr;
}

BST::~BST() {
	DestroyTree(root);
}


void BST::Insert(int Item){
	
	NodePtr temp = new Node;
	temp->key = Item;

	NodePtr y = NULL;
	NodePtr x = root;

	while (x != NULL) {
		y = x;
		if (temp->key < x->key)
			x = x->left;
		else
			x = x->right;
		}

	temp-> parent = y;
	if (y == NULL)
		root = temp;
	else if (temp->key < y->key)
		y->left = temp;
	else
		y->right = temp;
		
	return;
}



void BST::InorderTraverse(NodePtr node) {
	
	if(node != NULL){
		InorderTraverse(node->left);
		std::cout << node->key << " ";
		InorderTraverse(node->right);
	}


	return;
}

NodePtr BST::Search(NodePtr x, int item){

	if( (x == NULL) || (root->key == item)) {
		return x;
	}
	if (item < x->key)
		return Search(x->left, item);
	else
		return Search(x->right, item);
}


NodePtr BST::FindSucessor(int item) {
	NodePtr x = Search(root, item);

	if (x == NULL)
		return NULL;

	if (x->right != NULL)
		return FindMin(x->right);

	NodePtr y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;

}

NodePtr BST::FindPredecessor(int item){
	return NULL;
}

void BST::Delete(int item) {

}


NodePtr BST::ReturnRoot() {
	return root;
}


NodePtr BST::FindMin(NodePtr node) {
	NodePtr current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

void BST::DestroyTree(NodePtr node) {
	
	if (node != NULL){
		DestroyTree(node->left);
		DestroyTree(node->right);
		delete node;
	}
}