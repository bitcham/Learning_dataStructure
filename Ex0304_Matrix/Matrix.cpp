#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	num_rows_ = num_rows;
	num_cols_ = num_cols;
	values_ = new float[num_rows * num_cols];

	for (int i = 0; i < num_rows * num_cols; i++)
		values_[i] = 0.0f;

}

Matrix::Matrix(const Matrix& b)
{
	this->num_rows_ = b.num_rows_;
	this->num_cols_ = b.num_cols_;
	values_ = new float[b.num_rows_ * b.num_cols_];

	for (int i = 0; i < num_rows_ * num_cols_; i++)
		values_[i] = b.values_[i];
}

Matrix::~Matrix()
{
	if (values_) delete[] values_;
}

void Matrix::SetValue(int row, int col, float value)
{
	values_[row * num_cols_ + col] = value;
}

float Matrix::GetValue(int row, int col) const 
{
	return values_[row * num_cols_ + col];
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); 

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(c, r, GetValue(r, c));

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);
	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));
	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
