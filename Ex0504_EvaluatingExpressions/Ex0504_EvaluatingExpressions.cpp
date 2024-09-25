#include <iostream>

#include "../shared/Stack.h"
#include "../shared/Queue.h"

using namespace std;

int Prec(char c);
void InfixToPostfix(Queue<char>& q, Queue<char>& output);
int EvalPostfix(Queue<char>& q);

int main()
{
	//const char infix[] = "8/2+(3+4)*5-1*2";
	//const char infix[] = "1+(1*2+3)*4";
	//const char infix[] = "1+2*3+3";
	//const char infix[] = "1+2*(3+1)";
	const char infix[] = "1*2-3";
	const int size = sizeof(infix) / sizeof(char) - 1;

	Queue<char> q;
	for (int i = 0; i < size; i++)
		q.Enqueue(infix[i]);

	Queue<char> postfix;

	cout << "Infix: ";
	q.Print();
	cout << endl;

	InfixToPostfix(q, postfix);

	cout << "Postfix: ";
	postfix.Print();

	cout << "Evaluated = " << EvalPostfix(postfix) << endl;

	return 0;
}

int Prec(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1; 
}

void InfixToPostfix(Queue<char>& q, Queue<char>& output)
{
	Stack<char> s;

	output.SetDebugFlag(false);

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		cout << c << endl;

		if (c >= '0' && c <= '9') 
			output.Enqueue(c);
		else if (c == '(') 
			s.Push(c);
		else if (c == ')') 
		{
			while (s.Top() != '(')
			{
				output.Enqueue(s.Top());
				s.Pop();
			}
			s.Pop(); 
		}
		else 
		{
			while (!s.IsEmpty() && Prec(c) <= Prec(s.Top()))
			{
				output.Enqueue(s.Top());
				s.Pop();
			}

			s.Push(c);
		}

		cout << "Stack: ";
		s.Print();
		cout << "Output:";
		output.Print();
		cout << endl;
	}

	while (!s.IsEmpty())
	{
		output.Enqueue(s.Top());
		s.Pop();
	}
}

int EvalPostfix(Queue<char>& q)
{
	Stack<int> s;

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		cout << c << endl;

		
		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			s.Push(c-48);
		}
		else
		{
			cout << "Operator: " << c << endl;

			int temp_1 = s.Top();
			s.Pop();
			int temp_2 = s.Top();
			s.Pop();

			if (c == '+') {
				s.Push(temp_2 + temp_1);
			}
			else if (c == '-') {
				s.Push(temp_2 - temp_1);
			}
			else if (c == '*') {
				s.Push(temp_2 * temp_1);
			}
			else if (c == '/')
			{
				s.Push(temp_2 / temp_1);
			}
			else
			{
				cout << "Wrong operator" << endl;
				exit(-1); 
			}
		}
		

		cout << "Stack: ";
		s.Print();
	}

	return s.Top();
}
