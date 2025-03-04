#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class linkedList  {
public:
    Node* head;
    Node* tail;

    linkedList () {
        head = NULL;
        tail = NULL;
    }

    void insertLast(string data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void mergeList(linkedList & list2) {
        if (head == NULL) {
            head = list2.head;
            tail = list2.tail;
            return;
        }
        if (list2.head == NULL) return;

        tail->next = list2.head;
        list2.head->prev = tail;
        tail = list2.tail;
    }
};

int main() {
    linkedList l1, l2;

    l1.insertLast("Haroon");
    l1.insertLast("David");
    l1.insertLast("Hamd");

    l2.insertLast("Mubeen");
    l2.insertLast("Mira");

    cout << "List 1: ";
    l1.printList();

    cout << "List 2: ";
    l2.printList();

    l1.mergeList(l2);
    cout << "Merged List: ";
    l1.printList();

    return 0;
}
