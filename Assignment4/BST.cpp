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
//Narrative: Inserts a node in the tree with value of item
//	Pre - condition : tree initialized
//	Post - condition : node with key of item inserted into tree, length updated


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
//Narrative: prints the contents of the tree in sorted order with node as root of the tree
//	Pre - condition : tree initialized
//	Post - condition : contents of the tree printed  to screen

	if(node != NULL){
		InorderTraverse(node->left);
		std::cout << node->key << " ";
		InorderTraverse(node->right);
	}


	return;
}

NodePtr BST::Search(NodePtr x, int item){
//Narrative: Searches for an item in the list with x as root recursively
//	Pre - condition : tree initialized
//	Post - condition : if item is not found a null pointer is returned.Otherwise node with key = item is returned


	if( (x == NULL) || (x->key == item)) {
		return x;
	}
	if (item < x->key)
		return Search(x->left, item);
	else
		return Search(x->right, item);
}

NodePtr BST::NumComparisons(NodePtr x, int item, int& numComparisons) {
//Narrative: Calculates the number of comparisons it takes to find item in tree with x as root.Uses numComparisons as an output parameter
//	Pre - condition : initialized tree
//	Post - condition : numComparisons will have the value of the number of comparisons this function has made.
//
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
//Narrative: finds the sucessor of the node with key = item in the tree
//	Pre - condition : item is in the list
//	Post - condition : node that is sucessor of node is returned or null if successor is not found

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
//Narrative: finds the predecessor of the node with key = item in the tree
//	Pre - condition : item is in the list
//	Post - condition : node that is predecessor of node is returned or null if predecessor is not found

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
//Narrative: helps client use root of a tree for functions
//	Pre - condition : tree initialized
//	Post - condition : root returned

	return root;
}


NodePtr BST::FindMin(NodePtr node) {
//Narrative: Finds the minimum value in the tree with node as root
//	Pre - condition : tree is initialized
//	Post - condition : node with the lowest key returned

	NodePtr current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

NodePtr BST::FindMax(NodePtr node) {
//Narrative: Finds the max value in the tree with node as root
//	Pre - condition : tree is initialized
//	Post - condition : node with the highest key returned

	NodePtr current = node;

	while (current->right != NULL)
		current = current->right;
	return current;
}

void BST::BurnForest(NodePtr node) {
//Narrative: Helper function for the destructor.Visits every node and deletes recursively
//	Pre - condition : tree initialized
//	Post - condition : all nodes deleted

	if (node != NULL){
		BurnForest(node->left);
		BurnForest(node->right);
		delete node;
	}
}


void BST::CreateTree(NodePtr node) {
//Narrative: this inserts into the current tree with all of the values in the tree of node with node as the root
//	Pre - condition : otherlist is initalized
//	Post - condition : all values of tree of node inserted.

	if (node != NULL) {
		Insert(node -> key);
		CreateTree(node->left);
		CreateTree(node->right);
	}

	return;
}

int BST::ValueofNode(NodePtr node) {
//Narrative: returns the key of the node
//	Pre - condition : node is either null or is pointing to a current node
//	Post - condition : -1 if node is null or value of key is returned

	if(node)
	return node->key;

	return -1;
}