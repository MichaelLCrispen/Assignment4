#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList
{

private :
	struct LLNode;
	typedef LLNode* NodePtr;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& otherlinkedlist);
	const LinkedList& operator=(const LinkedList& otherLinkedList);

	void Insert(int data);
	void InsertSorted(int data);
	bool Search(int key);
	int NumComparesSorted(int key);
	int NumCompares(int key);
	void PrintList();

private:
	struct LLNode {
		int key;
		NodePtr next;
	};

	NodePtr head;
	int length;
};

#endif