#include <iostream>
#include "../shared/SinglyLinkedList.h"

using namespace std;

struct Term
{
	float coef;
	int exp;
};

class LinkedPolynomial : public SinglyLinkedList<Term>
{
public:
	typedef SinglyLinkedList<Term>::Node Node;

	void NewTerm(float coef, int exp)
	{
		Term term = { coef, exp };
		
		PushBack(term);
	}

	float Eval(float x)
	{
		float temp = 0.0f;
		Node* current = first_;
		while (current)
		{
			temp += current->item.coef * powf(x, float(current->item.exp));
			current = current->next;
		}

		return temp;
	}

	LinkedPolynomial Add(const LinkedPolynomial& poly)
	{

		LinkedPolynomial temp;

		Node* i = this->first_;
		Node* j = poly.first_;

		while (i && j) {
			if (i->item.exp == j->item.exp)
			{
				float sum = i->item.coef + j->item.coef;
				if (sum)
					temp.NewTerm(sum, i->item.exp);
				i = i->next;
				j = j->next;
			}
			else if (i->item.exp > j->item.exp){
				temp.PushBack(j->item);
				j = j->next;
			}
			else {
				temp.PushBack(i->item);
				i = i->next;
			}
		}
		for (; i; i = i->next)
			temp.PushBack(i->item);
		for (; j; j = j->next)
			temp.PushBack(j->item);
		return temp;
	}

	void Print()
	{
		bool is_first = true;

		Node* current = first_;
		if (!current) {
			is_first = false;
		}
		while (is_first) {
			if (current->item.exp == 0)
				cout << current->item.coef;
			else
			{
				cout << current->item.coef << "*x^" << current->item.exp;
			}

			current = current->next;
			if (!current) break;
			cout << " + ";
		}

		cout << endl;
	}

private:
};

int main()
{
	using namespace std;

	LinkedPolynomial p1;

	
	p1.NewTerm(1.0f, 0);	// 1 * x^0 = 1
	p1.NewTerm(1.5f, 1);	// 1.5 * x^1
	p1.NewTerm(2.0f, 2);	// 2 * x^2

	p1.Print(); // 1 + 1.5*x^1 + 2*x^2

	cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
	cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
	cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

	cout << endl;

	// Add() Test1
	cout << "Add() Test" << endl;
	{
		LinkedPolynomial p1; 

		p1.NewTerm(1.0f, 0);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(2.0f, 2);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2

		LinkedPolynomial p2;

		p2.NewTerm(1.0f, 1);
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(5.0f, 7);
		p2.NewTerm(2.0f, 11);

		p2.Print(); // 1*x^1 + 3*x^2 + 5*x^7 + 2*x^11

		cout << endl;

		LinkedPolynomial psum = p1.Add(p2);
		psum.Print(); // 1 + 2.5*x^1 + 5*x^2 + 5*x^7 + 2*x^11

		cout << endl;
	}

	// Add() Test2
	cout << "Add() Test2" << endl;
	{
		LinkedPolynomial p1;

		p1.NewTerm(1.0f, 0);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(2.0f, 2);
		p1.NewTerm(5.0f, 7);
		p1.NewTerm(3.5f, 10);
		p1.NewTerm(5.5f, 20);
		p1.NewTerm(5.0f, 1000);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2 + 5*x^7 + 3.5*x^10 + 5.5*x^20 + 5*x^1000

		LinkedPolynomial p2;

		p2.NewTerm(3.2f, 0);
		p2.NewTerm(1.0f, 1);
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(2.0f, 11);

		p2.Print(); // 3.2 + 1*x^1 + 3*x^2 + 2*x^11

		cout << endl;

		LinkedPolynomial psum = p1.Add(p2);
		psum.Print(); // 4.2 + 2.5*x^1 + 5*x^2 + 5*x^7 + 3.5*x^10 + 2*x^11 + 5.5*x^20 + 5*x^1000

		cout << endl;
	}

	return 0;
}
