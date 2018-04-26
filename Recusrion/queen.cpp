#include<iostream>
#include<vector>

using namespace std;

vector<int> x(5,0);
bool place (int k, int i);
void Nqueen(int k, int N);

int main()
{
    int N = 4;  //size of N*N chess board
    Nqueen(1,N);  //recursive call to place the queens
    return 0;
    
}

bool place (int k, int i)    //can the queen be placed in kth row and ith column?
{
    for(int j=1 ; j<=k-1; j++)
    {
        if(x[j] == i)  // same column
        return false;
        
        if(abs(x[j]-i) == abs(j-k))  //checks for diagonals i.e x[j] and i are columns and j and k are rows
        return false;
    }
    return true;
}

void Nqueen(int k, int N)  // k is row and N is number of queens
{
    for(int i=1; i<=N; i++)
    {
        if(place(k,i))
        {
            x[k] = i;
            
            //exit condition
            if(k == N )
            {
              //write all the values of vector x
              for(int i = 1; i<x.size();i++)
              cout<<x[i]<<" ";
              cout<<endl;
            }
            
            else
            Nqueen(k+1,N);
        }
    }
}