#include "Matrix.h"

int main() {

	DynamicMatrix MatrixSource(3, 3);
	cout << "MatrixSource: " << endl << MatrixSource.ToString() << endl;
	MatrixSource(1, 1, 222);
	cout << "MatrixSource with replaced element:  " << endl << MatrixSource.ToString() << endl;
	cout << "Element [1][1] in MatrixSource: " << MatrixSource[1][1] << endl << endl;
	DynamicMatrix MatrixOne(2, 2);
	cout << "MatrixOne: " << endl << MatrixOne.ToString() << endl;
	DynamicMatrix MatrixSecond(2, 2);
	cout << "MatrixSecond: " << endl << MatrixSecond.ToString() << endl;
	DynamicMatrix MatrixThree = MatrixOne + MatrixSecond;
	cout << "MatrixThree with operator sum: " << endl << MatrixThree.ToString() << endl;
	DynamicMatrix MatrixFour = MatrixOne - MatrixSecond;
	cout << "MatrixFour with operator sub: " << endl << MatrixFour.ToString() << endl;

	MatrixOne = MatrixSecond;
	cout << "MatrixOne = MatrixSecond: " << endl << MatrixOne.ToString() << endl;
	


	cout << "Constructor was called : " << DynamicMatrix::getCountObject() << endl;

	return 0;
}
