#include <iostream>

#include "Matrix.h"

int main()
{
	using namespace std;

	Matrix m1(3, 4);
	m1.SetValue(0, 0, 1.0f);
	m1.SetValue(0, 1, 2.0f);
	m1.SetValue(0, 2, 3.0f);
	m1.SetValue(1, 0, 0.0f);
	m1.SetValue(1, 1, 4.0f);
	m1.SetValue(1, 2, 5.0f);
	m1.SetValue(2, 3, 7.0f);

	m1.Print();

	cout << endl;

	Matrix add = m1.Add(m1);
	add.Print();

	cout << endl;

	Matrix tr = m1.Transpose(); 
	tr.Print();

	return 0;
}

