#include<iostream>

using namespace std;

int binarySearch(int A[], int n, int x){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid]>x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int main(){
    int A[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(A)/sizeof(A[0]);
    int x = 8;
    int res = binarySearch(A, n, x);
    if(res!=-1) cout<<"Element is present at index "<<res<<endl;
    else cout<<"Element is not present"<<endl;
}