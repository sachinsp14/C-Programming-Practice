#include <iostream>
#include <string>

using namespace std;

void print(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertion(int a[], int len)
{
    for(int i=1; i<len; i++)
    {
        int value = a[i];
        int x = i;
        while(x>0 && a[x-1]>value)
        {
            a[x] = a[x-1];
            x--;
        }
        a[x] = value; 
    }
    print(a,len);
}

int main()
{
    int a[] = {2,7,4,1,5,3};
    int len  = 6;
    print(a,len);
    insertion(a,len);
}