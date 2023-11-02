#include "Matrix.h"

int main() {
	srand(time(NULL));

	DynamicMatrix Matrix1;		
	DynamicMatrix Matrix2;		
	DynamicMatrix Matrix3;
	DynamicMatrix Matrix4;
	DynamicMatrix Matrix5;
	DynamicMatrix Matrix6;
	DynamicMatrix Matrix7;
	DynamicMatrix Matrix8;

	cout << "############# TXT FILE #############" << endl;
	cout << endl;
	
	cout << "Matrix3: " << endl;
	cout << Matrix3;
	cout << "Matrix4: " << endl;
	cout << Matrix4;
	cout << endl;


	ofstream fout("Matrix.txt", ios::out);
	if (!fout.is_open()) {
		cout << "File error!" << endl;
		return 1;
	}
	else {
		cout << "Enter N x M and Elements in Matrix1: " << endl;
		cin >> Matrix1;
		cout << "Enter N x M and Elements in Matrix2: " << endl;
		cin >> Matrix2;
		fout << Matrix1;
		fout << Matrix2;
	}
	fout.close();

	ifstream fin("Matrix.txt", ios::in);
	if (!fin.is_open()) {
		cout << "File error!" << endl;
		return 1;
	}
	else {
		fin >> Matrix3;
		fin >> Matrix4;
	}
	fin.close();



	cout << "Matrix3: " << endl;
	cout << Matrix3;
	cout << "Matrix4: " << endl;
	cout << Matrix4;
	cout << endl;

	cout << "############# BIN FILE #############" << endl;
	cout << endl;

	cout << "Matrix7: " << endl;
	cout << Matrix7;
	cout << "Matrix8: " << endl;
	cout << Matrix8;
	cout << endl;

	cout << "Enter N x M and Elements in Matrix5: " << endl;
	cin >> Matrix5;
	cout << "Enter N x M and Elements in Matrix6: " << endl;
	cin >> Matrix6;

	ofstream out("Matrix.dat", ios::binary);
	Matrix5.WriteToBinary(out);
	Matrix6.WriteToBinary(out);
	out.close();

	ifstream in("Matrix.dat", ios::binary);
	Matrix7.ReadFromBinary(in);
	Matrix8.ReadFromBinary(in);
	in.close();

	cout << "Matrix7: " << endl;
	cout << Matrix7;
	cout << "Matrix8: " << endl;
	cout << Matrix8;
}
