#include<iostream>
#include<random>
#include<time.h>
#include <vld.h>
#include"BST.h"
#include"HashTable.h"

using namespace std;

void shuffle(int values[], int size);
void CreateListRandomInts(int arrRandomNums[]);
BST CreateTree(int length, int arrRandomNums[]);
void BSTTrial(BST tree);

HashTable CreateHashTable(int length, int temp[]);
HashTable CreateSortedHashTable(int length, int temp[]);
void HashTableTrial(HashTable table);
void SortedHashTableTrial(HashTable table);

//BinarySearchTreeTests
void TestInsert(int temp[]);
void CreateTestArray(int temp[]);
void testPass(BST test);
void testSearch(BST test);
void testSuccPre(BST test);

BST CreateTestBST(int temp[]);

//Hash Table Tests
void HTestInsert(int temp[]);
void HTestPass(HashTable test);
void HtestSearch(HashTable test);


int main(){
	
	/*This block is for testing purposes only*/
	
	int testValues[7];
	CreateTestArray(testValues);


	//Binary Search Tree
	
	
	TestInsert(testValues);
	

	//Testing = operator
	cout << "T=:" << endl;
	BST test = CreateTestBST(testValues);
	test.InorderTraverse(test.ReturnRoot());
	cout << endl << endl;

	//Testing passing through function
	cout << "Tpass:" << endl;
	testPass(test);
	test.InorderTraverse(test.ReturnRoot());
	cout << endl << endl;

	//Testing Search
	testSearch(test);

	//Testing Predecessor and Successor
	testSuccPre(test);
											
											  
	//Hash Table
	HTestInsert(testValues);
	
	//Testing = and passing
	cout << "TH=:" << endl;
	HashTable Htest = CreateHashTable(7,testValues);
	Htest.PrintTable();
	cout << endl << endl;
	
	cout << "THpass:" << endl;
	HTestPass(Htest);
	Htest.PrintTable();
	cout << endl << endl;

	HtestSearch(Htest);

												 


	/*                      Trials              */
	

	int arrRandomNums[250];
	CreateListRandomInts(arrRandomNums);

	
	//BST Trials
	BST fifty = CreateTree(50, arrRandomNums);
	BST onefifty = CreateTree(150, arrRandomNums);
	BST twofifty = CreateTree(250, arrRandomNums);

	BSTTrial(fifty);
	BSTTrial(onefifty);
	BSTTrial(twofifty);
	
	

	//Hash Table Trials
	HashTable hfifty = CreateHashTable(50, arrRandomNums);
	HashTable honefifty = CreateHashTable(150, arrRandomNums);
	HashTable htwofifty = CreateHashTable(250, arrRandomNums);

	HashTableTrial(hfifty);
	HashTableTrial(honefifty);
	HashTableTrial(htwofifty);

	//Sorted Hash Table Trials
	HashTable hsfifty = CreateSortedHashTable(50, arrRandomNums);
	HashTable hsonefifty = CreateSortedHashTable(150, arrRandomNums);
	HashTable hstwofifty = CreateSortedHashTable(250, arrRandomNums);

	SortedHashTableTrial(hsfifty);
	SortedHashTableTrial(hsonefifty);
	SortedHashTableTrial(hstwofifty);

												
	system("pause");
	return 0;

}


void shuffle(int values[], int size) {
//Narrative: Shuffles around the values in the array values
//	Pre - condition : values has been filled
//	Post - condition : values will be an unsorted randomized array of values



	// Seed our random number generator.

	srand(1);


	// Create large number of swaps
	// This example takes the size and times it by 20 for the number of swaps

	for (int i = 0; i < (size * 20); i++) {

		// Generate random values for subscripts, not values!

		int randvalue1 = (rand() % size) + 0;

		int randvalue2 = (rand() % size) + 0;


		int temp = values[randvalue1];

		values[randvalue1] = values[randvalue2];

		values[randvalue2] = temp;

	}

}


