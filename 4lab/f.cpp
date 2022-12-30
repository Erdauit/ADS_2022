#include <iostream>

int cnt = 0;

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
        left = NULL;
        right = NULL;
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

void check(Node* root) {
    if (root == NULL) return;
    if (root -> left != NULL && root -> right != NULL) cnt++;
    check(root -> left);
    check(root -> right);
}


int main () {
    Node *root = new Node();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }

    check(root);
    cout << cnt;
}