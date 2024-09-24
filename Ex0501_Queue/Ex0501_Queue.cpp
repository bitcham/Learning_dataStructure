#include "../shared/Queue.h"

#include <iostream>

int main()
{
	Queue<char> q(2); 

	q.SetDebugFlag(true);

	q.Print();

	q.Enqueue('A');
	q.Print();

	q.Enqueue('B');
	q.Print();

	q.Enqueue('C');
	q.Print();

	q.Enqueue('D');
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	for (char c = 'E'; c <= 'K'; c++)
	{
		q.Enqueue(c);
		q.Print();
	}

	return 0;
}
