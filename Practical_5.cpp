#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Queue {
private:
    Node* front; 
    Node* rear;  
    int count;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    void enqueue(int value) {
        Node* n = new Node(value);
        if (rear == nullptr) { // empty queue
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        count++;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // queue became empty
            rear = nullptr;
        }
        delete temp;
        count--;
    }
    int Front() { // function to access front element
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    bool empty() {
        return front == nullptr;
    }
    int size() {
        return count;
    }
    void Display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    cout << "Front: " << q.Front() << endl; 
    q.dequeue();
    q.Display();
    cout << "Front after dequeue: " << q.Front() << endl; 
    return 0;
}
