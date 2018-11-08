#include "BST.h"
#include<iostream>



BST::BST()
{
	root = NULL;
	length = 0;
}

BST::~BST() {
	BurnForest(root);
	root = NULL;
}

BST::BST(const BST & otherBST) {
	root = NULL;
	length = 0;
	CreateTree(otherBST.root);

	return;
}

const BST& BST::operator=(const BST & otherBST) {
	root = NULL;
	length = 0;
	CreateTree(otherBST.root);

	return *this;
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
		
	length++;
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

	if( (x == NULL) || (x->key == item)) {
		return x;
	}
	if (item < x->key)
		return Search(x->left, item);
	else
		return Search(x->right, item);
}

NodePtr BST::NumComparisons(NodePtr x, int item, int& numComparisons) {
	
	numComparisons++;

	if ((x == NULL) || (x->key == item)) {
		return x;
	}
	if (item < x->key)
		return NumComparisons(x->left, item, numComparisons);
	else
		return NumComparisons(x->right, item, numComparisons);
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
	NodePtr x = Search(root, item);

	if (x == NULL)
		return NULL;

	if (x->left != NULL)
		return FindMax(x->left);

	NodePtr y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}


	return y;
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

NodePtr BST::FindMax(NodePtr node) {
	NodePtr current = node;

	while (current->right != NULL)
		current = current->right;
	return current;
}

void BST::BurnForest(NodePtr node) {
	
	if (node != NULL){
		BurnForest(node->left);
		BurnForest(node->right);
		delete node;
	}
}


void BST::CreateTree(NodePtr node) {

	if (node != NULL) {
		Insert(node -> key);
		CreateTree(node->left);
		CreateTree(node->right);
	}

	return;
}

int BST::ValueofNode(NodePtr node) {
	if(node)
	return node->key;

	return -1;
}