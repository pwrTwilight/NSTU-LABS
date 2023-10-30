#pragma once

#include "IdentityMatrix.h"
IdentityMatrix::IdentityMatrix(int size) : DynamicMatrix(size, size) {
	int count = size;

	arr = new int* [size];

	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (count == size) {
				arr[i][j] = 1;
				count = 0;
			}
			else {
				arr[i][j] = 0;
				count++;
			}
		}
	}
}