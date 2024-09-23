#include "SparsePolynomial.h"

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;


void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f) return;

	if (num_terms_ >= capacity_)
	{
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; 
		Term* new_term = new Term[capacity_];

		memcpy(new_term, terms_, sizeof(Term) * num_terms_);

		if (terms_) delete[] terms_;
		terms_ = new_term;
	}

	terms_[num_terms_].coef = coef;
	terms_[num_terms_].exp = exp;

	num_terms_++;
}

float SparsePolynomial::Eval(float x)
{
	float temp = 0.0f;

	for (int i = 0; i < num_terms_; i++)
	{
		temp += this->terms_[i].coef * powf(x, this->terms_[i].exp);
	}
	return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	SparsePolynomial temp;


	int i = 0, j = 0;

	while ((i < this->num_terms_) && (j < poly.num_terms_))
	{
		if ((terms_[i].exp == poly.terms_[j].exp))
		{
			temp.NewTerm(terms_[i].coef + poly.terms_[j].coef, terms_[i].exp);
			i++;
			j++;
		}
		else if ((terms_[i].exp > poly.terms_[j].exp))
		{
			temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
			j++;
		}
		else
		{
			temp.NewTerm(terms_[i].coef, terms_[i].exp);
			i++;
		}

	}

	for (; i < num_terms_; i++)
	{
		temp.NewTerm(terms_[i].coef, terms_[i].exp);
	}

	for (; j < poly.num_terms_; j++)
	{
		temp.NewTerm(poly.terms_[i].coef, poly.terms_[i].exp);
	}

	return temp;
}

void SparsePolynomial::Print()
{
	bool is_first = true; 

	for (int i = 0; i < num_terms_; i++)
	{
		if (!is_first)
			cout << " + ";

		cout << terms_[i].coef;

		if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

		is_first = false;
	}

	cout << endl;
}
