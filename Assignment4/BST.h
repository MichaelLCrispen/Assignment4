#ifndef BST_H
#define BST_H

#include "NodeT.cpp"

class BST {

public:
	BST();
	~BST();
	BST(const BST & otherBST);
	const BST& operator=(const BST & otherBST);

	void InorderTraverse(NodePtr node);
	void Insert(int item);
	NodePtr Search(NodePtr x, int item);
	NodePtr FindPredecessor(int item);
	NodePtr FindSucessor(int item);

	NodePtr NumComparisons(NodePtr x, int item, int& numComparisons);

	//void Delete(int item);  //Bonus Points for Transpose helper function
	
	NodePtr ReturnRoot(); //This is used so that we can use the root of the tree in other functions
	int ValueofNode(NodePtr node);
	int ReturnLength() { return length; }

private:
	Node *root;
	int length;

	NodePtr FindMin(NodePtr node);
	NodePtr FindMax(NodePtr node);
	void BurnForest(NodePtr node); //Recursive Destructor Helper Function
	void CreateTree(NodePtr node);	//Recursive Copy Constructer Helper Function

};

#endif