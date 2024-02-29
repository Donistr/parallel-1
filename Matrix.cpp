#include <iostream>
#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t columns) {
	this->rows = rows;
	this->columns = columns;

	data = new int* [rows];

	for (size_t i = 0; i < rows; ++i) {
		data[i] = new int[columns];

		for (size_t j = 0; j < columns; ++j) {
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (size_t i = 0; i < rows; ++i) {
		delete[] data[i];
	}

	delete data;
}

void Matrix::fillMatrixRandomNumbers(int maxNumber) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			data[i][j] = rand() % maxNumber;
		}
	}
}

void Matrix::printMatrix() const {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			std::cout << data[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

Matrix& Matrix::multiply(const Matrix& matrix) const {
	if (columns != matrix.rows) {
		throw new std::invalid_argument("columns 1-st matrix != rows 2-nd matrix");
	}

	Matrix* res = new Matrix(rows, matrix.columns);

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < matrix.columns; ++j) {
			for (size_t z = 0; z < columns; ++z) {
				res->data[i][j] += data[i][z] * matrix.data[z][j];
			}
		}
	}

	return *res;
}

const int& Matrix::get(size_t row, size_t column) const {
	return data[row][column];
}

size_t Matrix::getRows() const {
	return rows;
}

size_t Matrix::getColumns() const {
	return columns;
}