#include<iostream>
#include<set>
using namespace std;

bool isUniqueArray(int A[], int n){
    set<int> int_set;
    for(int i=0; i<n; i++){
        set<int>::iterator it = int_set.find(A[i]);
        if(it!=int_set.end()) return false;
        int_set.insert(A[i]);
    }
    return true;
}

int main(){
    int A[] = {0,0,0};
    int n = sizeof(A)/sizeof(A[0]);
    
    if(isUniqueArray(A, n))
        cout<<"Unique Array";
    else
        cout<<"Not a Unique Array";
}