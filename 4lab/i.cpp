#include <iostream>
using namespace std;

struct Tree {
    int val;
    Tree *left;
    Tree *right;
    int duplicate;
    Tree (int key) {
        this -> val = key;
        this -> left = NULL;
        this -> right = NULL;
        this -> duplicate = 1;
    }
};

// void add(Tree * root, int key) {
//     if (root == NULL) {
//         root = new Tree(key);
//         return;
//     }
//     if (root -> val == key) {
//         root -> duplicate++; 
//     }

//     if (root ->val > key) {
//         add(root -> left, key);
//     }
//     else {
//         add(root -> right, key);
//     }
// }

Tree* add(Tree* root, int key) {
	if (root == NULL) {
		return new Tree(key);
	} else if(root->val == key) {
        root->duplicate++;
    }
    else if (root->val > key) {
		if (root->left == NULL) {
			root->left = new Tree(key);
		} else {
			root->left = add(root->left, key);
		}
	} else if (root->val < key) {
		if (root->right == NULL) {
			root->right = new Tree(key);
		} else {
			root->right = add(root->right, key);
		}
	} 
	return root;
}
Tree* getMin(Tree* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Tree* find (Tree * root, int key) {
	if (root == NULL) {
		return NULL;
	} else if (root->val == key) {
		return root;
	} else if (root->val < key) {
		return find(root->right, key);
	} else {
		return find(root->left, key);
	}
}

Tree *remove(Tree * root, int key) {
    if (root == NULL) {
        return NULL; 
    }
    else if (root ->val > key) {
        root -> left = remove(root -> left, key);
        return root;
    }
    else if (root -> val < key) {
        root -> right = remove(root -> right, key);
        return root;
    }
    else if (root -> val == key) {
        if (root -> duplicate == 0)  {
            if (root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            } else if (root -> right == NULL) {
                Tree* temp = root->left;
                delete root;
                return temp;
            } else if (root -> left == NULL) {
                Tree* temp = root->right;
                delete root;
                return temp;      
            } else {
                Tree* temp = getMin(root->right);
                root->val = temp->val;
                root->right = remove(root->right, temp->val);
                return root;
            }
        }  
        else root->duplicate--;
        return root;
    }
    return NULL;
}

void solution (Tree* &root, int val, string s) {
    if (s == "insert") {
        root = add(root, val);
    } else if (s == "delete") {
        root = remove(root, val);
    } else if (s == "cnt") {
        Tree *finded = find(root, val);
        if (finded == NULL) cout << 0 << "\n";
        else cout << finded->duplicate << "\n";
    }

}

int main () {
    int n;
    cin >> n;
    Tree *root = NULL;

    for (int i = 0; i < n; i++) {
        string s;
        int key;
        cin >> s >> key;

        solution(root, key, s);
    }
}