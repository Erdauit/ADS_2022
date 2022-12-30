#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* &root, int data) {
    if (root == NULL) root = getNewNode(data);
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else root->right = Insert(root->right, data);
}

int main() {
    Node* root = NULL;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = Insert(root, x);
    }

    while (m--) {
        string s; cin >> s;
        bool go = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                root = root->left;
                if (root == NULL) {
                    cout << "NO\n";
                    go = false;
                    break;
            }
            }
            else if (s[i] == 'R') {
                root = root->right;
                if (root == NULL) {
                    cout << "NO\n";
                    go = false;
                    break;
            }
        }
        if (go) {
            cout << "YES\n";
        }

    }
}
}