#include "TriangleMatrix.h"


TriangleMatrix::TriangleMatrix(int size) : IdentityMatrix(size), size_(size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i <= j) {
				arr[i][j] = rand() % 9 + 1;
			}
			else {
				arr[i][j] = 0;
			}
		}
	}
}

int* TriangleMatrix::WriteToMassive(int size) {
	int* result = new int[sizeof(int) * size * size];
	int h = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] != 0) {
				result[h] = arr[i][j];
				h++;
			}
		}
	}
	result[h] = 0;
	return result;
}

ostream& operator << (ostream& out, TriangleMatrix& matrix) {
	
	for (int i = 0; i < matrix.size_; i++) {
		for (int j = 0; j < matrix.size_; j++) {
			if (matrix.arr[i][j] != 0) {
				out << matrix.arr[i][j] << ' ';
			}
		}
	}
	out << endl;
	return out;
}