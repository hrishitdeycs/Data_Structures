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
        Node* newNode = new Node(value);
        if (rear == nullptr) { // empty queue
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    int dequeue() {
        if (front == nullptr) {
            cerr << "Queue Underflow\n";
            exit(1);
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // queue became empty
            rear = nullptr;
        }
        delete temp;
        count--;
        return value;
    }
    int Front() { // function to access front element
        if (front == nullptr) {
            cerr << "Queue is empty\n";
            exit(1);
        }
        return front->data;
    }
    bool empty() {
        return front == nullptr;
    }
    int size() {
        return count;
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.Front() << endl; 
    q.dequeue();
    cout << "Front after dequeue: " << q.Front() << endl; 
    return 0;
}
