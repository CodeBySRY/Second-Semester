#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data) {
        this->data = data;
    }
};

class LinkedList {
    Node* head;

    public:
    void insertAtHead(int data) {
        Node* newNode = new Node(data);

        if(head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void print() {
        Node* curr;
        while(curr!=nullptr) {
            cout << curr->data;
            if(curr->next != nullptr) {
                cout << "-> ";
            }
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(5);
    list.insertAtHead(10);
    list.insertAtHead(15);
    list.insertAtHead(20);
    list.insertAtHead(25);

    list.print();

    return 0;
}