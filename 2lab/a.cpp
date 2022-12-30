#include <iostream>
#include <map>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int newVal) {
        this->val = newVal;
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

void nearestNumber(Node* head, int nearest) {
    Node* cur = head;
    int otvet= 0;
    int index = 0;

    int min = abs(nearest - head->val);
    while (cur != NULL) {

        if (min > abs(nearest - cur->val)) {
            min = abs(nearest - cur->val);
            otvet = index;
        }
        cur = cur->next;
        index++;
    }
    cout << otvet << endl;
}


int main () {
    int n; cin >>n;
    Node *head;
    Node *cur;
    Node *a;
    for (int i = 0; i < n; i++) {
        int val;cin >>val;
        if (i == 0) {
            head = new Node(val);
            cur = head;
        } else {
            a = new Node(val);
            cur -> next = a;
            cur = cur -> next;
        }
    }

    int nearest; cin >> nearest;

    nearestNumber(head, nearest);

}