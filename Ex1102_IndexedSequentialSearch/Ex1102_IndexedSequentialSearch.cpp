#include <iostream>

using namespace std;

int SequentialSearch(int arr[], int start, int stop, int x)
{
	for (int i = start; i < stop; i++)
	{
		if (arr[i] == x)
			return i;
	}

	return -1;
}

int main()
{
	int arr[] = { 1, 2, 8, 13, 22, 45, 55, 75, 88 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int keys[] = { 1, 13, 55 };
	int kn = sizeof(keys) / sizeof(keys[0]);

	int indices[] = { 0, 3, 6, n };

	for (int x : {1, 2, 8, 13, 22, 45, 55, 75, 88, 99, -1, 47, 101, 1000, 7, 10, 50, 60 })
	{
		if (x < arr[0] || x > arr[n - 1])
			cout << x << " was not found" << endl;
		else
		{
			/*for (int i = 0; i < kn; i++) {
				if (x < keys[i]) {
					int found = SequentialSearch(arr, indices[i - 1], indices[i], x);
					if (found >= 0) {
						cout << x << " was found at " << found << endl;
					}
					else {
						cout << x << " was not found" << endl;
					}
					break;
				}
				else if (x > keys[kn - 1]) {
					int found = SequentialSearch(arr, indices[kn-1], indices[kn], x);
					if (found >= 0) {
						cout << x << " was found at " << found << endl;
					}
					else {
						cout << x << " was not found" << endl;
					}
					break;
				}
			}*/

			int k = 0;
			while (k < kn - 1 && keys[k + 1] <= x)
				k++;

			int found = SequentialSearch(arr, indices[k], indices[k + 1], x);
			if (found >= 0)
				cout << x << " was found at " << found << endl;
			else
				cout << x << " was not found" << endl;
		}
	}
	return 0;
}
