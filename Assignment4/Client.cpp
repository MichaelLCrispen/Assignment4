#include<iostream>
#include<random>
#include<time.h>
#include <vld.h>
#include"BST.h"

using namespace std;

void shuffle(int values[], int size);
void CreateListRandomInts(int arrRandomNums[]);
BST CreateTree(int length, int arrRandomNums[]);
void BSTTrial(BST tree);

void TestInsert(int temp[]);
void CreateTestArray(int temp[]);
BST CreateTestBST(int temp[]);
void testPass(BST test);
void testSearch(BST test);
void testSuccPre(BST test);

int main(){
	
	/*This block is for testing purposes only

	int testValues[7];
	CreateTestArray(testValues);
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


	*/
	int arrRandomNums[250];
	CreateListRandomInts(arrRandomNums);

	BST fifty = CreateTree(50, arrRandomNums);
	BST onefifty = CreateTree(150, arrRandomNums);
	BST twofifty = CreateTree(250, arrRandomNums);

	BSTTrial(fifty);
	BSTTrial(onefifty);
	BSTTrial(twofifty);


	system("pause");
	return 0;

}


void shuffle(int values[], int size) {

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
	cout << "TI 1:" << endl;
	testInsert.Insert(1);
	testInsert.InorderTraverse(testInsert.ReturnRoot());
	cout << endl << endl;


	//Inserting multiple items into the tree
	cout << "TI 2:" << endl;
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
	cout << "S1" << endl;
	if (test.Search(test.ReturnRoot(), 20))
		cout << "Was found " << endl << endl;
	else
		cout << "Was not found" << endl << endl;

	cout << "S2" << endl;
	if (test.Search(test.ReturnRoot(), 0))
		cout << "Was found " << endl << endl;
	else
		cout << "Was not found" << endl << endl;
	
	return;
}

void testSuccPre(BST test) {
	cout << "PRE1: " << endl;
	cout << test.ValueofNode(test.FindPredecessor(20));
	cout << endl << endl;

	cout << "PRE2: " << endl;
	cout << test.ValueofNode(test.FindPredecessor(50));
	cout << endl << endl;

	
	
	cout << "POST1: " << endl;
	cout << test.ValueofNode(test.FindSucessor(20));
	cout << endl << endl;

	cout << "POST2: " << endl;
	cout << test.ValueofNode(test.FindSucessor(50));
	cout << endl << endl;

	return;

}


BST CreateTree(int length, int arrRandomNums[]) {
	BST temp;
	
	for (int i = 0; i < length; i++) {
		temp.Insert(arrRandomNums[i]);
	}
	
	return temp;
}


void BSTTrial(BST tree) {
	int numCompares[400];

	for (int i = 0; i < 400; i++) {
		int temp = 0;
		tree.NumComparisons(tree.ReturnRoot(), i + 100, temp);
		numCompares[i] = temp;
		cout << numCompares[i] << endl;
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