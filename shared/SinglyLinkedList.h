#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear()
	{
		while (first_)
		{
			PopFront();
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;
		Node* current = first_;
		while (current)
		{
			size++;
			current = current->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item;
	}

	T Back()
	{
		assert(first_);

		Node* current = first_;
		while (current->next)
			current = current->next;

		return current->item;
	}

	Node* Find(T item)
	{
		Node* current = first_;
		while (current)
		{
			if (current->item == item)
				return current;
			current = current->next;
		}
		return current;
	}

	void InsertBack(Node* node, T item)
	{
		Node* add_node = new Node;
		add_node->item = item;
		add_node->next = node->next;
		node->next = add_node;
	}

	void Remove(Node* n)
	{
		assert(first_);

		Node* current = first_->next;
		Node* prev = first_;
		if (first_ == n)
		{
			delete n;
			first_ = current;
			return;
		}

		while (current)
		{
			if (current == n)
			{
				prev->next = current->next;
				delete n;
				return;
			}
			prev = current;
			current = current->next;
			
		}
		
	}

	void PushFront(T item)
	{
		
		Node* temp = new Node;
		temp->item = item;
		temp->next = first_;
		first_ = temp;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			Node* current = first_;
			while (current->next)
			{
				current = current->next;
			}
			Node* new_node = new Node;
			new_node->item = item;
			new_node->next = nullptr;
			
			current->next = new_node;
		}
		else
		{
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		Node* temp = first_;
		first_ = first_->next;
		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		/*if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		} */

		assert(first_);

		Node* current = first_;
		Node* prev = nullptr;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = nullptr;
		Remove(current);

		/*Node* second_last = first_;

		while (second_last->next->next)
			second_last = second_last->next;

		Node* temp = second_last->next;
		second_last->next = second_last->next->next;

		delete temp;*/
	}

	void Reverse()
	{
		Node* prev = nullptr;
		Node* current = first_;
		while (current)
		{
			Node* temp = prev;
			prev = current;
			current = current->next;
			prev->next = temp;
		}
		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};