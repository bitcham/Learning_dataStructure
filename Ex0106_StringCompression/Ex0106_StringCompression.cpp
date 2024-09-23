#include <iostream>
#include <cassert>

using namespace std;

void InsertionSort(char* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int Count(char* arr, int n, char x)
{
	int count = 0;
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] == x)
			count++;
	}

	return count;
}

int main()
{
	// char arr[] = "ababcdfdceeefda";
	// char arr[] = "a";
	char arr[] = "zzababcdfdceeedag";
	int n = sizeof(arr) - 1;

	assert(n >= 1);

	cout << arr << endl;

	int table[26] = { 0 }; 

	for (int i = 0; i < 26; i++)
	{
		int count = Count(arr, n, char(i + 97));
		table[i] = char(i + 97);
		if (count > 0)
			cout << char(table[i]) << count;
	}

	cout << endl;

	for (int i = 0; i < 26; i++)
	{
		if (table[i] > 0)
		{
			cout << char(table[i]) << Count(arr, n, char(i + 97));
		}
	}
	cout << endl << endl;


	InsertionSort(arr, n);

	cout << arr << endl;

	char c = arr[0];
	int count = 1;

	cout << c;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == c)
		{
			count++;
		}
		else
		{
			cout << count;

			c = arr[i];
			cout << c;

			count = 1;
		}
	}

	cout << count << endl;

	return 0;
}
