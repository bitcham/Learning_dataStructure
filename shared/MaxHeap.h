#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10)
	{
		assert(cap > 0);

		capacity_ = cap;
		size_ = 0;
		heap_ = new T[capacity_ + 1]; //heap_[0] empty
	}

	void Resize(int new_capacity)
	{
		T* new_heap = new T[new_capacity];
		memcpy(new_heap, heap_, sizeof(T) * (size_ + 1));
		if (heap_) delete[] heap_;
		heap_ = new_heap;
		capacity_ = new_capacity;
	}

	T Top()
	{
		return heap_[1];
	}

	bool IsEmpty()
	{
		return size_ == 0;
	}

	void Print()
	{
		using namespace std;
		cout << "Index: ";
		for (int i = 1; i <= size_; i++)
			cout << setw(3) << i;
		cout << endl;

		cout << "Value: ";
		for (int i = 1; i <= size_; i++)
			cout << setw(3) << heap_[i];
		cout << endl << endl;
	}

	void Push(const T& item)
	{
		using namespace std;
		cout << "Push " << item << endl;

		if (size_ == capacity_)
			Resize(capacity_ * 2);


		size_ += 1;
		int current = size_; 

		while (current != 1 && item > heap_[current / 2])
		{
			heap_[current] = heap_[current / 2];
			
			cout << "Current = " << current << endl;
			Print();

			current /= 2;
		}

		heap_[current] = item;
	}

	void Pop()
	{
		assert(!IsEmpty());

		using namespace std;
		cout << "Pop()" << endl;

		T last_item = heap_[size_]; 
		size_--;					

		int current = 1;			
		int child = 2;				
		while (child <= size_)
		{
			if (child < size_ && heap_[child] < heap_[child + 1]){
				child++;
			}

			if (last_item > heap_[child]) {
				break;
			}


			heap_[current] = heap_[child];

			cout << "Current = " << current << ", child = " << child << endl;
			Print();

			current = child;
			child *= 2;
		}

		heap_[current] = last_item;
	}

private:
	T* heap_ = nullptr;
	int size_ = 0;
	int capacity_ = 0;
};

