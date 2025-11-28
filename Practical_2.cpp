#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    // i. Insert at beginning
    void insertAtHead(int x) {
        Node* n = new Node(x);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    // ii. Insert at end
    void insertAtTail(int x) {
        Node* n = new Node(x);
        if (tail == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    // iii. Remove from beginning
    void removeAtHead() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        // If only one node
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    // iv. Remove from end
    void removeAtTail() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail;
        // If only one node
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    // Display forward
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(5);
    dll.display();
    dll.removeAtHead();
    dll.display();
    dll.removeAtTail();
    dll.display();
    return 0;
}
