#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};
 

Node* insert(Node* root, int key) {
    if (root == NULL) 
    {
        root = newNode(key);
        return;
    }
    else if (root -> data > key) 
    {
        insert(root -> left, key);
    }
    else 
    {
        insert(root -> right, key);
    }
    return root;
}

/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
    // Base case
    if (root==NULL)
        return;
 
    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
 
/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
 
    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 

int main()
{
    Node root ;
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        insert(root, x);
    }

    root = buildTree(root);
 
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);
 
    return 0;
}