#include <iostream>

using namespace std;


struct Tree {
    int val;
    Tree *left;
    Tree *right;
    Tree(int key) {
        this->val = key;
        this->left = NULL;
        this-> right = NULL;
    }
};

void insert(Tree * &root, int key) {
    if (root == NULL) {
        root = new Tree(key);
        return;
    }
    if (root ->val > key) {
        insert(root -> left, key);
    }
    else {
        insert(root -> right, key);
    }
}

// Tree* bstToGst(Tree* root) {
//     int acc_sum = 0;
//     sum_node(root, acc_sum);
//     return root;
// }

void sum_node(Tree* node, int& acc_sum){
    if (node == NULL)  return;
    sum_node(node->right,acc_sum);
    node->val += acc_sum;
    acc_sum = node->val;

    cout << acc_sum << " ";
    
    sum_node(node->left, acc_sum);
}


int main() {
    int n; cin >> n;
    Tree* root = NULL;
    int acc_sum = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        insert(root, x);
    }
    sum_node(root, acc_sum);
}

