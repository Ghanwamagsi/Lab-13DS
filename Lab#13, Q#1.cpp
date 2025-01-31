#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(Node* root) {
    if (root == nullptr) 
        return;

    std::cout << root->data << " "; 
    preOrderTraversal(root->left);   
    preOrderTraversal(root->right);  
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}


