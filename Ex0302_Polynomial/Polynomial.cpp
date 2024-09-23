#include "Polynomial.h"

#include <cassert>
#include <iostream>
#include <math.h> // std::powf()

using namespace std;

Polynomial::Polynomial(int max_degree)
{
	assert(max_degree > 0);

	capacity_ = max_degree + 1;
	coeffs_ = new float[capacity_];

	for (int i = 0; i < capacity_; i++)
		coeffs_[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->capacity_ = poly.capacity_;
	coeffs_ = new float[capacity_];
	for (int i = 0; i < capacity_; i++)
		coeffs_[i] = poly.coeffs_[i];
}

Polynomial::~Polynomial()
{
	if (coeffs_) delete[] coeffs_;
}

int Polynomial::MaxDegree()
{
	return this->capacity_ - 1;
}

void Polynomial::NewTerm(const float coef, const int exp)
{
	assert(exp < capacity_);

	this->coeffs_[exp] = coef;
}

Polynomial Polynomial::Add(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_); 

	Polynomial temp(this->MaxDegree());
	for (int i = 0; i < this->capacity_; i++)
		temp.coeffs_[i] = this->coeffs_[i] + poly.coeffs_[i];
		
	return temp;
}

Polynomial Polynomial::Mult(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_);

	Polynomial temp(this->MaxDegree());
	for (int i = 0; i < this->capacity_; i++)
	{
		if (this->coeffs_[i] != 0.0f)
		{
			for (int j = 0; j < poly.capacity_; j++)
			{
				if (poly.coeffs_[j] != 0.0f && i + j < poly.capacity_)
					temp.coeffs_[i + j] = this->coeffs_[i] * poly.coeffs_[j];
			}
		}
	}
	return temp;
}

float Polynomial::Eval(float x)
{
	float temp = 0.0f;

	for (int i = 0; i < this->capacity_; i++)
		temp += this->coeffs_[i] * std::powf(x, i);

	return temp;
}

void Polynomial::Print()
{
	bool is_first = true; 

	for (int i = 0; i < capacity_; i++)
	{
		if (coeffs_[i] != 0.0f) 
		{
			if (!is_first)
				cout << " + ";

			cout << coeffs_[i];

			if (i != 0) cout << "*" << "x^" << i;

			is_first = false;
		}
	}

	cout << endl;
}