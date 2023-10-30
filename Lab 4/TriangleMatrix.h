#pragma once
#include "IdentityMatrix.h"

class TriangleMatrix : public IdentityMatrix {
public:
	TriangleMatrix(int size);
	int* WriteToMassive(int size);
private:
	int size_;
	friend ostream& operator << (ostream& out, TriangleMatrix& matrix);
};

