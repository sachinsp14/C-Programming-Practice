#include <iostream>

using namespace std;

bool isUnique(string s){
    if(s.length()>128) return false;
    
    bool *char_set = new bool[128];
    for(int i=0; i<s.length(); i++){
        int val = s[i];
        if(char_set[val]) return false;
        
        char_set[val] = true;
    }
    return true;
}

int main(){
    string s = "dsnbf";
    if(isUnique(s))
        cout<<"Unique"<<endl;
    else
        cout<<"Not Unique"<<endl;
}