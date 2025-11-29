#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtHead(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;   // store next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        head = prev; // new head
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);

    cout << "Original List:\n";
    list.display();

    list.reverse();

    cout << "Reversed List:\n";
    list.display();

    return 0;
}
