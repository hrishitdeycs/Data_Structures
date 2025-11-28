#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class BST {
private:
    Node* root;
    Node* createNode(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    Node* insertNode(Node* node, int x) {
        if (node == nullptr)
            return createNode(x);
        if (x < node->data)
            node->left = insertNode(node->left, x);
        else if (x > node->data)
            node->right = insertNode(node->right, x);
        return node; // Ignore duplicates
    }
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }
    Node* deleteNode(Node* node, int x) {
        if (!node) return node;
        if (x < node->data)
            node->left = deleteNode(node->left, x);
        else if (x > node->data)
            node->right = deleteNode(node->right, x);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    bool searchNode(Node* node, int x) {
        if (!node) return false;
        if (x == node->data) return true;
        if (x < node->data) return searchNode(node->left, x);
        return searchNode(node->right, x);
    }
    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
    void preorderTraversal(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
    void postorderTraversal(Node* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
public:
    BST() { root = nullptr; }
    void insert(int x) { root = insertNode(root, x); }
    void remove(int x) { root = deleteNode(root, x); }
    bool search(int x) { return searchNode(root, x); }
    void displayInorder() { inorderTraversal(root); cout << endl; }
    void displayPreorder() { preorderTraversal(root); cout << endl; }
    void displayPostorder() { postorderTraversal(root); cout << endl; }
};
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    cout << "Inorder traversal: ";
    bst.displayInorder();      // Should display 20 30 40 50 60 70 80
    cout << "Preorder traversal: ";
    bst.displayPreorder();     // Should display 50 30 20 40 70 60 80
    cout << "Postorder traversal: ";
    bst.displayPostorder();    // Should display 20 40 30 60 80 70 50
    cout << "Searching 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;
    bst.remove(20); // Leaf node
    bst.remove(30); // Node with one child
    bst.remove(50); // Node with two children
    cout << "Inorder traversal after deletions: ";
    bst.displayInorder();      
    return 0;
}
