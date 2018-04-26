#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

void levelOrderTraversal(Node* root);

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
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Node* root = NULL;
    int start = 0;
    int end = nums.size() -1;
    root = insert(nums,start, end);
    cout<<"Done!"<<endl;
    
    levelOrderTraversal(root);
}

void levelOrderTraversal(Node* root)
{
    queue<Node*>  q;
    q.push(root);
    
    while(!(q.empty()))
    {
        Node* curr = q.front();
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
        cout<<curr->data<<" ";
        q.pop();
    }
}