void CreateListRandomInts(int arrRandomNums[]) {
//Narrative: This function creates a list of
//	Pre - condition : array is created that can hold 250 integers
//	Post - condition : 250 random unique integers with values between 100 and 500 will be created and placed in the array.


	int min = 100;
	int	max = 500;


	// If the values for the range was reversed, swap them.
	if (max < min) {
		int temp = min;
		min = max;
		max = temp;
	}

	int range = (max - min);

	// Create our new array of size "range"
	int *values = new int[range];


	// Load some counting values into our array
	for (int i = 0; i <= range; i++) {
		values[i] = min + i;
	}


	// Now shuffle the array values randomly.
	shuffle(values, range + 1);

	// Spit out the values

	for (int i = 0; i < 250; i++) {
		arrRandomNums[i] = values[i];
	}

	return;
}

void CreateTestArray(int temp[]) {
	temp[0] = 50;
	temp[1] = 30;
	temp[2] = 20;
	temp[3] = 40;
	temp[4] = 70;
	temp[5] = 60;
	temp[6] = 80;
}

BST CreateTestBST(int temp[]) {
	/*              Creating Tree		                */
	/*					  50					        */
	/*			   	   /      \					        */
	/*			     30		   70				        */
	/*			    /  \	   /  \				        */
	/*		       20	40	  60	80			        */
	/*												    */

	BST tempBST;
	for (int i = 0; i < 7; i++)
		tempBST.Insert(temp[i]);

	return tempBST;
}

void TestInsert(int temp[]) {

	BST testInsert;

	//Insert a 1 into an empty tree
	cout << "BTI 1:" << endl;
	testInsert.Insert(1);
	testInsert.InorderTraverse(testInsert.ReturnRoot());
	cout << endl << endl;


	//Inserting multiple items into the tree
	cout << "BTI 2:" << endl;
	for (int i = 0; i < 7; i++)
		testInsert.Insert(temp[i]);

	testInsert.InorderTraverse(testInsert.ReturnRoot());
	cout << endl << endl;

	return;
}

void testPass(BST test) {
	return;
}

void testSearch(BST test) {
	cout << "BS1" << endl;
	if (test.Search(test.ReturnRoot(), 20))
		cout << "20 Was found " << endl << endl;
	else
		cout << "20 Was not found" << endl << endl;

	cout << "BS2" << endl;
	if (test.Search(test.ReturnRoot(), 0))
		cout << "0 Was found " << endl << endl;
	else
		cout << "0 Was not found" << endl << endl;
	
	return;
}

void testSuccPre(BST test) {
	cout << "BPRE1: " << endl;
	cout << test.ValueofNode(test.FindPredecessor(20));
	cout << endl << endl;

	cout << "BPRE2: " << endl;
	cout << test.ValueofNode(test.FindPredecessor(50));
	cout << endl << endl;
	
	cout << "BPRE3: " << endl;
	cout << test.ValueofNode(test.FindPredecessor(80));
	cout << endl << endl;

	
	
	cout << "BPOST1: " << endl;
	cout << test.ValueofNode(test.FindSucessor(20));
	cout << endl << endl;

	cout << "BPOST2: " << endl;
	cout << test.ValueofNode(test.FindSucessor(50));
	cout << endl << endl;

	cout << "BPOST3: " << endl;
	cout << test.ValueofNode(test.FindSucessor(80));
	cout << endl << endl;

	return;

}

void HTestInsert(int temp[]) {
	HashTable test;
	HashTable testSorted;

	//Insert a 1 into empty tree
	cout << "HTI 1" << endl;
	test.Insert(1);
	test.PrintTable();
	cout << endl << endl;


	//Inserting multiple items into tree
	cout << "HTI 2" << endl;
	for (int i = 0; i < 7; i++) {
		test.Insert(temp[i]);
	}
	test.PrintTable();
	cout << endl << endl;

	cout << "HTI 3" << endl;
	for (int i = 0; i < 7; i++) {
		testSorted.InsertSorted(temp[i]);
	}
	testSorted.PrintTable();
	cout << endl << endl;

}


HashTable CreateHashTable(int length, int temp[]) {
//Narrative: This will fill a hash table with values in randArray
//	Pre - condition : The length of randArray has been determined and randArray has been filled with values.
//	Post - condition : a Hash Table is returned containing all values in randArray[]

	HashTable temphash;

	for (int i = 0; i < length; i++) {
		temphash.Insert(temp[i]);
	}

	return temphash;
}

