#include <iostream>
#include <string>

using namespace std;

int start_index,end_index,start_index_so_far = 0;
int maxSum(int a[], int n)
{
   int maxSum = 0,sum = 0;
   int i;
   for(i = 0;i<n;i++)
   {
     sum = sum + a[i];
     if(sum < 0)
     {
        sum = 0;
        start_index_so_far = i+1;
     }
     else if(sum > maxSum)
     {
        maxSum = sum;
        start_index = start_index_so_far;
        end_index = i;
     }
   }
   return maxSum;
}

int main()
{
    int a[]={11, -12, 15, -3, 8, -9, 1, 8, 10, -2};
    int n = 10;
    int sum = maxSum(a, n);
    cout<<sum<<endl;
    cout<<start_index<<" "<<end_index<<endl;
}