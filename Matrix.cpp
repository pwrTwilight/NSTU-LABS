#include "Matrix.h"
#include <iostream>

DynamicMatrix::DynamicMatrix(int rows, int cols) : rows_(rows), cols_(cols) {

	arr = new int* [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 10;
		}
	}

}

DynamicMatrix::DynamicMatrix(const DynamicMatrix& other) : rows_(other.rows_), cols_(other.cols_) { 

	arr = new int* [rows_];

	for (int i = 0; i < rows_; i++) {
		arr[i] = new int[cols_];
	}


	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			arr[i][j] = other.arr[i][j];
		}
	}

}

DynamicMatrix::DynamicMatrix() : DynamicMatrix(3,3) {}	

DynamicMatrix::~DynamicMatrix() {							
	for (int i = 0; i < rows_; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}

char* DynamicMatrix::ToString() {
	char* string = new char[rows_ * cols_ * 12];

	int index = 0;
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			int length = snprintf(string + index, (rows_ * cols_ * 12) - index, "[%d] ", arr[i][j]);
			index += length;
		}
		string[index++] = '\n';
	}
	string[index] = '\0';

	return string;
}

int DynamicMatrix::GetElement(int Rows, int Rols) {
	if (Rows >= 0 && Rols >= 0) {
		return arr[Rows][Rols];
	}
	else {
		return -1;
	}
}
int DynamicMatrix::GetRows() {
	return rows_;
}

int DynamicMatrix::GetCols(){
	return cols_;
}

void DynamicMatrix::SortArrayX(int k) {

	int temp;

	for (int i = 0; i < cols_; ++i)
	{
		for (int j = 0; j < cols_ - 1; ++j)
		{
			if (arr[k][j] > arr[k][j + 1])
			{
				temp = arr[k][j];
				arr[k][j] = arr[k][j + 1];
				arr[k][j + 1] = temp;
			}
		}
	}
}

void DynamicMatrix::SortArrayY(int k) {

	int temp;
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < rows_ - 1; ++j)
		{
			if (arr[j][k] > arr[j + 1][k])
			{
				temp = arr[j][k];
				arr[j][k] = arr[j + 1][k];
				arr[j + 1][k] = temp;
			}
		}
	}
}

int** DynamicMatrix::FindElement(int x) {
	int** result = new int* [rows_ * cols_ * 2];
	int count = 0;
	for (int i = 0; i < (rows_ * cols_ * 2 - 1); i++) {
		result[i] = new int[2];
	}

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			if (arr[i][j] == x) {
				result[count][0] = i;
				result[count][1] = j;
				count++;
			}
		}
	}

	return result;
}

void DynamicMatrix::ReplaseElement(int x, int y, int Number) {
	arr[x][y] = Number;
}
