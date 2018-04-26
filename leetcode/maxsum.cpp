#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int maxProduct(vector<int>& nums) 
{
    int m1 = 0;
    int maximum;
    maximum = nums[0];
    
    for(int i=0; i<nums.size(); i++)
    {
        m1 = m1+nums[i];
        maximum = max(maximum,m1);
        if(m1<0)
            m1 = 0;
    }
    return maximum;
}

int thirdMax(vector<int>& nums) 
{
    set<int> s;
    for(int i=0; i<nums.size(); i++)
        s.insert(nums[i]);
    int count=0;
    set<int>::reverse_iterator rit;
    for (rit=s.rbegin(); rit != s.rend(); ++rit)
    {
        if(s.size()<3)
        {
            return *rit;
        }
        count++;
        if(count == 3)
            break;
    }
    return *rit;
}

int main()
{
    vector<int> nums = {3,2,1};
    int x = maxProduct(nums);
    x = thirdMax(nums);
    cout<<x;
}