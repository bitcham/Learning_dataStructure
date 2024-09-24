#include "../shared/Queue.h"

#include <iostream>

using namespace std;

int main()
{
	int n = 7, k = 3;

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	q.Print();
	
	while (q.Size() != 1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			int temp = q.Front();
			q.Dequeue();
			q.Enqueue(temp);
		}
		cout << "Executed " << q.Front()<< endl;
		q.Dequeue();
		
	}

	
	cout << "Survivor: " << q.Front() << endl;

	return 0;
}