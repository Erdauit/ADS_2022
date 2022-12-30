#include <iostream>

using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node () {
        left = NULL;
        right = NULL;
    }
    Node (int key) {
        this->key = key;
    }
};

void insert(Node* &root, int key) {
    if (root == NULL) 
    {
        root = new Node(key);
        return;
    }

    if (root -> key > key) 
    {
        insert(root -> left, key);
    }

    else 
    {
        insert(root -> right, key);
    }
}

int size (Node* root) {
    if (root == NULL) return 0;

    return 1 + size(root -> left) + size(root -> right);

}

Node* search (Node* root, int key) {
    if (root -> key == key) {
        return root;
    }
    else if (root -> key > key) {
        return search(root -> left, key);
    }
    else {
        return search(root -> right, key);
    }
}

void print (Node* root) {
    if (root == NULL) return;
    cout << root -> key << " ";
    print (root -> left);
    print (root -> right);
}

int main () {
    Node *root = new Node();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }

    int k; cin >> k;
    search(root, k);
    Node* head = search(root, k);
    print (head);

}