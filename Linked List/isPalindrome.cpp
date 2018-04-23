#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
Node* head;
Node* reverse(Node*);
bool compareLists(Node*, Node *);
void printList(Node *ptr);
 
/* Function to check if given linked list is
  palindrome or not */
bool isPalindrome(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev_slow = new Node();
    Node* midnode = new Node();
    Node* second_half = new Node();
    bool res = false;
    
    if(head!=NULL)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }
        
        if(fast!=NULL)
        {
            midnode = slow;
            slow = slow->next;
        }
        second_half = slow;
        prev_slow->next = NULL;
        second_half = reverse(second_half);
        cout<<"First Half"<<endl;
        printList(head);
        cout<<"Second Half"<<endl;
        printList(second_half);
        res = compareLists(head, second_half);
        
        second_half = reverse(second_half);
        if(midnode!=NULL)
        {
            cout<<"Midnode "<<endl;
            cout<<midnode->data<<endl;
            prev_slow->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_slow->next = second_half;
        
        return res;
    }
}
 
/* Function to reverse the linked list  Note that this
    function may change the head */
Node* reverse(Node* rev)
{
    Node* current = rev;
    Node* previous = NULL;
    Node* next;
    
    while(current!=NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    rev = previous;
    return rev;
}
 
/* Function to check if two input lists have same data*/
bool compareLists(Node* head1, Node *head2)
{
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        else
            return false;
    }
    if(head1==NULL && head2==NULL)
        return true;
    
    return false;
}
 
/* Push a node to linked list. Note that this function
  changes the head */
Node* push(Node* head, int new_data)
{
    Node* temp = new Node();
    temp->data = new_data;
    temp->next = NULL;
    
    if(head!=NULL)
	{
		temp->next = head;
	}
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
    head = push(head, 5);
    head = push(head, 1);
    cout<<"Initial List"<<endl;
    printList(head);
    
    isPalindrome(head)? cout<<"Is Palindrome"<<endl:
                           cout<<"Not Palindrome"<<endl;
 
    return 0;
}