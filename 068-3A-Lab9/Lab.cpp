#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

class circularList  {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }


    void insertFront(string data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode; 
        }
    }


    void insertLast(string data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }


    void insertNth(int position, string data) {
        if (position == 1 || head == NULL) {
            insertFront(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head) {
            insertLast(data);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Null" << endl;
    }

    void displayCenter() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != head && fast->next != head);

        cout << "Center Node: " << slow->data << endl;
    }
    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        Node* curr = head;

        do {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } while (curr != head);

        head->next = prev;
        head = prev;

        cout << "Reversed List: ";
        temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Null" << endl;
    }
};

int main() {
    circularList list;

    list.insertFront("Haroon");
    list.insertLast("David");
    list.insertNth(2, "Mira");
    list.insertLast("Mubeen");

    list.display();
    list.displayCenter();
    list.displayReverse();

    return 0;
}