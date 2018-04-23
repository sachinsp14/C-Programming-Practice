#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
Node* head;
bool removeDuplicate(Node*, Node *);

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairwiseSwap(Node* head)
{
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}
 
/* Push a node to linked list. Note that this function
  changes the head */
Node* push(Node* head, int new_data)
{
    Node* temp = new Node();
    temp->data = new_data;
    temp->next = NULL;
    
    temp->next = head;
    head = temp;
}
 
// A utility function to print a given linked list
void printList(Node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    head = NULL;
 
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 6);
    
    cout<<"Initial List"<<endl;
    printList(head);
    pairwiseSwap(head);
    cout<<"Updated List"<<endl;
    printList(head);
    return 0;
}