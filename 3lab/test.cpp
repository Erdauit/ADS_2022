#include <iostream>

using namespace std;

struct Node 
{
    public:
        int key;
        int data;
        Node* next;

        Node() {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d) {
            key = k;
            data = d;
        }
};
struct SinglyLinkedList 
{
    public:
        Node* head;

        SinglyLinkedList() 
        {
            head = NULL;
        }
        SinglyLinkedList(Node *n)
        {
            head = n;
        }

        Node* nodeExists(int k)
        {
            Node* temp = NULL;

            Node* ptr = head;
            while(ptr != NULL)
            {
                if (ptr -> key == k)
                    temp = ptr;
                ptr = ptr -> next;
            }
            return temp;
        }

        void appendNode(Node *n)
        {
            if (nodeExists(n -> key) != NULL)
            {
                return; 
            }
            else 
            {
                Node* ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                } 
            }
        }
        
        void deleteNodeByKey(int k) 
        {
            if (head == NULL)
            {
                return;
            }
            else if (head != NULL)
            {
                if (head -> key == k)
                {
                    head = head -> next;
                }
                else 
                {
                    Node* temp = NULL;
                    Node* prev = head;
                    Node* curr = head -> next;

                    while(curr != NULL)
                    {
                        if (curr -> key == k)
                        {
                            temp = curr;
                            curr = NULL;
                        }
                        else 
                        {
                            prev = prev -> next;
                            curr = curr -> next;
                        }
                    }
                    if (temp != NULL)
                    {
                        prev -> next = temp -> next;
                    }
                    else 
                    {
                        return;
                    }
                }
            }
        }
};

int main()
{

    SinglyLinkedList s;
    
      
    return 0;
}