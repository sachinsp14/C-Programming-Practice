// The selection sort algorithm sorts an array by repeatedly finding the minimum element 
// (considering ascending order) from unsorted part and putting it at the beginning

#include <iostream>
using namespace std;

void selectionSort(int *A, int n){
    int min;
    for(int i=0; i<n; i++){
        bool flag = false;
        min = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[min]){
                flag = true;
                min = j;
            }
        }
        if(flag){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

int main(){
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A)/sizeof(A[0]);
    selectionSort(A, n);
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
}