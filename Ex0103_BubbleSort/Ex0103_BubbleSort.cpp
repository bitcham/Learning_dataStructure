#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	//int arr[] = { 5, 1, 4, 2, 8 };
	//int arr[] = { 5, 4, 3, 2, 1 }; // Worst Case
	int arr[] = { 1, 2, 3, 5, 4 }; // Best Case
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);
	cout << endl;

	// Bubble Sort
	//int max_index;
	//for (int j = n - 1; j >= 0; j--)
	//{	
	//	max_index = j;
	//	for (int i = 0; i < j + 1; i++)
	//	{
	//		if (arr[max_index] < arr[i])
	//			max_index = i;
	//	}
	//	swap(arr[j], arr[max_index]);
	//	Print(arr, n);
	//}
	//
	//cout << endl;

	
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;

		/*int temp = arr[i];*/

		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
			Print(arr, n);
		}
		
	/*	if (temp == arr[i])
			break;*/

		if (swapped == false)
			break;
		

		cout << endl;
	}
	// Best case
	// Stability
}
