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

Node* insert(Node* root, int data);
Node* getNewNode(int data);
bool search(Node* root, int data);
int Min(Node* root);
int Max(Node* root);
int findheight(Node* root);
void Levelorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void inorder(Node* root);
bool IsbinarySearchTree(Node* root);
bool Issubtreegreater(Node* root, int data);
bool Issubtreelesser(Node* root, int data);
Node* Delete(Node* root, int data);
int GetSuccessor(Node* root, int data);
Node* minNode(Node* root, int data);
Node* Findmin(Node* root);

int main()
{
    Node* root = NULL;
    cout<<"Binary Search tree"<<endl;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    
    cout<<"Search BST"<<endl;
    bool s = search(root,10);
    if(s)
        cout<< "Number found"<<endl;
    else
        cout<< "Number not found"<<endl;
    
    s = search(root,7);
    if(s)
        cout<< "Number found"<<endl;
    else
        cout<< "Number not found"<<endl;
        
    int min = Min(root);
    cout<<"Minimum is - "<<min<<endl;
    int max = Max(root);
    cout<<"Maximum is - "<<max<<endl;
    
    int height = findheight(root);
    cout<<"Height of tree is - "<<height<<endl;
    
    Levelorder(root);
    
    cout<<endl<<"Preorder"<<endl;
    preorder(root);
    cout<<endl<<"Postorder"<<endl;
    postorder(root);
    cout<<endl<<"Inorder"<<endl;
    inorder(root);
    
    bool flag = IsbinarySearchTree(root);
    if(flag == true)
        cout<<endl<<"Its a BST"<<endl;
    else
        cout<<endl<<"Its not a BST"<<endl;
        
    root = Delete(root,5);
    cout<<endl<<"Inorder"<<endl;
    inorder(root);
}

Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    else if(data<=root->data)
        root->left = insert(root->left, data);
        
    else if(data>root->data)
        root->right = insert(root->right, data);    
    
    return root;    
}

bool search(Node* root, int data)
{
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    if(data<=root->data)
        return search(root->left, data);
    if(data>root->data)
        return search(root->right, data);    
}

int Min(Node* root)
{
    if(root == NULL)
        return -1;
    
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;
}

int Max(Node* root)
{
    if(root == NULL)
        return -1;
    
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;
}

int findheight(Node* root)
{
    if(root == NULL)
        return -1;
    return max(findheight(root->left),findheight(root->right))+1;
}

void Levelorder(Node* root)
{
    if(root == NULL)
        return;
        
    queue<Node*> Q;
    Q.push(root);
    cout<<endl<<"Level Order Traversal"<<endl;
    
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout<<current->data;
        
        if(current->left!=NULL)
            Q.push(current->left);
        
        if(current->right!=NULL)
            Q.push(current->right);
    
        Q.pop();    
    }
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);    
    postorder(root->right);
    cout<<root->data;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);    
    cout<<root->data;
    inorder(root->right);
}

bool IsbinarySearchTree(Node* root)
{
    if(root == NULL)
        return true;
    if((Issubtreelesser(root->left, root->data)) && (Issubtreegreater(root->right, root->data)) && (IsbinarySearchTree(root->left)) 
    && (IsbinarySearchTree(root->right)))
        return true;
    else 
        return false;    
}

bool Issubtreelesser(Node* root, int data)
{
    if(root == NULL)
        return true;
    if(root->data<=data && Issubtreelesser(root->left, data) && Issubtreelesser(root->right,data))
        return true;
    else
        return false;
}

bool Issubtreegreater(Node* root, int data)
{
    if(root == NULL)
        return true;
    if(root->data>  data && Issubtreegreater(root->left, data) && Issubtreegreater(root->right,data))
        return true;
    else
        return false;
}

Node* Delete(Node* root, int data)
{
    if(root == NULL)
        return root;
    else if(data<root->data)
        root->left = Delete(root->left, data);
    else if(data>root->data)    
        root->right = Delete(root->right, data);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            Node* current = root;
            root = root->right;
            delete current;
        }
        else if(root->right == NULL)
        {
            Node* current = root;
            root = root->left;
            delete current;
        }
        else
        {
            int temp = Min(root->right);
            root->data = temp;
            root->right = Delete(root->right, temp);
        }
    }
    return root;
} 

Node* Findmin(Node* root)
{
    if(root == NULL)
        return NULL;
    while(root->left == NULL)
        root = root->left;
    
    return root;    
}

Node* minNode(Node* root, int data)
{
    if(root == NULL)
        return root;
    if(root->data == data)
        return root;
    if(data<=root->data)
        search(root->left, data);
    if(data>root->data)
        search(root->right, data);    
}

int GetSuccessor(Node* root, int data)
{
    Node* current = minNode(root,data);
    if(current == NULL)
        return 0;
    
    if(current->right!=NULL)
    {
        current = Findmin(current->right);
        return current->data;
    }
    else
    {
        Node* successor = NULL;
        
        while(root!= NULL)
        {
            if(current->data < root->data)
            {
                successor =  ancestor;
                root = root->left;
            }
            else
                root = root->right;
        }
        return successor->data;
    }
}
