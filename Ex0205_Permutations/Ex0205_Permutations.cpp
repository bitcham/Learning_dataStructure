#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char* arr, int left, int right)
{
	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int j = 0; j <= right; j++)
		{
			swap(arr[j], arr[j]);
			RecurPermutations(arr, j + 1, right);
			cout << arr[j] << " ";

		}


		
	}
}

int main()
{
	// Permutations
	char arr[] = "abcd";

	RecurPermutations(arr, 0, 0);
	cout << endl;

	RecurPermutations(arr, 0, 1);
	cout << endl;

	RecurPermutations(arr, 0, 2);
	cout << endl;

	// RecurPermutations(arr, 0, 3);
	// cout << endl;

	return 0;
}
