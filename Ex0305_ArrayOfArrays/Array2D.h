#pragma once

class Array2D
{
public:
	Array2D(int num_rows, int num_cols);

	Array2D(const Array2D& b);

	~Array2D();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	Array2D Add(const Array2D& b);

	Array2D Transpose();

	void Print();

private:
	float** arrays_ = nullptr; 
	int num_rows_ = 0;
	int num_cols_ = 0;
};
