#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    } 
};

void Insert(Node *head, int val, int pos) {
    Node *curr = head;
    Node *NewNode = new Node(val);
    int i = 0;

    while (curr != NULL) {
        if (pos == 0) {
            NewNode->next = head;
            head = NewNode;
            break;
        }
        else if (pos - 1 == i) {
            NewNode->next = curr -> next;
            curr -> next = NewNode;
            break;
        }
        curr = curr->next;
        i++;
    }
}






int main () {
    int a;
    cin >> a;
    Node *head;
    Node *cur;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            head = new Node(x);
            cur = head;
        } else {
            cur -> next = new Node(x);
            cur = cur -> next;
        }
    }
}