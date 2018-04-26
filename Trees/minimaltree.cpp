#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* minhelp(vector<int> v, int start, int end)
{
    if(end<start)
        return NULL;
    
    int mid = (start+end)/2;
    Node* n = new Node();
    n->data = v[mid];
    n->left = minhelp(v,start,mid-1);
    n->right = minhelp(v, mid+1, end);
    return n;
}

Node* mintree(vector<int> v)
{
    return minhelp(v,0,v.size()-1);
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

int main()
{
    Node* root = NULL;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    root = mintree(v);
    Levelorder(root);
}