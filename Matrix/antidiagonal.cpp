#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> antidiagonal(vector<vector<int>> mat, int m, int n)
{
    vector<vector<int>> res(m+n-1);
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x =i+j;
            res[x].push_back(mat[i][j]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},
                               {5,6,7,8},
                               {9,10,11,12},
                               {13,14,15,16}};
                               
    vector<vector<int>> res = antidiagonal(mat,4,4);
    
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}