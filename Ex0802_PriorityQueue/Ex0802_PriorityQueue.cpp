#include <iostream>

#include "../shared/MaxHeap.h"

using namespace std;

struct Patient
{
	int severity; 
	int time;	  
	const char* name;

	friend bool operator >= (const Patient& a, const Patient& b)
	{
		if (a.severity == b.severity) 
			return a.time <= b.time;   
		else
			return a.severity > b.severity; 
	}

	friend bool operator > (const Patient& a, const Patient& b)
	{
		if (a.severity == b.severity)
			return a.time < b.time;
		else
			return a.severity > b.severity;
	}

	friend bool operator < (const Patient& a, const Patient& b)
	{
		return !(a >= b);
	}

	friend std::ostream& operator << (std::ostream& os, const Patient& p)
	{
		return os;
	}
};

int main()
{
	
	MaxHeap<Patient> h;


	h.Push({ 1, 0, "Ironman" });   
	h.Push({ 1, 1, "Nick Fury" }); 
	h.Push({ 3, 2, "Hulk" });     

	cout << h.Top().name << endl;  
	h.Pop();

	cout << h.Top().name << endl; 
	h.Pop();

	h.Push({ 2, 3, "Blue Beetle" });

	cout << h.Top().name << endl; 
	h.Pop();

	cout << h.Top().name << endl;  
	h.Pop();


	return 0;
}
