#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* head;
void insert(int x);
void print();
void reverse();

int main()
{
    insert(5);
    insert(8);
    insert(9);
    insert(2);
    insert(4);
    insert(3);
    print();
    reverse();
    cout<<endl;
    print();
}

void insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reverse()
{
    stack<Node*> in;
    Node* temp = head;
    while(temp!=NULL)
    {
        in.push(temp);
        temp = temp->next;
    }
    temp=in.top();
    head = temp;
    in.pop();
    while(!(in.empty()))
    {
        temp->next = in.top();
        in.pop();
        temp = temp->next;  
    }
    temp->next = NULL;
}