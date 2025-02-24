#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node *next;
	Node(string data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class linkedList
{
public:
	Node *head;

	linkedList()
	{
		head = nullptr;
	}

	void insertFront(string data)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}


	void insertLast(string data)
	{
		Node *newNode = new Node(data);

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void printList()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

int main()
{
linkedList list;
	list.insertFront("Haroon ");
	list.insertFront("David ");
	list.insertFront("Mubeen ");
	list.insertLast("Last list");
	cout << "Printing Linked List: ";
	list.printList();



	return 0;
}