#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class Queue 
{
public:
	Queue(int capacity = 2)
	{
		assert(capacity > 0);

		capacity_ = capacity;
		queue_ = new T[capacity_];
		front_ = rear_ = 0;
	}

	~Queue()
	{
		if (queue_) delete[] queue_;
	}

	bool IsEmpty() const
	{
		return front_ == rear_;
	}

	bool IsFull() const
	{
		return (rear_ + 1) % capacity_ == front_;
	}

	T& Front() const
	{
		assert(!IsEmpty());

		return queue_[(front_ + 1) % capacity_];
	}

	T& Rear() const
	{
		assert(!IsEmpty());

		return queue_[rear_];
	}

	int Size() const
	{

		if (front_ < rear_)
			return rear_ - front_;
		else if (front_ > rear_)
			return capacity_ - front_ + rear_;
		else
			return 0;

		/* if (front_ > rear_)
			  return capacity_ - front_ + rear_;
		 else
		    return rear_ - front_*/;
	}

	void Resize()
	{

		T* new_queue = new T[capacity_ * 2];
		
		int count = 1;
		for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_)
		{
			new_queue[count] = queue_[i];
			count++;
		}

		front_ = 0;
		rear_ = capacity_ - 1;
		capacity_ = capacity_ * 2;
		delete[] queue_;
		queue_ = new_queue;
	}

	void Enqueue(const T& item) 
	{
		if (IsFull())
			Resize();
		rear_ = (rear_ + 1) % capacity_;
		queue_[rear_] = item;
	}

	void Dequeue() 
	{
		assert(!IsEmpty());

		front_ = (front_ + 1) % capacity_;
	}

	void Print()
	{
		using namespace std;

		for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_)
			cout << queue_[i] << " ";
		cout << endl;

		if (print_debug_)
			PrintDebug();
	}

	void PrintDebug()
	{
		using namespace std;

		cout << "Cap = " << capacity_ << ", Size = " << Size();
		cout << endl;

		for (int i = 0; i < capacity_; i++) {
			if (i == front_) cout << " F ";
			else if (i == rear_) cout << " R ";
			else cout << "   ";
		}
		cout << endl;

		for (int i = 0; i < capacity_; i++)
			cout << setw(2) << i << " ";
		cout << endl;

		if (front_ < rear_)
		{
			for (int i = 0; i < front_ + 1; i++)
				cout << " - ";

			for (int i = front_ + 1; i <= rear_; i++)
				cout << setw(2) << queue_[i] << " ";

			for (int i = rear_ + 1; i < capacity_; i++)
				cout << " * ";

			cout << endl << endl;
		}
		else if (front_ > rear_)
		{
			for (int i = 0; i <= rear_; i++)
				cout << setw(2) << queue_[i] << " ";

			for (int i = rear_ + 1; i <= front_; i++)
				cout << " * ";

			for (int i = front_ + 1; i < capacity_; i++)
				cout << setw(2) << queue_[i] << " ";

			cout << endl << endl;
		}
		else
		{
			for (int i = 0; i < capacity_; i++)
				cout << " - ";
			cout << endl << endl;
		}
	}

	void SetDebugFlag(bool flag)
	{
		print_debug_ = flag;
	}

protected: 
	T* queue_;
	int front_ = 0; 
	int rear_ = 0; 
	int capacity_; 
	bool print_debug_ = false;
};
