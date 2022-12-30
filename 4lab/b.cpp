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

int size (Node* root) {
    if (root == NULL) return 0;

    return 1 + size(root -> left) + size(root -> right);

}

int height (Node* root) {
    if (root == NULL) return -1;

    else {
        int left_height = height(root -> left);
        int right_height = height(root -> right);
        return 1 + max(left_height, right_height);
    }
}



void search (Node* root, int key) {
    if (root -> key == key) {
        cout << size(root) <<"\n";
    }
    else if (root -> key > key) {
        search(root -> left, key);
    }
    else {
        search(root -> right, key);
    }
}


int main () {
    Node *root = new Node();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }

    cout << height(root);
}
