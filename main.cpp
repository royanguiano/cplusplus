//Roy Anguiano
//class: csc 340
//assigment: hw1 problem 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void selectionSort (vector<int>& nums, int size){
	int i, j;
	int min;

	for (i = 0; i < size - 1; i++ ) {
		min = i;
		for ( j = i + 1; j < size; j++ ) {
			if ( nums[j] < nums[min] ) {
				min = j;
			}
		}
		if ( min != i ) {
			swap (nums[i], nums[min]);
		}
	}
	cout << "Her is the List: ";
	for ( int m = 0; m < size; m++ )
		cout << nums[m] << " ";
}

int main () {
	
	cout << "How many numbers:  ";
	int numSize;
	cin >> numSize;

	vector <int> numbers (numSize);

	cout << "Enter numbers: ";
	for ( int y = 0; y < numSize; y++ )
		cin >> numbers[y];

	int size = numbers.size ();
	selectionSort (numbers, size);

	return 0;
}