// C++ program to reverse a string with special characters
#include<bits/stdc++.h>
using namespace std;
 
// Returns true if x is an aplhabatic character, false otherwise
bool isAlphabet(char x)
{
    return ( (x >= 'A' &&  x <= 'Z') ||
             (x >= 'a' &&  x <= 'z') );
}
 
void reverse(string &str)
{
    int r = str.length()-1,  l = 0;
    while(l<r)
    {
        if(!isAlphabet(str[l]))
            l++;
        else if(!isAlphabet(str[r]))
            r--;
        else
        {
            char temp = str[l];
            str[l] = str[r];
            str[r] = temp;
            l++;
            r--;
        }
    }
}
 
// Driver program
int main()
{
    string str = "a!!!b.c.d,e'f,ghi";
    cout << "Input string: " << str << endl;
    reverse(str);
    cout << "Output string: " << str << endl;
    return 0;
}