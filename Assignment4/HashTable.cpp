#include "HashTable.h"
#include <iostream>



HashTable::HashTable(){
	length = 0;
}


HashTable::~HashTable(){
	for (LinkedList i : bucket) {
		i.~LinkedList();
	}
}


void HashTable::Insert(int key) {
	bucket[Hash(key)].Insert(key);
	length++;
	return;
}

void HashTable::InsertSorted(int key) {
	bucket[Hash(key)].InsertSorted(key);
	length++;
	return;
}

bool HashTable::Search(int key) {
	return bucket[Hash(key)].Search(key);
}

int HashTable::numCompares(int key) {
	return bucket[Hash(key)].NumCompares(key);
}

int HashTable::numComparesSorted(int key) {
	return bucket[Hash(key)].NumComparesSorted(key);
}


void HashTable::PrintTable(){
	for (int i = 0; i < 10; i++) {
		std::cout << "Bucket " << i << " : ";
		bucket[i].PrintList();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}