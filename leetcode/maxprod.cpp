#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) 
{
    int m1 = 1;
    int m2 = 1;
    int maximum = nums[0];
    for(int i=0; i<nums.size(); i++)
    {
        m1 = m1*nums[i];
        m2 = m2*nums[nums.size()-i-1];
        
        maximum = max(maximum,max(m1,m2));
        
        if(m1 == 0)
            m1 = 1;
        if(m2 == 0)
            m2 = 1;
    }
    return maximum;
}

int main()
{
    vector<int> nums = {-4,-2,-3, 0};
    int x = maxProduct(nums);
    cout<<x;
}