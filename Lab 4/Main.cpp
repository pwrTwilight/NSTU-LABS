#include "Matrix.h"
#include "TriangleMatrix.h"
int main() {
	srand(time(NULL));
	int n;

	cout << "Enter size matrix N x N: " << endl;
	cin >> n;

	cout << "Identity matrix: " << endl;
	IdentityMatrix Matrix(n);
	cout << Matrix;

	cout << "Triangle Matrix represented in one-dimensional array: " << endl;
	TriangleMatrix Matrix1(n);
	cout << Matrix1;

	cout << "Triangle Matrix: " << endl;
	DynamicMatrix TMatrix = Matrix1;
	cout << TMatrix;

	return 0;
}