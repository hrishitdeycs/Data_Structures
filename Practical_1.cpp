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
    // i. Insert at beginning
    void insertAtHead(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }
    // ii. Insert at i-th position (1-based index)
    void insertAtPosition(int x, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            insertAtHead(x);
            return;
        }
        Node* temp = head;
        int i = 1;
        // Use while loop instead of for
        while (i < pos - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) {
            cout << "Position out of range!\n";
            return;
        }
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }
    // iii. Remove from beginning
    void removeAtHead() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // iv. Remove from i-th position (1-based index)
    void removeAtPosition(int pos) {
        if (pos < 1 || head == nullptr) {
            cout << "Invalid position or empty list!\n";
            return;
        }
        if (pos == 1) {
            removeAtHead();
            return;
        }
        Node* temp = head;
        int i = 1;
        // Again, use while loop instead of for
        while (i < pos - 1 && temp->next != nullptr) {
            temp = temp->next;
            i++;
        }
        if (temp->next == nullptr) {
            cout << "Position out of range!\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    // v. Search for an element x
    Node* search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    SinglyLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtPosition(15, 2);
    list.display();
    list.removeAtHead();
    list.display();
    list.removeAtPosition(2);
    list.display();
    int x;
    cout << "Enter value to search: ";
    cin >> x;
    Node* found = list.search(x);
    if (found)
        cout << "Element found at address: " << found << "\n";
    else
        cout << "Element not found.\n";
    return 0;
}
