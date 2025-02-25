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
};

int main()
{




	return 0;
}