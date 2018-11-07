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

	void FindPredecessor(int item);
	void FindSucessor(int item);
	void Delete(int item);  //Bonus Points for Transpose helper function
	
	NodePtr ReturnRoot();
	

private:
	Node *root;
	

};

#endif