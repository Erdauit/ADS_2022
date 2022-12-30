#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node * cur = head;
    Node * prev = head;
    while(cur != NULL){
        if(cur->data == prev-> data){
            prev->next = cur->next;
        }
        else{
            prev->next = cur;
            prev = prev->next;
        }
        cur = cur->next;
    }
}  

int getCount(Node* head)  
{  
    Node * cur = head;
    int count = 0; 
    while(cur != NULL){
        count++;
        cur = cur->next;
    }

    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}