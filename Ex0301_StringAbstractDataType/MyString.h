#pragma once

#include <iostream>
#include <algorithm> // swap
#include <cassert>



class MyString
{
public:
	MyString();						
	MyString(const char* init);		
	MyString(const MyString& str);	
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(int new_size);

	MyString Substr(int start, int num);	
	MyString Concat(MyString app_str);		
	MyString Insert(MyString t, int start); 

	int Find(MyString pat);

	void Print();

private:
	char* str_ = nullptr;
	int size_ = 0; 
};
