#ifndef BST_H
#define BST_H

#include "NodeT.cpp"

class BST {

public:
	BST();
	~BST();
	void InorderTraverse(NodePtr node);
	void Insert(int item);
	NodePtr Search(NodePtr x, int item);
	NodePtr FindPredecessor(int item);
	NodePtr FindSucessor(int item);

	void Delete(int item);  //Bonus Points for Transpose helper function
	
	NodePtr ReturnRoot();
	

private:
	Node *root;
	NodePtr FindMin(NodePtr node);
	void DestroyTree(NodePtr node); //Recursive Destructor Helper Function

};

#endif