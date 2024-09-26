#include <iostream>

using namespace std;

struct Node
{
	int item = 0;

	Node* next = nullptr;

	friend ostream& operator<<(ostream& os, const Node& n)
	{
		cout << n.item << " " << flush;
		return os;
	}
};

void RecurPrint(Node* node)
{
	if (node)
	{
		cout << *node << endl;
		RecurPrint(node->next);
	}
}

void IterPrint(Node* node)
{
	Node* current = node;
	cout << *current << endl;
	while (current->next != nullptr)
	{
		current = current->next;
		cout << *current << endl;
	}
}

int main()
{
	Node* first = nullptr;
	first = new Node;
	first->item = 1;
	first->next = nullptr;

	Node* second = nullptr;
	second = new Node;
	second->item = 2;
	second->next = nullptr;

	Node* third = nullptr;
	third = new Node;
	third->item = 3;
	third->next = nullptr;

	Node* fourth = nullptr;
	fourth = new Node;
	fourth->item = 4;
	fourth->next = nullptr;

	Node* fifth = nullptr;
	fifth = new Node;
	fifth->item = 5;
	fifth->next = nullptr;


	cout << *first << endl;
	cout << *second << endl;
	cout << *third << endl;
	cout << *fourth << endl;
	cout << *fifth << endl;
	cout << endl;

	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = nullptr;


	cout << *(first) << endl;
	cout << *(first->next) << endl;
	cout << *(first->next->next) << endl;
	cout << *(first->next->next->next) << endl;
	cout << *(first->next->next->next->next) << endl;
	//cout << *(first->next->next->next->next->next) << endl; // error

	cout << endl;

	RecurPrint(first);
	cout << endl;

	IterPrint(first);
	cout << endl;

	Node* current = first;
	while (current)
	{
		Node* temp = current;

		cout << "Delete: " << *temp << endl;
		current = current->next;
		delete[] temp;
	}

	return 0;
}
