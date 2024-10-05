#include <iostream>

#include "../shared/BinarySearchTree.h"

using namespace std;

int main()
{
	using Item = BinarySearchTree<int, char>::Item;

	BinarySearchTree<int, char> bst;

	for (int i : { 5, 3, 7, 1, 4, 6, 8 })
		//for (int i : { 9, 8, 7, 6, 5})
	{
		// bst.Insert({ i, char('A' + i) });
		bst.IterInsert(Item{ i, char('A' + i) });
		bst.Print2D();
	}

	bst.IterInsert({ 6, 'Z' });
	bst.Print2D();

	bst.Inorder(); 

	
	cout << bst.RecurGet(5)->value << endl; 
	cout << bst.RecurGet(3)->value << endl;
	cout << bst.RecurGet(7)->value << endl;
	cout << bst.RecurGet(1)->value << endl;
	cout << bst.RecurGet(4)->value << endl;

	bst.Remove(999);
	bst.Print2D();

	for (int i : {5, 4, 7, 3})
	{
		bst.Remove(i);
		bst.Print2D();
	}

	return 0;
}
