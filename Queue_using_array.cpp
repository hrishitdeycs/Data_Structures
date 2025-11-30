#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Array to store queue elements
    int capacity;  // Maximum capacity
    int front;     // Index of the front element
    int rear;      // Index of the last element
    int count;     // Current number of elements

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        count++;
    }

    // Remove the front element from the queue
    void dequeue() {
        if (empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % capacity; // Circular increment
        count--;
    }

    // Get the front element
    int Front() const { // Function name capitalized to avoid conflict with variable
        if (empty()) {
            cout << "Queue is empty\n";
            return -1; // error value
        }
        return arr[front];
    }

    // Get the current size of the queue
    int size() const {
        return count;
    }

    // Check if queue is empty
    bool empty() const {
        return count == 0;
    }
};

// Example usage
int main() {
    Queue q(5); // Queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.Front() << endl; // 10
    cout << "Queue size: " << q.size() << endl;     // 3

    q.dequeue();
    cout << "Front element after dequeue: " << q.Front() << endl; // 20
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No

    return 0;
}
