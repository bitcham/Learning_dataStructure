#include <iostream>
#include <iomanip>

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

void Print(int* arr, int left, int right)
{
	for (int i = left; i <= right; i++)
		cout << setw(3) << arr[i] << " ";
	cout << endl;
}

void Merge(int init[], int merged[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	cout << "  Left : ";
	Print(init, left, mid);
	cout << " Right : ";
	Print(init, mid + 1, right);

	while (i <= mid && j <= right)
	{
		if (init[i] <= init[j])
			merged[k++] = init[i++];
		else
			merged[k++] = init[j++];
	}

	if (i > mid)
		for (l = j; l <= right; l++)
			merged[k++] = init[l];
	else
		for (l = i; l <= mid; l++)
			merged[k++] = init[l];

	// merged -> init 
	for (l = left; l <= right; l++)
		init[l] = merged[l];

	cout << "Merged : ";
	Print(init, left, right);
	cout << endl;
}

void MergeSort(int arr[], int merged[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, merged, left, mid);
		MergeSort(arr, merged, mid + 1, right);

		Merge(arr, merged, left, mid, right);
	}
}

int main()
{
	//int arr[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6 }; 
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int* merged = new int[n]; 

	Print(arr, 0, n - 1);
	cout << endl;

	MergeSort(arr, merged, 0, n - 1);

	Print(merged, 0, n - 1);
	cout << endl;

	delete[] merged;

}
