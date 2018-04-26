#include <iostream>
#include <string>
#include <stack>

using namespace std;

void hanoi(int N, stack<int> &src, stack<int> &temp, stack<int> &dest)
{
    if(N==1)
    {
        dest.push(src.top());
        src.pop();
    }
    else
    {
        hanoi(N-1,src,dest,temp);
        hanoi(1,src,temp,dest);
        hanoi(N-1,temp,src,dest);
    }
}

int main()
{
    stack<int> src;
    stack<int> temp;
    stack<int> dest;
    src.push(3);
    src.push(2);
    src.push(1);
    hanoi(src.size(),src,temp,dest);
    cout<<"Done"<<endl;
}