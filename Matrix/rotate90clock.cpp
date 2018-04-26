#include <iostream>
#include <vector>

using namespace std;

void rotatematrix(vector<vector<int>> &mat)
{
    int N = mat.size();
    for(int i=0; i<N/2; i++)
    {
        for(int j =i; j<N-1-i; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[N-1-j][i];
            mat[N-1-j][i] = mat[N-1-i][N-1-j];
            mat[N-1-i][N-1-j] = mat[j][N-1-i];
            mat[j][N-1-i] = temp;
        }
    }
}

void display(vector<vector<int>> &mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        for(int j =0; j<mat[i].size(); j++)
        {
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},
                               {5,6,7,8},
                               {9,10,11,12},
                               {13,14,15,16}};

    cout<<"original matrix"<<endl;
    display(mat);
    rotatematrix(mat);
    cout<<endl<<endl<<"rotated matrix"<<endl;
    display(mat);
}