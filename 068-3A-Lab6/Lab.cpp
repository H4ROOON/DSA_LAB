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

	void insertNth(int position, string data)
	{
		Node *newNode = new Node(data);

		if (position == 1)
		{
			newNode->next = head;
			head = newNode;
			return;
		}

		Node *temp = head;
		for (int i = 1; i < position - 1 && temp != nullptr; i++)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			cout << "Invalid position!\n";
			return;
		}

		newNode->next = temp->next;
		temp->next = newNode;
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

	void deleteFirst()
	{
		if (head != NULL)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
			cout << "First Node has been deleted!\n";
		}
	}

	void deleteEnd()
	{
		if (head == NULL)
		{
			cout << "List is empty!\n";
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			cout << "Last node has been deleted!\n";
			return;
		}

		Node *temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		cout << "End node has been deleted!\n";
	}

	void deleteNth(int position)
	{
		if (head == NULL)
		{
			cout << "List is empty!\n";
			return;
		}

		if (position == 1)
		{
			deleteFirst();
			return;
		}

		Node *temp = head;
		for (int i = 1; i < position - 1 && temp->next != NULL; i++)
		{
			temp = temp->next;
		}

		if (temp->next == NULL)
		{
			cout << "Invalid position!\n";
			return;
		}

		Node *delNode = temp->next;
		temp->next = delNode->next;
		delete delNode;
		cout << "Node at position " << position << " deleted!\n";
	}
};

int main()
{
	linkedList list;
	list.insertFront("Haroon ");
	list.insertFront("David ");
	list.insertFront("Mubeen ");
	list.insertLast("Last ");
	cout << "Printing Linked List: ";
	list.printList();

	list.deleteFirst();
	list.printList();

	list.deleteEnd();
	list.printList();

	list.deleteNth(2);
	list.printList();

	return 0;
}
