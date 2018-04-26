#include <iostream>
#include <vector>

using namespace std;

void printAllPaths(vector<vector<int>> v, vector<int> r, int rows, int cols, int i, int j ) 
{
    r.push_back(v[i][j]);
    if ((i == rows - 1) && (j == cols -1)) 
    {
        for (int x=0; x<r.size(); x++)
        {
            cout<<r[x]<<" ";
        }
        cout<<endl;
    }
    if (i < rows - 1)
        printAllPaths(v, r, rows, cols, i + 1, j);

    if (j < cols - 1)
        printAllPaths(v, r, rows, cols, i, j + 1);
        
    return ;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> path(m, vector<int> (n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            path[i][j] = path[i - 1][j] + path[i][j - 1];
    return path[m - 1][n - 1];
}
int main()
{
    vector<vector<int>> v = {
                    {1, 2, 3, 3, 2, 2 },
                    {4, 5, 6, 4, 2, 2 },
                    {7, 8, 9, 5, 2, 2 },
                    {1, 2, 3, 4, 2, 2 },
                    {1, 2, 3, 4, 2, 2 },
                    {1, 2, 3, 4, 2, 2 }
                  };
    vector<int> r;
    int c = 0;
    //printAllPaths(v, r, 6, 6, 0, 0);
    int x = uniquePaths(6,6);
    cout<<x<<endl;
}