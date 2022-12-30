#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;

    Node* insert(Node* cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if (cur -> val > val) {
            cur -> left = insert(cur -> left, val);
        }
        if (cur -> val < val) {
            cur -> right = insert(cur -> right, val);
        }
        return cur;
    }

    void height(Node * cur) {
        Node * temp = cur;
        int l = 0, r = 0;
        while(temp != NULL) {
            temp = temp -> left;
            l++;
        }

        temp = cur;
        while(temp != NULL) {
            temp = temp -> right;
            r++;
        } 

        for(int i = 1; i <= min(l, r); ++i) {
            mp[i]++;
        }
    }

    void count_height(Node * current) {
        if(current != NULL) {
            count_height(current->left);
            count_height(current->right);
            height(current);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }  

    void count_height(){
        return count_height(root);
    }
   
};

int main(){
    int n;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.count_height();
    for(int i = 2; i <= n; ++i) {
        cout << mp[i] << " ";
    }
}