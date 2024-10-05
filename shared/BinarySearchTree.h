#pragma once

#include <iomanip>
#include <cassert>
#include <iostream>

template<typename K, typename V>
class BinarySearchTree
{
public:
	struct Item 
	{
		K key = K();	
		V value = V();	
	};

	struct Node
	{
		Item item;

		Node* left = nullptr;
		Node* right = nullptr;
	};

	void Preorder()
	{
		using namespace std;
		Preorder(root_);
		cout << endl;
	}

	void Preorder(Node* node)
	{
		using namespace std;
		if (node)
		{
			cout << node->item.key << " ";
			Preorder(node->left);
			Preorder(node->right);
		}
	}

	void Inorder()
	{
		using namespace std;
		Inorder(root_);
		cout << endl;
	}

	void Inorder(Node* node)
	{
		using namespace std;
		if (node)
		{
			Inorder(node->left);
			cout << node->item.key << " ";
			Inorder(node->right);
		}
	}

	Item* RecurGet(const K& key)
	{
		return RecurGet(root_, key);
	}

	Item* RecurGet(Node* node, const K& key)
	{
		if (!node) return nullptr; 

		if (key < node->item.key)
			return RecurGet(node->left, key);
		if (key > node->item.key)
			return RecurGet(node->right, key);

		return &node->item; // if (key == node->item.key)
	}

	Item* IterGet(const K& key)
	{
		if (!root_) return nullptr;
		Node* current = root_;
		while (current) {
			
			if (key < current->item.key) {
				current = current->left;
			}
			if (key > current->item.key) {
				current = current->right;
			}
			if (key == current->item.key) {
				return &current->item;
			}
		}

		return nullptr;// No matching
	}

	void Insert(const Item& item)
	{
		using namespace std;
		cout << "Insert " << item.key << item.value << endl;
		root_ = Insert(root_, item);
	}

	Node* Insert(Node* node, const Item& item)
	{
		if (!node) {
			return new Node{ item, nullptr, nullptr };
		}

		if (item.key < node->item.key)
			node->left = Insert(node->left, item);
		else if (item.key > node->item.key)
			node->right = Insert(node->right, item);
		else // if (item.key == node->item.key)
			node->item = item;

		return node;
	}

	void IterInsert(const Item& item)
	{
		std::cout << "Insert " << item.key << item.value << std::endl;

		if (!root_) {
			root_ = new Node{ item, nullptr, nullptr };
			return;
		}

		Node* current = root_;
		Node* temp = nullptr;
		int i = 0;
		while (current) {
			temp = current;
			if (item.key < current->item.key) {
				current = current->left;
				i = 1;
			}
			else if (item.key > current->item.key) {
				current = current->right;
				i = 2;
			}
			else {
				current->item.value = item.value;
				i = 0;
				return;
			}
		}

		if (i == 1) {
			temp->left = new Node{ item, nullptr, nullptr };
		}
		else if (i == 2) {
			temp->right = new Node{ item, nullptr, nullptr };
		}
	}

	Node* MinKeyLeft(Node* node)
	{
		assert(node);
		while (node->left)
			node = node->left;
		return node;
	}

	void Remove(const K& key)
	{
		using namespace std;
		cout << "Remove " << key << endl;
		root_ = Remove(root_, key);
	}

	Node* Remove(Node* node, const K& key)
	{
		if (!node) return node;

		if (key < node->item.key)
			node->left = Remove(node->left, key);
		else if (key > node->item.key)
			node->right = Remove(node->right, key);
		else
		{
			if (node->left == nullptr)
			{
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}
			Node* temp = MinKeyLeft(node->right);
			node->item = temp->item;
			node->right = Remove(node->right, temp->item.key);
			
		}

		return node;
	}

	int Height()
	{
		return Height(root_);
	}

	int Height(Node* node)
	{
		if (!node) return 0;
		return 1 + std::max(Height(node->left), Height(node->right));
	}

	void Print2D();
	void PrintLevel(int n);
	void DisplayLevel(Node* p, int lv, int d);

protected:
	Node* root_ = nullptr;
};


template<typename K, typename V>
void BinarySearchTree<K, V>::Print2D()
{
	using namespace std;
	cout << "Height = " << Height() << endl;
	int i = 0;
	while (i < Height()) {
		PrintLevel(i);
		i++;
		cout << endl;
	}
	cout << endl;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::PrintLevel(int n) {
	using namespace std;
	Node* temp = root_;
	int val = (int)pow(2.0, Height() - n + 1.0);
	cout << setw(val) << "";
	DisplayLevel(temp, n, val);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::DisplayLevel(Node* p, int lv, int d) {
	using namespace std;
	int disp = 2 * d;
	if (lv == 0) {
		if (p == NULL) {
			cout << "   ";
			cout << setw(disp - 3) << "";
			return;
		}
		else {
			int result = ((p->item.key <= 1) ? 1 : (int)log10(p->item.key) + 1);
			cout << " " << p->item.key << p->item.value << " ";
			cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
		}
	}
	else
	{
		if (p == NULL && lv >= 1) {
			DisplayLevel(NULL, lv - 1, d);
			DisplayLevel(NULL, lv - 1, d);
		}
		else {
			DisplayLevel(p->left, lv - 1, d);
			DisplayLevel(p->right, lv - 1, d);
		}
	}
}
