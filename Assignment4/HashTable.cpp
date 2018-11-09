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
//Narrative: Inserts a value into the bucket
//	Pre - condition : key has a value and the buckets have been initialized
//	Post - condition : node with the value key is added to the table.Length is updated

	bucket[Hash(key)].Insert(key);
	length++;
	return;
}

void HashTable::InsertSorted(int key) {
//Narrative:  Adds sorted functionality to the hashtable class, same as insert but sorted buckets
//	Pre - condition : same as Insert
//	Post - condition : same as Insert

	bucket[Hash(key)].InsertSorted(key);
	length++;
	return;
}

bool HashTable::Search(int key) {
//Narrative: returns if key was found in the table
//	Pre - condition : the table is initialized
//	Post - condition : returns true if key is found in table

	return bucket[Hash(key)].Search(key);
}

int HashTable::numCompares(int key) {
//Narrative: searches the table for key
//	Pre - condition : table initialized
//	Post - condition : returns amount of compares made to attempt finding key

	return bucket[Hash(key)].NumCompares(key);
}

int HashTable::numComparesSorted(int key) {
//Narrative: Same as numCompares but sorted
//	Pre - condition : Same as numCompares but sorted
//	Post - condition : Same as numCompares but sorted

	return bucket[Hash(key)].NumComparesSorted(key);
}


void HashTable::PrintTable(){
//Narrative: Prints the contents of each bucket
//	Pre - condition : table initialized
//	Post - condition : information printed to screen

	for (int i = 0; i < 10; i++) {
		std::cout << "Bucket " << i << " : ";
		bucket[i].PrintList();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}