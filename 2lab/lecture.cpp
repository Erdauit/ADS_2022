#include <iostream>

using namespace std;
struct node{
    int data;
    node* next;

   node(int data){
    this->data = data;
    this->next = NULL;
   }

};

void insertLast(node* &head, int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }

    node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newnode;
    
}

int Nearest(node* head, int k){
    int mn = abs(head->data - k);
    int index = 0;
    int cnt = 0;
    node* cur = head;
    while (cur != NULL)
    {
        if (mn > abs(cur->data - k))
        {
            mn = abs(cur->data - k);
            cnt = index;
        }
        cur = cur->next;
        index++;
        
    }

    return cnt;
    
}

// void Answer(node* head, int k){
//     int x = Nearest(head, k);
//     int i = 0;
//     node* cur = head;
//     while (cur != NULL)
//     {
//         if (abs(cur->data - k) == x)
//         {
//             cout << i;
//             return;
//         }
//         cur = cur->next;
//         i++;
        
//     }
    
// }

// void display(node* head){
//     node* cur = head;
//     while (cur != NULL)
//     {
//         cout << cur->data << " ";
//         cur = cur->next;
//     }
//     cout << endl;
    
// }


int main(){
node* head = NULL;
int n;cin >> n;
for(int i = 0; i < n; i++){
    int x;cin >> x;
    insertLast(head, x);
}
int k;cin >> k;

cout << Nearest(head, k) << endl;


}