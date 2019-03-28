#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
	public:
        Node* head;
        Node* tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
};

int main() {
    SinglyLinkedList* l = new SinglyLinkedList();

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    cout << n1->next->next->data; // prints 3

}
