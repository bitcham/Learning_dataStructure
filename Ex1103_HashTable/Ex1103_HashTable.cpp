#include <iostream>
#include <string> 

using namespace std;

template<typename K, typename V>
class HashTable
{
public:
	struct Item
	{
		K key = K();
		V value = V();
	};

	HashTable(const int& cap = 8)
	{
		capacity_ = cap;
		table_ = new Item[capacity_];
	}

	~HashTable()
	{
		delete[] table_;
	}

	void Insert(const Item& item)
	{
		size_t index = HashFunc(item.key);

		if (table_[index].key != K())
			cout << "Collision!" << endl;

		for (int i = 0; i < capacity_; i++)
		{
			int temp = (index + i) % capacity_;
			if (table_[temp].key == K())
			{
				table_[temp] = item;
				return;
			}
		}
		cout << "Failed to insert" << endl;
	}

	V Get(const K& key)
	{
		size_t index = HashFunc(key);
		for (int i = 0; i < capacity_; i++)
		{
			// index = (index + i) % capacity;
			size_t temp = (index + i) % capacity_;
			if (table_[temp].key == key)
				return table_[temp].value;
		}
		return V();
	}

	size_t HashFunc(const int& key)
	{
		return key % capacity_;
	}

	// Horner's method
	size_t HashFunc(const string& s)
	{
		int g = 31;
		size_t index = 0;
		for (int i = 0; i < s.size(); i++)
			index = g * index + int(s.at(i));

		return index % capacity_;
	}

	void Print()
	{
		for (int i = 0; i < capacity_; i++)
			cout << i << " : " << table_[i].key << " " << table_[i].value << endl;
		cout << endl;
	}

private:
	Item* table_ = nullptr;
	int capacity_ = 0;
};

int main()
{

	/*{
		using item = hashtable<int, int>::item;

		hashtable<int, int> h(8);

		h.insert(item{ 123, 456 });

		h.print();

		cout << "get 123 " << h.get(123) << endl;

		h.insert(item{ 1000021, 9898 });

		h.print();

		cout << "get 1000021 " << h.get(1000021) << endl;

		h.insert(item{ 1211, 999 }); // 충돌!

		h.print();

		cout << "get 123 " << h.get(123) << endl;
		cout << "get 1211 " << h.get(1211) << endl;
	}*/

	{
		using Item = HashTable<string, int>::Item;

		HashTable<string, int> h(8);

		h.Insert(Item{ "apple", 1 });
		h.Insert(Item{ "orange", 2 });
		h.Insert(Item{ "mandarin", 4 });

		h.Print();

		cout << "apple " << h.Get("apple") << endl;
		cout << "orange " << h.Get("orange") << endl;
		cout << endl;

		h.Print();

		h.Insert(Item{ "tomato", 4 });

		h.Print();

		cout << "apple " << h.Get("apple") << endl;
		cout << "orange " << h.Get("orange") << endl;
		cout << "pineapple " << h.Get("pineapple") << endl;
		cout << endl;
	}

	return 0;
}