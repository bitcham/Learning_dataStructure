#include <iostream>

using namespace std;

void Func2()
{
	cout << "This is Func2()" << endl;
}

void Func1()
{
	Func2();

	cout << "This is Func1()" << endl;
}

void RecurFunc(int count)
{
	if (count == 0) 
		return;

	cout << count << endl;

	RecurFunc(count - 1);

}

int main()
{

	RecurFunc(5); 

	return 0;
}