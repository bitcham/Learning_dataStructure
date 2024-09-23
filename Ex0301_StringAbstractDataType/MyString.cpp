#include "MyString.h"

using namespace std;

MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

MyString::MyString(const char* init)
{
	size_ = 0;

	while (init[size_] != '\0')
		size_++;
	str_ = new char[size_];
	
	memcpy(str_, init, size_);
}

MyString::MyString(const MyString& str)
{
	size_ = str.size_;
	str_ = new char[size_];
	memcpy(str_, str.str_, size_);
}

MyString::~MyString()
{
	if (str_ != nullptr)
	{
		delete[] str_;
		str_ = nullptr;
	}
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str)
{
	if (this->size_ != str.size_)
		return false;
	for (int i = 0; i < this->size_; i++)
		if (str_[i] != str.str_[i])
			return false;
	return true;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	if (new_size != size_)
	{
		char* new_str = new char[new_size];
		int copy_size = (new_size < size_) ? new_size : size_;
		memcpy(new_str, str_, copy_size);

		delete[] str_;
		str_ = new_str;
		size_ = new_size;
	}
}

MyString MyString::Substr(int start, int num)
{
	assert(start + num - 1 < this->size_);

	MyString temp;
	temp.Resize(num);

	for (int i = 0; i < num; i++)
	{
		temp.str_[i] = this->str_[start + i];
	}
	return temp;
	
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;
	temp.Resize(this->size_ + app_str.size_);
	/*int j = 0;
	for (int i = this->size_ - 1; i < temp.size_; i++)
	{
		temp.str_[i] = app_str.str_[j];
		j++;
	}*/

	memcpy(temp.str_, this->str_, this->size_);
	memcpy(&temp.str_[this->size_], app_str.str_, app_str.size_);

	return temp;
	
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);
	MyString temp;
	temp.Resize(this->size_ + t.size_);
	for (int i = 0; i < start; i++)
	{
		temp.str_[i] = str_[i];
	}

	for (int i = start; i < start + t.size_; i++)
	{
		temp.str_[i] = t.str_[i - start];
	}

	for (int i = start + t.size_; i < temp.size_; i++)
	{
		temp.str_[i] = str_[i - t.size_];
	}
	

	return temp;
	
}

int MyString::Find(MyString pat)
{
	for (int start = 0; start <= Length() - pat.Length(); start++)
	{
		for (int i = 0; i < pat.Length(); i++)
		{
			if (this->str_[start + i] != pat.str_[i])
				break;

			if (i == pat.Length() - 1)
				return start;
		}
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}

