#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>


using namespace std;

class DynamicMatrix
{
public:
	DynamicMatrix();
	DynamicMatrix(int rows, int cols);
	DynamicMatrix(const DynamicMatrix& other);
	~DynamicMatrix();

	void WriteToBinary(ofstream& file);
	void ReadFromBinary(ifstream& file);
	void SortArrayX(int k);
	void SortArrayY(int k);
	int** FindElement(int x);
	int ReplaceElement(int x, int y, int Number);


	DynamicMatrix Sum(const DynamicMatrix& other);
	DynamicMatrix Sub(const DynamicMatrix& other);

	void operator () (int x, int y, int Number);
	DynamicMatrix& operator = (const DynamicMatrix& other);
	int* operator [] (int index);



	static int getCountObject();
	int GetRows();
	int GetCols();
	int GetElement(int rows, int cols);
	char* ToString();

	int** arr;

private:
	static int CountObjects;
	int rows_;
	int cols_;

	friend DynamicMatrix operator + (const DynamicMatrix& FirstMatrix, const DynamicMatrix& SecondMatrix);
	friend DynamicMatrix operator - (const DynamicMatrix& FirstMatrix, const DynamicMatrix& SecondMatrix);
	friend ostream& operator << (ostream& out, DynamicMatrix& matrix);
	friend istream& operator >> (istream& in, DynamicMatrix& matrix);
};
