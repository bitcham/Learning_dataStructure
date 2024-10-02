#include <iostream>

#include "../shared/Stack.h"
#include "../shared/Queue.h"
#include "../shared/BinaryTree.h"

using namespace std;

// Function to return precedence of operators
int Prec(char c);
void InfixToPostfix(Queue<char>& q, Queue<char>& output);
int EvalPostfix(Queue<char>& q);

class ExpressionTree : public BinaryTree<char>
{
public:
	typedef BinaryTree<char> Base;

	ExpressionTree(Node* root) : Base(root) {}

	bool IsDigit(char c)
	{
		if (c >= '0' && c <= '9') return true;
		else return false;
	}

	int Evaluate()
	{
		return Evaluate(Base::root_);
	}

	int Evaluate(Node* node)
	{
		if (!node) return 0;

		if (IsDigit(node->item))
			return node->item - '0';
		else if (node->item == '*')
			return Evaluate(node->left) * Evaluate(node->right);
		else if (node->item == '+')
			return Evaluate(node->left) + Evaluate(node->right);
		else if (node->item == '-')
			return Evaluate(node->left) - Evaluate(node->right);
		else
			return Evaluate(node->left) / Evaluate(node->right);
	}

	void Infix() { Infix(root_); cout << endl; }
	void Infix(Node* node)
	{
		if (node)
		{
			if (!IsDigit(node->item)) cout << "(";
			Infix(node->left);
			cout << node->item;
			Infix(node->right);
			if (!IsDigit(node->item)) cout << ")";
		}
	}


	void Postfix() { Postfix(root_);  cout << endl; }
	void Postfix(Node* node) {
		if (node)
		{
			Postfix(node->left);
			Postfix(node->right);
			cout << node->item;
		}
	}

	// Infix -> postfix -> expression tree
	ExpressionTree(const char* infix)
	{
		// Infix -> Postfix
		Queue<char> q;
		for (int i = 0; infix[i] != '\0'; i++)
			q.Enqueue(infix[i]);
		cout << "  Infix: ";
		q.Print();
		Queue<char> postfix;
		InfixToPostfix(q, postfix);
		cout << "Postfix: ";
		postfix.Print();

		// Postfix -> Expression tree

		Stack<Node*> s;

		while (!postfix.IsEmpty())
		{
			char c = postfix.Front();
			postfix.Dequeue();

			if (c >= '0' && c <= '9')
			{
				Node* temp = new Node{ c, nullptr, nullptr };
				s.Push(temp);
			}
			else
			{
				Node* temp = new Node{ c, nullptr, nullptr };
				temp->right = s.Top();
				s.Pop();
				temp->left = s.Top();
				s.Pop();
				s.Push(temp);
			}
		}

		root_ = s.Top();
	}
};

int main()
{
	using Node = ExpressionTree::Node;

	// 5 + (3 - 2) * 4
	// 
	//    +
	//	/   \
	// 5     *
	//	    / \
	//	   -   4
	//	  / \
	//	 3   2

	Node* n1 = new Node{ '5', nullptr, nullptr };
	Node* n2 = new Node{ '+', nullptr, nullptr };
	Node* n3 = new Node{ '3', nullptr, nullptr };
	Node* n4 = new Node{ '-', nullptr, nullptr };
	Node* n5 = new Node{ '2', nullptr, nullptr };
	Node* n6 = new Node{ '*', nullptr, nullptr };
	Node* n7 = new Node{ '4', nullptr, nullptr };

	// +
	n2->left = n1; // 5
	n2->right = n6; // *

	// *
	n6->left = n4; // -
	n6->right = n7; // 4

	// -
	n4->left = n3; // 3
	n4->right = n5; // 2

	ExpressionTree tree(n2);

	tree.Print2D();

	cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9

	cout << "  Infix: ";
	tree.Infix();   // (5+((3-2)*4)) 

	cout << "Postfix: ";
	tree.Postfix(); // 532-4*+

	cout << endl;

	// Infix -> Postfix -> Expression Tree
	{
		// const char infix[] = "1+(1*2+3)*4";
		const char infix[] = "(5+((3-2)*4))";

		ExpressionTree tree(infix);

		tree.Print2D();

		cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9
	}

	return 0;
}

// Function to return precedence of operators
int Prec(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void InfixToPostfix(Queue<char>& q, Queue<char>& output)
{
	Stack<char> s; 

	output.SetDebugFlag(false);

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		//cout << c << endl;

		if (c >= '0' && c <= '9') 
			output.Enqueue(c);
		else if (c == '(') 
			s.Push(c);
		else if (c == ')')
		{
			while (s.Top() != '(')
			{
				output.Enqueue(s.Top());
				s.Pop();
			}
			s.Pop(); 
		}
		else 
		{
			while (!s.IsEmpty() && Prec(c) <= Prec(s.Top()))
			{
				output.Enqueue(s.Top());
				s.Pop();
			}

			s.Push(c);
		}

		//cout << "Stack: ";
		//s.Print();
		//cout << "Output:";
		//output.Print();
		//cout << endl;
	}

	while (!s.IsEmpty())
	{
		output.Enqueue(s.Top());
		s.Pop();
	}
}

int EvalPostfix(Queue<char>& q)
{
	Stack<int> s;

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		//cout << c << endl;

		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			s.Push(c - '0'); 
		}
		else
		{
			//cout << "Operator: " << c << endl;

			int op2 = s.Top();
			s.Pop();
			int op1 = s.Top();
			s.Pop();

			if (c == '+') {
				s.Push(op1 + op2);
			}
			else if (c == '-') {
				s.Push(op1 - op2);
			}
			else if (c == '*') {
				s.Push(op1 * op2);
			}
			else if (c == '/')
			{
				s.Push(op1 / op2);
			}
			else
			{
				cout << "Wrong operator" << endl;
				exit(-1); 
			}
		}

		//cout << "Stack: ";
		//s.Print();
	}

	return s.Top();
}
