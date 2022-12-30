#include <iostream> 

using namespace std;

struct Node {
    int val;
    Node * next;
    Node (int val) {
        this -> val = val;
        this -> next = NULL;
    }
};



int main() {
    int n;
    cin >> n;
    Node * head;
    Node * cur;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if(i == 0) {
            head = new Node(c);
            cur = head;
        }
        else {
            cur -> next = new Node(c);
            cur = cur -> next;
        }
    }
}