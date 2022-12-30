#include <iostream>

using namespace std;
int sum[5000];
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
    if (root == NULL) {
        root = new Node(key);
        return;
    }

    if (root -> key > key) {
        insert(root -> left, key);
    }

    else {
        insert(root -> right, key);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
 
int getHeight(Node* root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);
 
    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);
 
    return (max(left, right) + 1);
}

void LevelSum(Node *root, int level,int sum[]){
    if (root == NULL) return ;

    sum[level] += root->key;
    LevelSum(root->left, level + 1, sum);
    LevelSum(root->right, level + 1, sum);
}

int height (Node* root) {
    if (root == NULL) return 0;

    else {
        int left_height = height(root -> left);
        int right_height = height(root -> right);
        return 1 + max(left_height, right_height);
    }
}

int main() {
    Node *root = new Node();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        insert(root, k);
    }
    
    int level = getHeight(root);

    // LevelSum(root, 0, sum);
    cout << getHeight(root)<<'\n';
    LevelSum(root, 0, sum);
    for (int i = 1; i <= level; i++) {
        cout << sum[i] << '\n';
    }
}