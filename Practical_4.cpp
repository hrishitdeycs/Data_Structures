#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
// Stack ADT using linked list
class Stack {
private:
    Node* head;
    int count;
public:
    Stack() {
        head = nullptr;
        count = 0;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }
    int pop() {
        if (empty()) {
            cerr << "Stack Underflow\n";
            exit(1);
        }
        int value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }
    int top() {
        if (empty()) {
            cerr << "Stack is empty\n";
            exit(1);
        }
        return head->data;
    }
    bool empty() {
        return head == nullptr;
    }
    int size() {
        return count;
    }
};
// Utility function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int evaluatePostfix(const string& expr) {
    Stack s;
    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int b = s.pop();
            int a = s.pop();
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}
int evaluatePrefix(const string& expr) {
    Stack s;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int a = s.pop();
            int b = s.pop();
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}
int main() {
    string postfixExpr = "231*+9-"; 
    string prefixExpr = "-+2*319"; 
    cout << "Postfix Result: " << evaluatePostfix(postfixExpr) << endl;
    cout << "Prefix Result: " << evaluatePrefix(prefixExpr) << endl;
    return 0;
}
