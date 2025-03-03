#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node *prev;
	Node *next;

	Node(string data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

class doublyLinkedList
{
public:
	Node *head;
	Node *tail;

	doublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertFront(string data)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void insertLast(string data)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void insertNth(int position, string data)
	{
		Node *newNode = new Node(data);
		if (position == 1)
		{
			insertFront(data);
			return;
		}

		Node *temp = head;
		for (int i = 1; i < position - 1 && temp != NULL; i++)
		{
			temp = temp->next;
		}

		if (temp == NULL)
		{
			cout << "Invalid position!\n";
			return;
		}

		newNode->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

	void print()
	{
		Node *temp = head;
		cout << "Doubly linked list: ";
		while (temp != NULL)
		{
			cout << temp->data << " <-> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main()
{
	doublyLinkedList list;

	list.insertFront("Haroon");
	list.insertFront("David");
	list.insertLast("Mubeen");
	list.insertNth(2, "Mira");

	list.print();

	return 0;
}
