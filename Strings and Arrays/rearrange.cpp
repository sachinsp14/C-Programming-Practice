#include<iostream>
#include<string>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void rearrange (int arr[])
{
    int low = 0;
    int high = 6;
    int pivot = arr[6];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
}

int main()
{
    int A[] = {-1, 5, 8, 4, 3, 9, 6};
    rearrange(A);
    for (int i=0; i<7; i++)
    {
        cout<<A[i]<<" ";
    }
}