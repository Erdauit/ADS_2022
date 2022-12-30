#include <iostream> 
using namespace std;


int counter;
struct Bst {
    int val;
    Bst *right;
    Bst *left;
    Bst(int val) {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

void insert(Bst * &root, int val) {
    if (root == NULL) {
        root = new Bst(val);
        return;
    }

    if (root->val > val) {
        insert(root -> left, val);
    }
    if (root->val < val) {
        insert(root -> right, val);
    }
}

int height (Bst * root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int left = height(root -> left);
        int right = height(root -> right);
        return 1 + max(left, right);
    }
}
void answer(Bst * root) {
    if (root == NULL) {
        return;
    }
    if (root -> left == NULL && root -> right == NULL) {
        counter++;
    }
    answer(root -> left);
    answer(root -> right);
}
int main() {
    int n; cin >> n;
    Bst * root = NULL;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        insert(root, c);
    }

    int level = height(root);
    answer(root);
    cout << counter;
}