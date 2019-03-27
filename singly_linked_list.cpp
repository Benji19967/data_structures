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
    
}
