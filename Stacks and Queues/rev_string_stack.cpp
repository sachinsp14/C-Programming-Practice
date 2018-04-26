#include <iostream>
#include<stack>

using namespace std;
string Reverse (string s);
int main()
{
    string s= "Hello";
    string result = Reverse(s);
    cout<<result<<endl;
}

string Reverse(string s)
{
    stack<char> ch;
    int len = s.length();
    for(int i= 0; i<len; i++)
    {
        ch.push(s[i]);
    }
    for(int i= 0; i<len; i++)
    {
        s[i]= ch.top();
        ch.pop();
    }
    return s;
}