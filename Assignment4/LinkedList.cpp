#include "LinkedList.h"
#include <iostream>



LinkedList::LinkedList(){
	length = 0;
	head = nullptr;
}


LinkedList::~LinkedList(){
	NodePtr temp;
	NodePtr curr = head;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = nullptr;
	length = 0;
	return;
}



LinkedList::LinkedList(const LinkedList& otherLinkedList) {
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr)
		head = nullptr;

	else {
		from = otherLinkedList.head;
		head = new LLNode;
		head->key = from->key;

		to = head;
		from = from->next;

		while (from != nullptr) {
			to->next = new LLNode;
			to = to->next;
			to->key = from->key;

			from = from->next;
		}

		to->next = nullptr;
	}

	return;
}

const LinkedList& LinkedList::operator=(const LinkedList& otherLinkedList) {
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr)
		head = nullptr;

	else {
		from = otherLinkedList.head;
		head = new LLNode;
		head->key = from->key;

		to = head;
		from = from->next;

		while (from != nullptr) {
			to->next = new LLNode;
			to = to->next;
			to->key = from->key;

			from = from->next;
		}

		to->next = nullptr;
	}

	return *this;

}

void LinkedList::Insert(int data) {
//Narrative: Inserts a node into the linked list at the head
//	Pre - condition : data has a value and list initialized
//	Post - condition : a node with key = data inserted into list, length updated

	NodePtr temp = new LLNode;
	temp->key = data;
	temp->next = nullptr;
	length++;

	if (!head) {
		head = temp;
		return;
	}

	temp->next = head;
	head = temp;
	return;

}


void LinkedList::InsertSorted(int data) {
//Narrative: Same as Insert but inserts into sorted location in list
//	Pre - condition : same as Insert
//	Post - condition : Same as Insert

	NodePtr temp = new LLNode;
	NodePtr current;

	temp->key = data;
	temp->next = nullptr;
	length++;

	if (!head || head->key >= temp->key) {
		temp->next = head;
		head = temp;
	}

	else {
		current = head;
		while (current->next != nullptr && current->next->key < temp->key)
			current = current->next;

		temp->next = current->next;
		current->next = temp;
	}

	return;
}

bool LinkedList::Search(int key) {
//Narrative: Searches for a node with value of key
//	Pre - condition : list initialized
//	Post - condition : returns true if key found in list else return false

	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->key != key) {
		currPtr = currPtr->next;
	}

	return (currPtr);
}

int LinkedList::NumCompares(int key) {
//Narrative: Searches for an item in the  list with value key and keeps track of the number of compares and returns that value
//	Pre - condition : list initalized
//	Post - condition : number of comparisons returned

	NodePtr currPtr = head;
	int numCompares = 0;

	while (currPtr != nullptr && currPtr->key != key) {
		numCompares++;
		currPtr = currPtr->next;
	}

	return numCompares;
}

int LinkedList::NumComparesSorted(int key) {
//Narrative: Searches for an item in the sorted list with value key and keeps track of the number of compares and returns that value
//	Pre - condition : list initalized
//	Post - condition : number of comparisons returned

	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->key < key) {
		currPtr = currPtr->next;
		numCompares++;
	}

	return numCompares;
}

void LinkedList::PrintList() {
//Narrative: Prints the contents of the list
//	Pre - condition : list initialized
//	Post - condition : values of each node printed to screen

	NodePtr currPtr = head;

	while (currPtr != nullptr) {
		std::cout << currPtr->key << " ";
		currPtr = currPtr->next;
		
	}

	return;
}