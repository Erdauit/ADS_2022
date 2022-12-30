#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *left, *right;
    Node(int value)
    {
        this -> value = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};

struct BST
{
    Node *root;
    BST()
    {
        root = NULL;
    }

public:
    void push(Node *&root, int val)
    {
        if (root == NULL)
            root = new Node(val);
        if (val < root->value)
            push(root->left, val);
        if (val > root->value)
            push(root->right, val);
    }

    // void insert(int value)
    // {
    //     root = push(root, value);
    // }

    int height(Node *cur, int &d)
    {
        if (cur == NULL)
            return 0;
        int left = height(cur->left, d);
        int right = height(cur->right, d);
        d = max(d, right + left + 1);
        return max(left, right) + 1;
    }

    int findMaxDistance()
    {
        int d = 0;
        height(root, d);
        return d;
    }
};

int main()
{
    BST tree;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tree.push(tree.root, x);
    }
    cout << tree.findMaxDistance();
}