#include <iostream>
#include <map>
using namespace std;

struct Node {
    int val;
    int index;
    Node *next;

    Node(int val) {
        this->val = val;
        this->index = 0;
        this->next = NULL;
    } 
};

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}



int main () {
int n; cin >>n;
Node *head;
Node *cur;
for (int i = 1; i <= n; i++) {
    int val;cin >>val;
    if (i == 1) {
        head = new Node(val);
        cur = head;
    } else if (i % 2 == 0) {
        continue;
    } else {
        cur -> next = new Node(val);
        cur = cur -> next;
    }
}

print (head);


}