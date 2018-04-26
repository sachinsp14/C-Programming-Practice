#include<iostream>

using namespace std;

void BubbleSort(int *A, int n){
    for(int i=0; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-1; j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

int main(){
    int A[] = {6,5,4,8,3,2,1};
    int n = sizeof(A)/sizeof(A[0]);
    BubbleSort(A, n);
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
}