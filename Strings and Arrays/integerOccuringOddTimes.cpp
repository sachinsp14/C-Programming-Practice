// Find the Number Occurring Odd Number of Times
#include <iostream>

using namespace std;

int getOddOccurrence(int A[], int n){
    int res = 0;
    for(int i=0; i<n; i++){
        res = res^A[i];
    }
    return res;
}

int main() {
    int A[] = {2, 3, 5, 4, 2, 5, 4, 3, 5, 2, 4, 4, 2};
    int n = sizeof(A)/sizeof(A[0]);
    int res = getOddOccurrence(A, n); 
    if(res)
        cout<<"Element is "<<res<<endl;
    else
        cout<<"No such element"<<endl;
    
}
