#include <iostream>

using namespace std;

int rec_count = 0;

int InterpolationSearch(int arr[], int low, int high, int x)
{
	rec_count++;

	if (low <= high && x >= arr[low] && x <= arr[high])
	{
		//int pos = (low + high) / 2; 
		//int pos = high * ((x - arr[low]) / (arr[high] - arr[low])) - low * ((x - arr[low]) / (arr[high] - arr[low])) + low;
		int pos = low + (int)((float)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));

		if (arr[pos] == x)
			return pos;

		if (arr[pos] < x)
			return InterpolationSearch(arr, pos + 1, high, x);

		if (arr[pos] > x)
			return InterpolationSearch(arr, low, pos - 1, x);
	}

	return -1;
}

int main()
{
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (auto x : { 10, 18, 33, 47, -1, 99 })
	{
		rec_count = 0;

		int index = InterpolationSearch(arr, 0, n - 1, x);

		if (index != -1)
			cout << x << " was found at index " << index << endl;
		else
			cout << x << " was not found." << endl;

		cout << "rec_count = " << rec_count << endl;
		cout << endl;
	}

	return 0;
}