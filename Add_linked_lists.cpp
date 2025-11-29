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

    Node* getHead() {
        return head;
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
};

SinglyLinkedList addTwoLists(SinglyLinkedList& L1, SinglyLinkedList& L2) {
    Node* p = L1.getHead();
    Node* q = L2.getHead();

    SinglyLinkedList result;
    int carry = 0;

    while (p != nullptr || q != nullptr || carry != 0) {
        int x = (p != nullptr) ? p->data : 0;
        int y = (q != nullptr) ? q->data : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        result.insertAtHead(sum % 10);

        if (p) p = p->next;
        if (q) q = q->next;
    }

    // List is reversed — fix by reversing again
    SinglyLinkedList finalList;
    Node* temp = result.getHead();
    while (temp != nullptr) {
        finalList.insertAtHead(temp->data);
        temp = temp->next;
    }

    return finalList;
}

int main() {
    SinglyLinkedList L1, L2;

    L1.insertAtHead(3);
    L1.insertAtHead(4);
    L1.insertAtHead(2);

    L2.insertAtHead(4);
    L2.insertAtHead(6);
    L2.insertAtHead(5);

    cout << "List 1: ";
    L1.display();

    cout << "List 2: ";
    L2.display();

    SinglyLinkedList sum = addTwoLists(L1, L2);

    cout << "Sum:   ";
    sum.display();

    return 0;
}
