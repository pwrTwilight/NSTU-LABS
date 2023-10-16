#include <iostream>

#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int** find;
	int x, y, FirstNumber, SecondNumber, rows, cols;
	cout << "Enter rows and cols: ";
	cin >> rows >> cols;
	DynamicMatrix Matrix(rows, cols);
	cout << "Your Matrix: " << endl;
	cout << Matrix.ToString() << endl;

	cout << "Sorted Matrix Rows: " << endl;
	for (int i = 0; i < rows; i++) {
		Matrix.SortArrayX(i);
	}
	cout << Matrix.ToString() << endl;


	cout << "Sorted Matrix Cols: " << endl;
	for (int i = 0; i < cols; i++) {
		Matrix.SortArrayY(i);
	}
	cout << Matrix.ToString() << endl;


	cout << "Enter an integer to find: ";
	cin >> FirstNumber;		
	cout << endl;
	
	find = Matrix.FindElement(FirstNumber);

	cout << "Found Indexes: " << endl;
	for (int i = 0; i < (rows * cols * 2 - 1); i++) {
			if (find[i][0] >= 0 && find[i][1] >= 0) {
				cout << "[" << find[i][0] << "] " << "[" << find[i][1] << "] " << endl;
			}
	}
	cout << endl;

	cout << "Select element to replace(x, y, number): ";
	cin >> x >> y >> SecondNumber;	cout << endl;
	
	Matrix.ReplaseElement(x, y, SecondNumber);

	cout << "Matrix after replace: " << endl;
	
	cout << Matrix.ToString() << endl;

	return 0;
}