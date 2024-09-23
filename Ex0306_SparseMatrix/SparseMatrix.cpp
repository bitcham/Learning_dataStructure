#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	terms_ = new MatrixTerm[capacity];

	capacity_ = capacity;
	num_rows_ = num_rows;
	num_cols_ = num_cols;
}

SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	if (b.capacity_ > 0)
	{
		terms_ = new MatrixTerm[b.capacity_];

		capacity_ = b.capacity_;
		num_rows_ = b.num_rows_;
		num_cols_ = b.num_cols_;
		num_terms_ = b.num_terms_;

		memcpy(terms_, b.terms_, sizeof(MatrixTerm) * num_terms_);
	}

}

SparseMatrix::~SparseMatrix()
{
	if (terms_) delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; 
	
	int key = col + num_cols_ * row;
	int i = 0;
	for (; i < num_terms_; i++)
	{
		int key_i = terms_[i].col + num_cols_ * terms_[i].row;
		if (key_i == key)
		{
			terms_[i].row = row;
			terms_[i].col = col;
			terms_[i].value = value;
			return;
		}
		else if (key_i > key)
			break;
	}

	assert(capacity_ > num_terms_);
	num_terms_++;
	for (int j = num_terms_ - 1; j > i; j--)
		terms_[j] = terms_[j - 1];
	terms_[i].row = row;
	terms_[i].col = col;
	terms_[i].value = value;


}

float SparseMatrix::GetValue(int row, int col) const 
{
	int key = col + num_cols_ * row;
	for (int i = 0; i < num_terms_; i++)
	{
		int key_i = terms_[i].col + num_cols_ * terms_[i].row;
		if (key_i == key)
			return terms_[i].value;
		else if (key_i > key)
			return 0.0f;
	}

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); 

	for (int r = 0; r < temp.num_rows_; r++)
		for (int i = 0; i < num_terms_; i++)
		{
			if (terms_[i].col == r)
			{
				temp.terms_[temp.num_terms_].value = terms_[i].value;
				temp.terms_[temp.num_terms_].col = terms_[i].row;
				temp.terms_[temp.num_terms_].row = terms_[i].col;
				temp.num_terms_++;
			}
		}
			

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}
