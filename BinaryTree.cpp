#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) { data = value; left = right = NULL; }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = NULL; }

    void insert(int data) {
        root = insertRec(root, data);
    }

    Node* insertRec(Node* node, int data) {
        if (node == NULL) return new Node(data);
        if (data < node->data) node->left = insertRec(node->left, data);
        else node->right = insertRec(node->right, data);
        return node;
    }

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    Node* search(int data) {
        return searchRec(root, data);
    }

    Node* searchRec(Node* node, int data) {
        if (node == NULL || node->data == data) return node;
        if (data < node->data) return searchRec(node->left, data);
        return searchRec(node->right, data);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    void deleteNode(int data) {
        root = deleteRec(root, data);
    }

    Node* deleteRec(Node* node, int data) {
        if (node == NULL) return node;
        if (data < node->data) node->left = deleteRec(node->left, data);
        else if (data > node->data) node->right = deleteRec(node->right, data);
        else {
            if (node->left == NULL) return node->right;
            if (node->right == NULL) return node->left;
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }
};

int main() {
    BinaryTree tree;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : values) tree.insert(val);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    int searchValue = 40;
    if (tree.search(searchValue)) cout << "Node " << searchValue << " found in the tree." << endl;
    else cout << "Node " << searchValue << " not found in the tree." << endl;

    tree.deleteNode(20);
    cout << "In-order traversal after deleting 20: ";
    tree.inOrder(tree.root);
    cout << endl;
    
    return 0;
}
