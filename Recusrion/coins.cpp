#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> coins = {1,2,3};
    int value = 5;
    vector<vector<int>> coinways((coins.size()+1),vector<int>(value+1));
    
    for(int i=0; i<coins.size()+1; i++)
    {
        coinways[i][0] = 1;
    }
    for(int i=1; i<=coins.size(); i++)
    {
        for(int j=1; j<=value; j++)
        {
            if(coins[i-1]>j)
                coinways[i][j] = coinways[i-1][j];
            else
                coinways[i][j] = coinways[i-1][j] + coinways[i][j-coins[i-1]];
        }
    }
    cout<<coinways[coins.size()][value];
}