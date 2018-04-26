#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> sums(vector<int> &nums);

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> r =sums(nums);
}

vector<vector<int>> sums(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> r;
    
    for(int i=0; i<nums.size(); i++)
    {
        int x = -nums[i];
        int f = i+1;
        int l = nums.size()-1;
        
        while(f<l)
        {
            int sum = nums[f] + nums[l];
            if(sum<x)
                f++;
            else if(sum>x)
                l--;
            else
            {
                vector<int> temp(3,0);
                temp[0] = nums[i];
                temp[1] = nums[f];
                temp[2] = nums[l];
                r.push_back(temp);
            
                while(f<l && temp[1] == nums[f])
                    f++;
                while(f<l && temp[2] == nums[l])
                    l--;    
            }
        }
        while(i+1<nums.size() && nums[i+1] == nums[i])
            i++;
    }
    return r;
}