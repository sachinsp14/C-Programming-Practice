#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sub(vector<int> &nums, int start, vector<vector<int>> &res)
{
    if(start == nums.size())
    {
        vector<int> v = {};
        res.push_back(v);
    }
    else
    {
        sub(nums, start+1, res);
        int len =res.size();
        for(int i=0; i<len; i++)
        {
            vector<int> y;
            y = res[i];
            y.push_back(nums[start]);
            res.push_back(y);
        }
    }
}

vector<vector<int>> subset(vector<int> nums)
{
    vector<vector<int>> res;
    sub(nums, 0, res);
    return res;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> x = subset(nums);
    for(int i=0; i<x.size();i++)
    {
        for(int j=0; j<x[i].size(); j++)
        {
            cout<<x[i][j];
        }
        cout<<endl;
    }
}