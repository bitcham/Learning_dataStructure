#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols)
{
	arrays_ = new float* [num_rows];

	for (int r = 0; r < num_rows; r++)
	{
		arrays_[r] = new float[num_cols]; 
	}

	for (int r = 0; r < num_rows; r++)
		for (int c = 0; c < num_cols;c++)
			arrays_[r][c] = 0.0f;

	this->num_cols_ = num_cols;
	this->num_rows_ = num_rows;
}




Array2D::Array2D(const Array2D& b)
{
	num_cols_ = b.num_cols_;
	num_rows_ = b.num_rows_;
	arrays_ = new float* [num_rows_];

	for (int r = 0; r < num_rows_; r++)
	{
		arrays_[r] = new float(num_cols_); 
	}

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			arrays_[r][c] = b.arrays_[r][c];
}

Array2D::~Array2D()
{
	if (arrays_)
	{
		for (int r = 0; r < num_rows_; r++)
			delete[] arrays_[r];

		delete[] arrays_;
	}
}

void Array2D::SetValue(int row, int col, float value)
{
	arrays_[row][col] = value;
}

float Array2D::GetValue(int row, int col) const
{
	return arrays_[row][col];
}

Array2D Array2D::Transpose()
{
	Array2D temp(num_cols_, num_rows_); 

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(c, r, GetValue(r, c));

	return temp;
}

Array2D Array2D::Add(const Array2D& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Array2D temp(num_rows_, num_cols_);

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

	return temp;
}

void Array2D::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
