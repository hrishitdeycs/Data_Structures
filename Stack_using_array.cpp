 #include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Array to hold stack elements
    int capacity;  // Maximum capacity of the stack
    int top;       // Index of the top element

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; // Stack initially empty
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop the top element
    void pop() {
        if (empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Get the top element
    int Top() const { // Use Top() to avoid conflict with variable 'top'
        if (empty()) {
            cout << "Stack is empty\n";
            return -1; // or some error value
        }
        return arr[top];
    }

    // Return the current size
    int size() const {
        return top + 1;
    }

    // Check if stack is empty
    bool empty() const {
        return top == -1;
    }
};

// Example usage
int main() {
    Stack s(5); // Stack with capacity 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.Top() << endl; // 30
    cout << "Stack size: " << s.size() << endl; // 3

    s.pop();
    cout << "Top element after pop: " << s.Top() << endl; // 20
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // No

    return 0;
}
