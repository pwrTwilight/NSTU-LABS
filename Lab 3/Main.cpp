#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

int main() {
	srand(time(NULL));
	DynamicMatrix Matrix1(6, 6);	DynamicMatrix Matrix3(5, 5);
	DynamicMatrix Matrix2;		DynamicMatrix Matrix4;

	ofstream fout;	ofstream write;
	ifstream fin;	ifstream read;

	string path = "Matrix.txt";

	cout << "Create and write to .txt file" << endl;

	fout.open(path, ios::out);
	if (!fout.is_open()) {
		cout << "File error!" << endl;
		return 1;
	}
	else {
		fout << Matrix1;
	}
	fout.close();

	cout << endl << "Read .txt file" << endl;
	fin.open(path, ios::in);
	if (!fin.is_open()) {
		cout << "File error!" << endl;
		return 1;
	}
	else {
		fin >> Matrix2;
	}
	fin.close();

	cout << Matrix2;

	cout << "Create and write to .bin file" << endl;
	Matrix3.WriteToBinary(write);

	cout << endl << "Read .bin file" << endl;
	Matrix4.ReadFromBinary(read);
	cout << Matrix4;
	

	return 0;
}