HashTable CreateSortedHashTable(int length, int temp[]) {

//Narrative: This will fill a hash table with sorted buckets using values in randArray
//	Pre - condition : The length of randArray has been determined and randArray has been filled with values.
//	Post - condition : a Sorted Hash Table is returned containing all values in randArray[]



	HashTable temphash;

	for (int i = 0; i < length; i++) {
		temphash.InsertSorted(temp[i]);
	}

	return temphash;
}

void HTestPass(HashTable test) {
	return;
}

void HtestSearch(HashTable test) {
	cout << "HS1" << endl;
	if (test.Search(20))
		cout << "20 Was found " << endl << endl;
	else
		cout << "20 Was not found" << endl << endl;

	cout << "HS2" << endl;
	if (test.Search(0))
		cout << "0 Was found " << endl << endl;
	else
		cout << "0 Was not found" << endl << endl;

	return;
}


BST CreateTree(int length, int arrRandomNums[]) {
//Narrative: This will fill a binary search tree with the values in randArray.
//	Pre - condition : The length of randArray has been determined and randArray has been filled with values.
//	Post - condition : a BST is returned containing all values in randArray[]


	BST temp;
	
	for (int i = 0; i < length; i++) {
		temp.Insert(arrRandomNums[i]);
	}
	
	return temp;
}


void BSTTrial(BST tree) {
//Narrative: This runs a trial on the binary tree that is passed into the function.
//	The trial includes outputting the size of the BST and the average number of probes
//	it takes to find a value between 100 and 500
//
//	Pre - condition : tree is a filled binary search tree
//	Post - condition : Binary search tree trial requirements(List size and Average number of probes) will be output to the screen.



	int numCompares[400];

	for (int i = 0; i < 400; i++) {
		int temp = 0;
		tree.NumComparisons(tree.ReturnRoot(), i + 100, temp);
		numCompares[i] = temp;
		//cout << numCompares[i] << endl;
	}


	cout << endl << endl;
	cout << "Binary Search Tree implementation" << endl;
	cout << "List Size : " << tree.ReturnLength() << endl ;
	int averageNumProbes = 0;
	for (int i = 0; i < 400; i++) {
		averageNumProbes += numCompares[i];
	}
	averageNumProbes = averageNumProbes / 400;
	cout << "Average number of probes : " << averageNumProbes << endl << endl;

	return;
}


void HashTableTrial(HashTable table) {
//	Narrative:	This runs a trial on the HashTable that is passed into the function.
//				The trial includes outputting the size of the HashTable and the average number
//				of probes it takes to find a value between 100 and 500
//	Pre - condition : table is a filled hash table
//	Post - condition : Hash Table trial requirements(List size and Average number of probes) will be output to the screen.

	int numCompares[400];

	for (int i = 0; i < 400; i++) {
		numCompares[i] = table.numCompares(i + 100);
		//cout << numCompares[i] << endl;
	}
	//table.PrintTable();

	cout << endl << endl;
	cout << "Unsorted Hash Table Implementation" << endl;
	cout << "List Size : " << table.ReturnLength() << endl;
	int averageNumProbes = 0;
	for (int i = 0; i < 400; i++) {
		averageNumProbes += numCompares[i];
	}
	averageNumProbes = averageNumProbes / 400;
	cout << "Average number of probes : " << averageNumProbes << endl << endl;

	return;
}


void SortedHashTableTrial(HashTable table) {
	//Narrative: This runs a trial on the sorted HashTable that is passed into the function.
//			 The trial includes outputting the size of the sorted HashTable and the average
//			 number of probes it takes to find a value between 100 and 500
//	Pre - condition : table is a filled sorted hash table
//	Post - condition : Sorted Hash Table trial requirements(List size and Average number of probes) will be output to the screen.


	int numCompares[400];

	for (int i = 0; i < 400; i++) {
		numCompares[i] = table.numComparesSorted(i + 100);
		//cout << numCompares[i] << endl;
	}
	//table.PrintTable();

	cout << endl << endl;
	cout << "Sorted Hash Table Implementation" << endl;
	cout << "List Size : " << table.ReturnLength() << endl;
	int averageNumProbes = 0;
	for (int i = 0; i < 400; i++) {
		averageNumProbes += numCompares[i];
	}
	averageNumProbes = averageNumProbes / 400;
	cout << "Average number of probes : " << averageNumProbes << endl << endl;

	return;
}