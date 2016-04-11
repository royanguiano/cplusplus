#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector< vector<int> > matrix;

	for (int row = 0; row < 10; row++) {
		matrix.push_back(vector<int>());
		
		for (int col = 0; col < 10; col++) {
			matrix[row].push_back(row * col);
		}
	}

	cout << setw(5);
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[0].size(); col++) {
			cout << matrix[row][col] << setw(5);
		}
		cout << endl;
	}

	return 0;
}

