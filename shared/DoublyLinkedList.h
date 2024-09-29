#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;
	};

	DoublyLinkedList()
	{
	}
	DoublyLinkedList(const DoublyLinkedList& list)
	{
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->right;
		}
	}

	~DoublyLinkedList()
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
		while (current) {
			size++;
			current = current->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			
			while (true)
			{
				cout << current->item << " ";

				if (!current->right)
					break;
				current = current->right;
			}

			/*Node* temp = new Node;
			temp = current;
			while (current)
			{
				temp = current;
				cout << current->item << " ";
				current = current->right;
			}
			current = temp;*/

			cout << endl;

			cout << "Backward: ";
			while (true)
			{
				cout << current->item << " ";
				if (!current->left)
					break;
				current = current->left;
			}

			/*while (current) {
				cout << current->item << " ";
				current = current->left;
			}*/

			cout << endl;
		}
	}

	Node* Find(T item)
	{
		Node* current = first_;
		while (current)
		{
			if (current->item == item)
				return current;
			current = current->right;
		}
		return current;
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			Node* add_node = new Node;
			add_node->item = item;
			add_node->right = node->right;
			node->right = add_node;

			if(add_node->right)
				add_node->right->left = add_node;

			add_node->left = node;
		}
	}

	void PushFront(T item)
	{
		Node* temp = new Node;
		temp->item = item;
		temp->right = first_;
		if(first_) {
			first_->left = temp;
		}
		first_ = temp;
		first_->left = nullptr;
	}

	void PushBack(T item)
	{
		if (first_) {
			Node* current = first_;
			while (current->right) {
				current = current->right;
			}
			Node* new_node = new Node;
			new_node->item = item;
			new_node->right = nullptr;
			new_node->left = current;
			current->right = new_node;
		}
		else {
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

		first_ = first_->right;
		if (first_)
			first_->left = nullptr;
		delete temp;

		/*if (first_->right) {
			first_ = first_->right;
			first_->left = nullptr;
			delete temp;
		}
		else {
			first_ = first_->right;
			delete temp;
		}*/
		
		
		
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		assert(first_);

		if (first_->right == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		} 

		Node* second_last = first_;

		while (second_last->right->right)
			second_last = second_last->right;

		Node* temp = second_last->right;
		second_last->right = nullptr;


		delete temp;

	}

	void Reverse()
	{
		if (IsEmpty())
			return;

		Node* prev = nullptr;
		Node* current = first_;
		
		while(current)
		{
			prev = current;
			current = current->right;

			std::swap(prev->left, prev->right);
		}

		/*while (current)
		{
			Node* temp = prev;
			prev = current;
			current = current->right;
			prev->right = temp;
			prev->left = current;
		}*/

		first_ = prev;
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
		while (current->right)
			current = current->right;

		return current->item;
	}

protected:
	Node* first_ = nullptr;
};