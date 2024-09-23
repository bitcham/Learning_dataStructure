#include <iostream>

using namespace std;


void MySwapPtr(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void MySwapRef(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}


bool checksorted(int a, int b)
{	
	if (a > b)
		return false;
	else
		return true;
}

int main()
{
	{
		int a = 3;
		int b = 2;

		cout << a << " " << b << endl;

		MySwapRef(a, b);

		cout << a << " " << b << endl;
	}


	// sorting
	{
		int arr[] = { 9, 3 };

		//cout << arr[0] << " " << arr[1] << endl;

		if (arr[0] > arr[1])
			MySwapRef(arr[0], arr[1]);

		cout << arr[0] << " " << arr[1] << endl;
	}

	{
		int arr[5] = { 3, 5, 2, 1, 6 };
		int n = sizeof(arr) / sizeof(arr[0]);
		
		
		for (int j = 0; j < n; j++)
		{
			for (int i = j + 1; i < n; i++)
			{
				cout << boolalpha;
				cout << arr[j] << " "<< arr[i] << " ";
				cout << (checksorted(arr[j], arr[i]) == 1 ? true : false) << endl;
				if (arr[j] > arr[i])
				{
					MySwapRef(arr[j], arr[i]);
				}
			}

		}
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}

	int arr[2];

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			arr[0] = j;
			arr[1] = i;

			if (arr[0] > arr[1])
				swap(arr[0], arr[1]);

			cout << boolalpha;
			cout << arr[0] << " " << arr[1]\
				<< " " << checksorted(arr[0], arr[1]) << endl;
		}
	}

	return 0;
}

