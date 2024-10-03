#include <iostream>

#include "../shared/MaxHeap.h"

using namespace std;

int main()
{
	MaxHeap<int> h;

	for (auto i : { 2, 8, 5, 3, 2, 1, 9, 3, 7 })
	{
		h.Push(i);
		h.Print();
	}

	while (!h.IsEmpty())
	{
		cout << h.Top() << " ";
		h.Pop();
		// h.Print();
	}
	cout << endl;

	return 0;
}
