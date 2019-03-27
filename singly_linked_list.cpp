#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int node_data) {
            this->data = node_data;
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
