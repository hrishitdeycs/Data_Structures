#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};
// Function to get height of a node
int height(Node* node) {
    return node ? node->height : 0;
}
// Function to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}
// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
// Get balance factor
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Normal BST insertion
    if (!node)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;
    // Update height
    node->height = 1 + max(height(node->left), height(node->right));
    // Check balance
    int balance = getBalance(node);
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// Search a key in the AVL tree
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}
// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;
    int key;
    cout<<"Enter key to search: ";  
    cin >> key;
    if (search(root, key))
        cout << key << " found in AVL tree." << endl;
    else
        cout << key << " not found in AVL tree." << endl;
    return 0;
}
