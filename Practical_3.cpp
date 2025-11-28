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
class CircularLinkedList {
private:
    Node* tail;  // We maintain a tail pointer for easier circular operations
public:
    CircularLinkedList() {
        tail = nullptr;
    }
    void insert(int x) {
        Node* n = new Node(x);
        if (tail == nullptr) {
            n->next = n;
            tail = n;
        } else {
            n->next = tail->next;  // New node points to head
            tail->next = n;
            tail = n;  // Update tail to new node
        }
    }
    void remove(int x) {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* curr = tail->next; // Start from head
        Node* prev = tail;
        do {
            if (curr->data == x) {
                if (curr == tail && curr->next == tail) {
                    // Only one node
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev; // Update tail if needed
                    delete curr;
                }
                cout << x << " removed from the list.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Element " << x << " not found.\n";
    }
    Node* search(int x) {
        if (tail == nullptr) return nullptr;
        Node* curr = tail->next; // Start from head
        do {
            if (curr->data == x) return curr;
            curr = curr->next;
        } while (curr != tail->next);
        return nullptr;
    }
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* curr = tail->next; // Start from head
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << "(head)\n";
    }
};
int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
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
