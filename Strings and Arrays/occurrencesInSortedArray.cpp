#include<iostream>

using namespace std;

int Search(int A[], int n, int x, bool search) {
    int high = n-1, low = 0, result = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == x) {
            result = mid;
            if(search) high = mid-1;
            else low = mid+1;
        } else if(A[mid]>x) high = mid-1;
        else low = mid+1;
    }
    return result;
}

int main(){
    int A[] = {1,2,3,3,4,4,4,5,6,6,6,6,6,6,7};
    int n = sizeof(A)/sizeof(A[0]);
    int x = 2;
    int first = Search(A, n, x, true);
    if(first == -1)
        cout<<"Number "<<x<<" has not occurred"<<endl;
    else {
        int last = Search(A, n, x, false);
        cout<<"Number "<<x<<" has occurred "<<last-first + 1<<" times"<<endl;
    }
}