#pragma once

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
	void ReplaseElement(int x, int y, int Number);


	int GetRows();
	int GetCols();
	int GetElement(int rows, int cols);

	char* ToString();

private:
	const int rows_;
	const int cols_;
	int** arr;
};
