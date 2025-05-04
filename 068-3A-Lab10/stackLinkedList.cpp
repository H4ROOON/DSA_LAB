#include <iostream>
using namespace std;

class Node
{
public:
	Node *next;
	int data;

	Node(int d)
	{
		data = d;
		next = nullptr;
	}
};

class Stack
{
public:
	Node *top;
	Stack()
	{
		top = nullptr;
	}

	void push(int d)
	{
		Node *newNode = new Node(d);
		newNode->next = top;
		top = newNode;
	}

	void pop()
	{
		Node *temp = top;
		top = top->next;
		delete temp;
	}
	void display()
	{
		Node *temp = top;
		while (temp != nullptr)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}
};
int main()
{

	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	s.pop();
	cout << "\nAfter deleting!\n";
	s.display();
}