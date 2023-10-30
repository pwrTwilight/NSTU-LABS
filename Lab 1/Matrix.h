#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class DynamicMatrix
{
public:
	DynamicMatrix();
	DynamicMatrix(int rows, int cols);
	DynamicMatrix(const DynamicMatrix& other);
	~DynamicMatrix();

	void SortArrayX(int k);
	void SortArrayY(int k);
	int** FindElement(int x);
	int ReplaceElement(int x, int y, int Number);


	static int getCountObject();
	int GetRows();
	int GetCols();
	int GetElement(int rows, int cols);

	char* ToString();

private:
	static int CountObjects;
	int rows_;
	int cols_;
	int** arr;
};
