#include <iostream>
#include <string>
#include <vector>

using namespace std;
int triplesteps(int n, vector<int> memo);
int countways(int n);

int main()
{
    int n=6;
    int x = countways(n);
    cout<<x;
}

int countways(int n)
{
    vector<int> memo(n+1); 
    for(int i=0; i<n+1; i++)
    {
        memo[i]= -1;
    }
    return triplesteps(n, memo);
}

int triplesteps(int n, vector<int> memo)
{
    if(n<0)
        return 0;
    else if(n==0)
        return 1;
    else if(memo[n]>-1)
        return memo[n];
    else
    {
        memo[n] = triplesteps(n-1, memo) + triplesteps(n-2, memo) + triplesteps(n-3, memo);
        return memo[n];
    }
}