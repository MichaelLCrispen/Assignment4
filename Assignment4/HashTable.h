#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"LinkedList.h"


class HashTable
{
public:
	HashTable();
	~HashTable();

	void Insert(int key);
	void InsertSorted(int key);
	bool Search(int key);
	int numCompares(int key);
	int numComparesSorted(int key);
	void PrintTable();

	int ReturnLength() { return length; }
private:

	LinkedList bucket[10];
	int length;

	int Hash(int key) {return (key % 10);}
};

#endif