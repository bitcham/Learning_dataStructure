#pragma once

#include <cassert>
#include <iostream>

template<typename T> 
class Stack
{
public:
	Stack(int capacity = 1)
	{
		assert(capacity > 0);
		Resize(capacity);
	}

	~Stack()
	{
		if (stack_) delete[] stack_;
	}

	void Resize(int new_capacity)
	{
		T* new_stack = new T[new_capacity];
		memcpy(new_stack, stack_, sizeof(T) * Size());
		if (stack_) delete[] stack_;
		stack_ = new_stack;
		capacity_ = new_capacity;
	}

	bool IsEmpty() const
	{

		return top_ == -1;
	}

	int Size() const
	{
		
		return top_ + 1;
	}

	void Print()
	{
		using namespace std;

		for (int i = 0; i < Size(); i++)
			cout << stack_[i] << " ";
		cout << endl;
	}

	T& Top() const
	{
		assert(!IsEmpty());

		return stack_[top_];
	}

	void Push(const T& item)
	{
		if (top_ == capacity_ - 1)
			Resize(capacity_ * 2);
		
		stack_[++top_] = item;
		
	}

	void Pop()
	{
		assert(!IsEmpty());

		top_--;
	}

protected:
	T* stack_ = nullptr;
	int top_ = -1; 
	int capacity_ = 0;
};
