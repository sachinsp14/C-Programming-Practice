#include<iostream>
#include<vector>

using namespace std;

int solve(int total,int finaltotal, vector<int> coins, int index, vector<int> temp, vector<vector<int>>& res)
{
    if (total == finaltotal) 
    {
        res.push_back(temp);
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << ' ';
        }
        cout << "\n";
        return 1;
    }
    if (total > finaltotal) return 0;
    int sum = 0;
    for (int i = index; i < coins.size(); i++)
    {
        temp.push_back(coins[i]);
        sum += solve(total + coins[i],finaltotal, coins, i,temp,res); 
        temp.pop_back();
    }
    return sum;
}

int main()
{
    vector<int> coins = {1,2,3};
    vector<vector<int>> res;
    vector<int> temp; 
    int total = 0;
    int index = 0;
    int finaltotal = 5;
    cout << solve(total,finaltotal, coins, index,temp,res) << endl;
}