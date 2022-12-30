#include <iostream>

using namespace std;

struct Tree {
    int val;
    Tree *left;
    Tree *right;
    Tree(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Tree * &root, int val) {
    if (root == NULL) {
        root = new Tree(val);
        return;
    }

    if (root->val > val) {
        insert(root -> left, val);
    }
    if (root->val < val) {
        insert(root -> right, val);
    }
}

void Check(Tree * root, int val) {
    if (root == NULL) {
        cout << "NULL";
        return;
    }
    if (root -> val == val) {
        cout << "Finded";
        return;
    }
    else if (root -> val > val) {
        Check(root -> left, val);
    }
    else if (root -> val < val) {
        Check(root -> right, val);
    }
    
}

int height (Tree * root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int left = height(root -> left);
        int right = height(root -> right);
        return 1 + max(left, right);
    }
}

int size (Tree * root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size(root -> left) + size(root -> right);
}



int main() {
    int n;
    cin >> n;
    Tree * root = NULL;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        insert(root, c);
    }
    int target; cin >> target;
    Check(root, target);
}