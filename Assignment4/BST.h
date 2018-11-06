#pragma once

#ifndef BST_H
#define BST_H


class BST
{

private:
	typedef int ItemType;
	struct NodeType;
	typedef NodeType* NodePtr;


public:
	BST();
	void Insert(NodePtr item);
	void InorderTraverse(NodePtr node);

	/*
	void Search(int key);
	void FindPredecessor(Item);
	void FindSucessor(Item);
	*/
	
	

private:
	NodePtr root;

	struct NodeType {
		int key;
		NodePtr left, right;
	};


};

#endif