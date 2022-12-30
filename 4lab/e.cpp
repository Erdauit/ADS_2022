#include <iostream>
using namespace std;

struct Tree {
    int key;
    Tree *left;
    Tree *right;
    Tree (int val) {
        this->key = val;
        this->left = NULL;
        this->right = NULL;
    }

};

void insert(Tree* &root, int key, int direction) {
    if (root == NULL) 
    {
        root = new Tree(key);
        return;
    }
    else if (direction == 0) 
    {
        root-> left = new Tree(key);
    }
    else if (direction == 1) 
    {
        root->right = new Tree(key);
    }
}

Tree* search (Tree* cur, int key, key2, int direction) {
    Tree *target;
    if(cur != NULL){
        if(cur->key == key){
            target = cur;
            if (direction == 0) 
            {
                root-> left = new Tree(key2);
            }
            else if (direction == 1) 
            {
                root->right = new Tree(key2);
            }
        }
        search(cur->left, key);
        search(cur->right, key);
    }
    return target;
}

int getWidth(Tree * cur, int level){
    if(cur == NULL){
        return 0;
    }
    if(level == 1){
        return 1;
    }
    else if(level > 1){
        return getWidth(cur->left, level - 1) + getWidth(cur->right, level - 1);
    }
    return 0;
}

void push (Tree* &root, int x, int key, int direction) {
    Tree *cur = search(root, x);
    insert(cur, key, direction);
}

int height(Tree * cur){
    if(cur == NULL){
        return 0;
    }
    else
        return 1 + max(height(cur->left), height(cur->right));
}

int answer (Tree *root) {
    int maxWidth = 0;
    int curWidth = 0;
    for (int i = 1; i < height(root); i++) {
        curWidth = getWidth(root, i);
        if (curWidth > maxWidth) {
            maxWidth = curWidth;
        }
    }
    return maxWidth;
}


int main () {
    Tree *root = new Tree(1);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, key, direction;
        cin >> x >> key >> direction;
        push(root, x, key, direction);
    }

    cout << answer(root);


}