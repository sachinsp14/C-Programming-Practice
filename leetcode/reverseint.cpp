#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int reverseint(int x)
{
    int res = 0;
    while(x) 
    {
        res = res*10 + x%10;
        x /= 10;
    }
    return res;
}

int main()
{
    int x = -543;
    cout<<x<<endl;
    int y = reverseint(x);
    cout<<y;
}