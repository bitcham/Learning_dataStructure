#include <iostream>

#include "../shared/Stack.h" 

int main()
{
	using namespace std;


	Stack<char> s;

	s.Push('A');
	s.Print();

	s.Push('B');
	s.Print();

	s.Push('C');
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	s.Push('E');
	s.Print();

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();

	{
		Stack<int> int_stack;
		int_stack.Push(123);
		cout << int_stack.Top() << endl;
		int_stack.Top();
	}

	{
		const char str[] = "Hello, World!";
		const int size = sizeof(str) - 1; 

		cout << "Input: " << str << endl;

		Stack<char> stack;

		for (int i = 0; i < size; i++)
		{
			stack.Push(str[i]);
		}

		while (!stack.IsEmpty())
		{
			cout << stack.Top();
			stack.Pop();
		}

		cout << endl;
	}

	return 0;
}
