#include<iostream>
#include<math.h>

using namespace std;

class Node
{
  public:    
  int data;
  Node* left;
  Node* right;
};

int height(Node* root);
bool checkbalanced(Node* root);

Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return getNewNode(data);
    else if(data < root->data) 
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    
    return root;
}


int main()
{
    Node* root;
    root = NULL;   //empty tree
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    
    bool res = checkbalanced(root);
    
    if(res)
        cout<<"Tree is balanced";
    else
        cout<<"Tree is not balanced";
}

int height(Node* root)
{
    int hl,hr;
    if(root == NULL)
        return -1;
    
    hl = height(root->left);
    hr = height(root->right);
    
    return max(hl,hr)+1;
}

bool checkbalanced(Node* root)
{
    if(root == NULL)
        return true;

    int h = height(root->left) - height(root->right);
    if(abs(h)>1)
        return false;
    else
        return (checkbalanced(root->left) && checkbalanced(root->right));
}