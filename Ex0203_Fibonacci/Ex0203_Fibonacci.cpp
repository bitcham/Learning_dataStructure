#include <iostream>
#include <cassert>
#include <algorithm> // swap
#include <iomanip> // setw

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0; 
	else if (n == 1)
		return 1; 
	else
	{
		int prev_1 = 0;
		int	prev_2 = 1;
		int fn = 1;
		for (int i = 2; i <= n; i++)
		{
			fn = prev_1 + prev_2;
			
			prev_1 = prev_2;
			prev_2 = fn;
		}

		return fn;
	}
}

int RecurFibonacci(int n)
{
	if (n < 0)
		return 0;
	else if (n == 1)
		return 1;
	
	return RecurFibonacci(n-1) + RecurFibonacci(n-2);
}

int main()
{
	cout << "Input     : ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << i << " ";
	cout << endl;

	// Fibonnacci
	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << Fibonacci(i) << " ";
	cout << endl;

	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << RecurFibonacci(i) << " ";
	cout << endl;

	return 0;
}
