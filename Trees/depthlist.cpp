#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

void levelOrderTraversal(Node* root);
list<list<Node*>> depths_list(Node* root);

Node* insert(vector<int> nums,int start, int end)
{
    if(end<start)
    return NULL;
    
    int mid = (start + end)/2 ;
    Node* newNode = new Node();
    newNode->data = nums[mid];
    newNode->left = insert(nums,start,mid-1);
    newNode->right = insert(nums,mid+1,end);
    
    return newNode;
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    Node* root = NULL;
    int start = 0;
    int end = nums.size() -1;
    root = insert(nums,start, end);
    cout<<"Done!"<<endl;
    
    levelOrderTraversal(root);
    cout<<endl;
    
    list<list<Node*>> res = depths_list(root);
    
    for(auto i = res.begin(); i != res.end(); i++)
    {
        for(auto j = (*i).begin(); j != (*i).end(); j++)
        {
            cout<<(*j)->data<<" ";
        }
        cout<<endl;
    }
    cout<<"Done!"<<endl;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* cur = q.top();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        cout<<curr->data<<" ";    
        q.pop();    
    }
}

list<list<Node*>> depths_list(Node* root)
{
    list<Node*> current;
    list<Node*> parent;
    list<list<Node*>> res;
    
    if(root!=NULL)
        current.push_back(root);
    
    while(current.size()>0)
    {
        res.push_back(current);
        parent = current;
        current.clear();
    
        auto it = parent.begin();
    
        while(it!=parent.end())
        {
            if((*it)->left!=NULL)
                current.push_back((*it)->left);
            
            if((*it)->right!=NULL)
                current.push_back((*it)->right);  
                
            it++;    
        }
    }
    return res;
}