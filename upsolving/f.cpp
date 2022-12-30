#include <iostream> 
using namespace std;


int sum;
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
void LevelSum(Bst *root, int level){
    if (root == NULL) return ;

    sum += (root->val - level);
    LevelSum(root->left, level + 1);
    LevelSum(root->right, level + 1);
}

int main() {
    int n; cin >> n;
    Bst * root = NULL;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        insert(root, c);
    }

    int level = height(root);
    LevelSum(root, 0);
    cout << sum;
}