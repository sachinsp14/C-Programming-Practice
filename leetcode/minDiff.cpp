#include <iostream>
#include <algorithm>
using namespace std;
 

int findMinDiff(int arr[], int n)
{
   // Initialize difference as infinite
   int diff = 100;
 
   // Find the min diff by comparing difference
   // of all possible pairs in given array
   for (int i=0; i<n-1; i++)
      for (int j=i+1; j<n; j++)
          if (abs(arr[i] - arr[j]) < diff)
                diff = abs(arr[i] - arr[j]);
 
   // Return min diff
   return diff;
}
 
int main()
{
   int arr[] = {9, 32, 1, 6, 13};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Minimum difference is " << findMinDiff(arr, n);
   return 0;
}