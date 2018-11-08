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
	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->key != key) {
		currPtr = currPtr->next;
	}

	return (currPtr);
}

int LinkedList::NumCompares(int key) {
	NodePtr currPtr = head;
	int numCompares = 0;

	while (currPtr != nullptr && currPtr->key != key) {
		numCompares++;
		currPtr = currPtr->next;
	}

	return numCompares;
}

int LinkedList::NumComparesSorted(int key) {
	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->key < key) {
		currPtr = currPtr->next;
		numCompares++;
	}

	return numCompares;
}

void LinkedList::PrintList() {
	NodePtr currPtr = head;

	while (currPtr != nullptr) {
		std::cout << currPtr->key << " ";
		currPtr = currPtr->next;
		
	}

	return;
}