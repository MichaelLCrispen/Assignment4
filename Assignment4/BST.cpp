#include "BST.h"
#include<iostream>



BST::BST()
{
	root = nullptr;
}

BST::~BST() {

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

void BST::FindPredecessor(int item){

}

void BST::FindSucessor(int item){

}

void BST::Delete(int item) {

}


NodePtr BST::ReturnRoot() {
	return root;
}

