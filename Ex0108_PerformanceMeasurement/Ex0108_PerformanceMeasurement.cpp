#include <iostream>
#include <cassert>
#include <chrono>
#include <fstream>
#include <algorithm> // swap

using namespace std;
using namespace std::chrono;

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ShuffleArray(int arr[], int n)
{
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
}

int SequentialSearch(int* arr, int n, int x)
{
	int i;
	for (i = 0; i < n && arr[i] != x; i++);
	if (i == n) return -1;
	else return i;
}

int BinarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2; 

		if (x < arr[middle])
			right = middle - 1;
		else if (x > arr[middle])
			left = middle + 1;
		else
			return middle;
	}

	return -1; // Not found
}

int main()
{

	const int kNumTest = int(pow(2, 18));


	ofstream ofile("performance.txt");			// TEST 1
	//ofstream ofile("performance_worst.txt");  // TEST 2

	//for (int n = 1; n <= kNumTest; n *= 2) 
	for (int n = 1; n <= kNumTest; n += int(pow(2, 10)))
	{
		int* x_table = new int[n + 1];
		for (int i = 0; i < n; i++) {
			x_table[i] = i;
		}
		x_table[n] = n;

		ShuffleArray(x_table, n + 1);

		double seq_sum = 0.0;
		double bi_sum = 0.0;
		double seq_max = 0.0; //worst
		double bi_max = 0.0;
		double seq_min = 10000.0;
		double bi_min = 10000.0;

		for (int x = 0; x < n + 1; x++)
		{
			int result_seq;
			int result_bi;
			int x_find = x_table[x];

			// Sequential Search
			{
				int* arr = new int[n];
				for (int i = 0; i < n; i++)
					arr[i] = i;

				auto start = high_resolution_clock::now();
				result_seq = SequentialSearch(arr, n, x_find); // TEST 1
				//result_seq = SequentialSearch(arr, n, n + rand() % 1000); // TEST 2
				auto stop = high_resolution_clock::now();
				auto duration = double(duration_cast<nanoseconds>(stop - start).count()) / 1000.0;
				seq_sum += duration;
				seq_max = std::max(duration, seq_max);
				seq_min = std::min(duration, seq_min);

				delete[] arr;
			}

			// Binary Search
			{
				int* arr = new int[n];
				for (int i = 0; i < n; i++)
					arr[i] = i;

				auto start = high_resolution_clock::now();
				result_bi = BinarySearch(arr, n, x_find); // TEST 1
				// result_bi = BinarySearch(arr, n, n + rand() % 1000); // TEST 2
				auto stop = high_resolution_clock::now();
				auto duration = double(duration_cast<nanoseconds>(stop - start).count()) / 1000.0;
				bi_sum += duration;
				bi_max = std::max(duration, bi_max);
				bi_min = std::min(duration, bi_min);

				delete[] arr;
			}

			if (result_bi != result_seq)
			{
				cout << "Wrong " << result_seq << " " << result_bi << endl;
				exit(0);
			}
		}

		seq_sum /= n + 1;
		bi_sum /= n + 1; 

		cout << n << ", " << seq_max << ", " << bi_max << ", " << seq_sum << ", " << bi_sum << ", " << seq_min << ", " << bi_min << endl;
		ofile << n << ", " << seq_max << ", " << bi_max << ", " << seq_sum << ", " << bi_sum << ", " << seq_min << ", " << bi_min << endl;

		delete[] x_table;
	}

	ofile.close();

	return 0;
}
