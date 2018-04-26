#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data)
{
   
    if(root == NULL)
        return getNewNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    if(data > root->data)
        root->right = insert(root->right, data);   
    return root;    
}

void leveltraversal(Node* root)
{
    queue<Node*> q;
    if(root!=NULL)
        q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        cout<<temp->data<<" ";
        q.pop();
    }
}

int main()
{
    Node* root; 
    root = NULL;   //empty tree
    root = insert(root,12);
    root = insert(root,3);
    root = insert(root,6);
    root = insert(root,2);
    root = insert(root,18);
    root = insert(root,14);
    root = insert(root,20);
    cout<<"Level Traversal"<<endl;
    leveltraversal(root);
}