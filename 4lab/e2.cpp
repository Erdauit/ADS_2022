#include <iostream>

using namespace std;

struct Node{
    int key;
    Node * right;
    Node * left;
    Node(int x){
        this->key = x;
        this->right = NULL;
        this->left = NULL;
    }
};

class BST{
private:
    Node * root;
    Node * target;

    void pushNode(Node * cur, int val, int direct){
        if(cur == NULL){
            cur = new Node(val);
        }else if(direct == 0){
            cur->left = new Node(val);
        }else{
            cur->right = new Node(val);
        }
        
    }

    Node * search(Node * cur, int val){
        if(cur != NULL){
            if(cur->key == val){
                target = cur;
            }
            search(cur->left, val);
            search(cur->right, val);
        }
        return target;
        
    }

    int height(Node * cur){
        if(cur == NULL){
            return 0;
        }
        else
            return max(height(cur->left), height(cur->right)) + 1;
    }

    int getWidth(Node * cur, int level){
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


    int Width(Node * cur){
        int maxWidth = 0;
        int curWidth = 0;
        int h = height(cur);
        for(int i = 1; i <= h; i++){
            curWidth = getWidth(cur, i);
            if(curWidth > maxWidth){
                maxWidth = curWidth;
            }
        }

        return maxWidth;
    }

public:
    BST(){
        root = new Node(1);
    }

    void push(int target, int val, int direct){
        Node * cur  = search(root, target);
        pushNode(cur, val, direct);
    }

    void findMaxWidth(){
        cout << Width(root);
    }

};


int main(){
    int n; cin >> n;
    BST bst;
    
    
    for(int i = 0; i < n - 1; i++){
        int x, val, direct;
        cin >> x >> val >> direct;

        bst.push(x,val,direct);
    }

    bst.findMaxWidth();

    return 0;
}