#include<iostream>
#include<random>
#include<time.h>
#include <vld.h>
#include"BST.h"

using namespace std;

void shuffle(int values[], int size);
void CreateListRandomInts();
void TestInsert();

int main()

{
	TestInsert();

	
	


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


void CreateListRandomInts() {
	int min, max;

	// Prompt user for two integer values to specify a range.

	cout << "Enter minimum integer value of number range: ";
	cin >> min;
	cout << "Enter maximum integer value of number range: ";
	cin >> max;

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
	for (int i = 0; i <= range; i++) {
		cout << "Next random value: " << values[i] << endl;
		cout << "i: " << i << endl;
	}
}

void TestInsert() {
	BST Test;
	int temp[7];

	temp[0] = 50;
	temp[1] = 30;
	temp[2] = 20;
	temp[3] = 40;
	temp[4] = 70;
	temp[5] = 60;
	temp[6] = 80;


	for (int i = 0; i < 7; i++)
		Test.Insert(temp[i]);

	Test.InorderTraverse(Test.ReturnRoot());

	return;
}