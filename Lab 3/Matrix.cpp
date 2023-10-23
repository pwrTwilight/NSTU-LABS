#include "Matrix.h"

int DynamicMatrix::CountObjects = 0;


DynamicMatrix::DynamicMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
	CountObjects++;
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
	CountObjects++;
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

DynamicMatrix::DynamicMatrix() : DynamicMatrix(0, 0) {}

DynamicMatrix::~DynamicMatrix() {

	for (int i = 0; i < rows_; i++) {
		delete[] arr[i];
	}

	delete[] arr;
	CountObjects--;
}

int DynamicMatrix::GetElement(int Rows, int Rols) {
		return arr[Rows][Rols];
}
int DynamicMatrix::GetRows() {
	return rows_;
}

int DynamicMatrix::GetCols() {
	return cols_;
}

int DynamicMatrix::getCountObject() {
	return CountObjects;
}

char* DynamicMatrix::ToString() {
	char* string = new char[rows_ * cols_ * 4];

	int index = 0;
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			int length = snprintf(string + index, (rows_ * cols_ * 4) - index, "%d ", arr[i][j]);
			index += length;
		}
		string[index++] = '\n';
	}
	string[index] = '\0';

	return string;
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

int DynamicMatrix::ReplaceElement(int x, int y, int Number) {
	if (x >= 0 && y >= 0) {
		return arr[x][y] = Number;
	}
	else {
		return -1;
	}
}

DynamicMatrix DynamicMatrix::Sum(const DynamicMatrix& other) {
	if (rows_ == other.rows_ && cols_ == other.cols_) {
		DynamicMatrix result(rows_, cols_);

		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				result[i][j] = arr[i][j] + other.arr[i][j];
			}
		}

		return result;
	}
}

DynamicMatrix DynamicMatrix::Sub(const DynamicMatrix& other) {
	if (rows_ == other.rows_ && cols_ == other.cols_) {
		DynamicMatrix result(rows_, cols_);

		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				result[i][j] = arr[i][j] - other.arr[i][j];
			}
		}

		return result;
	}
	else {
		std::stringstream stream;
		stream << "Matrix have different size :";
		throw std::invalid_argument(stream.str().c_str());
	}
}

int* DynamicMatrix::operator [] (int index) {
	return arr[index];
}

DynamicMatrix& DynamicMatrix::operator = (const DynamicMatrix& other) {
	if (&other != this) {
		for (int i = 0; i < rows_; i++) {
			delete[] arr[i];
		}

		delete[] arr;

		rows_ = other.rows_;
		cols_ = other.cols_;


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

	return *this;
}

void DynamicMatrix::operator () (int x, int y, int Number) {
	ReplaceElement(x, y, Number);
}

DynamicMatrix operator + (const DynamicMatrix& FirstMatrix, const DynamicMatrix& SecondMatrix) {
	DynamicMatrix Matrix(FirstMatrix);

	return Matrix.Sum(SecondMatrix);

}

DynamicMatrix operator - (const DynamicMatrix& FirstMatrix, const DynamicMatrix& SecondMatrix) {
	DynamicMatrix Matrix(FirstMatrix);

	return Matrix.Sub(SecondMatrix);

}

ostream& operator << (ostream& out, DynamicMatrix& matrix) {

	out << matrix.rows_ << " " << matrix.cols_ << endl;

	for (int i = 0; i < matrix.rows_; i++) {
		for (int j = 0; j < matrix.cols_; j++) {
			out << matrix.arr[i][j] << " ";
		}
		out << endl;
	}

	return out;
}

istream& operator >> (istream& in, DynamicMatrix& matrix) {

	in >> matrix.rows_ >> matrix.cols_;
	matrix.arr = new int* [matrix.rows_];
	for (int i = 0; i < matrix.rows_; ++i) {
		matrix.arr[i] = new int[matrix.cols_];
	}

	for (int i = 0; i < matrix.rows_; i++) {
		for (int j = 0; j < matrix.cols_; j++) {
			in >> matrix.arr[i][j];
		}
	}

	return in;
}

void DynamicMatrix::WriteToBinary(ofstream& file) {

	file.open("Matrix.bin", ios::binary);

	if (!file.is_open()) {

		std::stringstream stream;
		stream << "Failed to open the file!";
		throw std::invalid_argument(stream.str().c_str());
	}
	else {
		file.write(reinterpret_cast<char*>(&rows_), sizeof(int));
		file.write(reinterpret_cast<char*>(&cols_), sizeof(int));
		for (int i = 0; i < rows_; i++) {

				file.write(reinterpret_cast<char*> (arr[i]), cols_ * sizeof(int));
		}
	}

	file.close();

	


}

void DynamicMatrix::ReadFromBinary(ifstream& file) {

	file.open("Matrix.bin", ios::binary);

	if (!file.is_open()) {
		std::stringstream stream;
		stream << "Failed to open the file!";
		throw std::invalid_argument(stream.str().c_str());
	}
	else {
		file.read(reinterpret_cast<char*>(&rows_), sizeof(int));
		file.read(reinterpret_cast<char*>(&cols_), sizeof(int));

		arr = new int* [rows_];
		for (int i = 0; i < rows_; ++i) {
			arr[i] = new int[cols_];
		}
		for (int i = 0; i < rows_; i++) {
			file.read(reinterpret_cast<char*> (arr[i]), cols_ * sizeof(int));
		}

	}

	file.close();

}


/*MyArray* loadFromBinaryFile(const char* filename) {
	try {
		std::ifstream ifstream(filename, std::ios::binary);
		int countArrays;
		ifstream.read((char*)(&countArrays), sizeof(countArrays));

		MyArray* loadedArrays = new MyArray[countArrays];

		for (int i = 0; i < countArrays; i++) {
			int size, maxSize, currentIndex;
			ifstream.read((char*)(&size), sizeof(size));
			ifstream.read((char*)(&maxSize), sizeof(maxSize));
			ifstream.read((char*)(&currentIndex), sizeof(currentIndex));

			MyArray loadedArray(maxSize);
			loadedArray.setSize(size);
			loadedArray.setCurrentIndex(currentIndex);
			ifstream.read((char*)(loadedArray.getArray()), sizeof(int) * size);
			loadedArrays[i] = loadedArray;
		}

		ifstream.close();
		return loadedArrays;
	}
	catch (std::exception& e) {
		std::cout << "NullPointerException reading from binary file" << e.what() << std::endl;
		return nullptr;
}*/