#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* n1;
Node* n2;
Node* push(Node* head, int new_data);
Node* Add(Node* p1, Node* p2);
Node* Reverse(Node* r1);
Node* AddReversed(Node* p1, Node* p2);
Node* AddNode(Node* p1, Node* p2, int* carry);
Node* Append(Node** head, Node** prev, Node* node);
void printList(Node* p);

Node* Add(Node* p1, Node* p2)
{
    if(p1==NULL && p2==NULL)
        return NULL;
    
    p1 = Reverse(p1);
    p2 = Reverse(p2);
    
    cout<<"Reversed List1"<<endl;
    printList(p1);
    cout<<"Reversed List2"<<endl;
    printList(p2);
    
    
    Node* res = AddReversed(p1, p2);
    return res;
}

Node* Reverse(Node* r1)
{
    Node* current = r1;
    Node* prev = NULL;
    Node* next;
    
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    r1 = prev;
    return r1;
}

Node* AddReversed(Node* p1, Node* p2)
{
    int carry = 0;
    Node* head = NULL;
    Node* prev = NULL;
    
    while(p1!=NULL || p2!=NULL)
    {
        Node* node = AddNode(p1, p2, &carry);
        Append(&head, &prev, node);
        
        if(p1!=NULL)
            p1 = p1->next;
        if(p2!=NULL)
            p2 = p2->next;
    }
    if(carry<0)
    {
        Node* temp = push(temp, carry);
        Append(&head, &prev, temp);
    }
    return head;
}

Node* AddNode(Node* p1, Node* p2, int* carry)
{
    int num1 = 0;
    if(p1!=NULL)
        num1 = p1->data;
    int num2 = 0;
    if(p2!=NULL)
        num2 = p2->data;
    
    int sum = num1 + num2 + *carry;
    *carry = (sum>=10) ? 1 : 0;
    
    int value = (sum>=10) ? (sum-10) : sum;
    
    Node* val = NULL;
    val = push(val, value);
    return val;
}

Node* Append(Node** head, Node** prev, Node* node)
{
    if(*head == NULL)
        *head = node;
    if(*prev == NULL)
        *prev = node;
    else
    {
        (*prev)->next = node;
        *prev = node;
    }
}

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
	return head;
}

void printList(Node* p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    n1 = NULL;
    n2 = NULL;
    Node * res = NULL;
    n1 = push(n1, 3);
    n1 = push(n1, 2);
    n1 = push(n1, 1);
    cout<<"List1"<<endl;
    printList(n1);
    n2 = push(n2, 7);
    n2 = push(n2, 6);
    n2 = push(n2, 5);
    n2 = push(n2, 4);
    cout<<"List2"<<endl;
    printList(n2);
    
    res = Add(n1, n2);
    cout<<"Added List"<<endl;
    printList(res);
    
    return 0;
}