#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    bool searchNonRecursive(int key) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            } else if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    bool searchRecursive(int key) {
        return searchRec(root, key);
    }

    bool searchRec(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        } else if (key < node->data) {
            return searchRec(node->left, key);
        } else {
            return searchRec(node->right, key);
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    int key = 7;
    std::cout << "Searching for " << key << " non-recursively: "
              << (bst.searchNonRecursive(key) ? "Found" : "Not Found") << std::endl;

    key = 20;
    std::cout << "Searching for " << key << " recursively: "
              << (bst.searchRecursive(key) ? "Found" : "Not Found") << std::endl;

    return 0;
}
