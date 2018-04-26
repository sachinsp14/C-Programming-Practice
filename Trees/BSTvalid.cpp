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

bool isBST(Node* root);
bool isSubtreeLesser(Node* lNode, int rootdata);
bool isSubtreeGreater(Node* rNode, int rootdata);

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
    else if(data > root->data) 
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
    
    bool r = isBST(root);
    
    if(r)
        cout<<"Valid BST";
    else
        cout<<"Invalid BST";
}

bool isBST(Node* root)
{
    if(root == NULL) 
        return true;  //base case
    
    if(isSubtreeLesser(root->left,root->data) &&
       isSubtreeGreater(root->right,root->data) &&
       isBST(root->left) &&
       isBST(root->right)
       )
        return true;
    else
        return false;
    
}

bool isSubtreeLesser(Node* lNode, int rootdata)
{
    if(lNode == NULL) 
        return true;
    
    if(lNode->data < rootdata &&
       isSubtreeLesser(lNode->left,rootdata)  &&
       isSubtreeLesser(lNode->right,rootdata)
    )
        return true;
    else    
        return false;
}

bool isSubtreeGreater(Node* rNode, int rootdata)
{
    if(rNode == NULL) 
        return true;

    if(rNode->data > rootdata &&
       isSubtreeGreater(rNode->left,rootdata)  &&
       isSubtreeGreater(rNode->right,rootdata)
    )
        return true;
    else 
        return false;
}