#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
using namespace std;

string insertCharAt(string word, string c, int i)
{
    string start = word.substr(0,i);
    string end = word.substr(i,word.length());
    return start+c+end;
}

void permhelp(string s, int start, vector<string> &res)
{
    if(start == s.length()-1)
    {
        res.push_back(s.substr(start,1));
    }
    else
    {
        permhelp(s, start+1, res);
        vector<string> temp;
        temp = res;
        res.clear();
        for(int i=0, len = temp.size(); i<len; i++)
        {
            string toupdate = temp[i];
            for(int j=0, wlen =temp[i].length(); j<=wlen; j++)
            {
                string si = insertCharAt(toupdate, s.substr(start,1), j);
                res.push_back(si);
            }
        }
    }
}

vector<string> perm(string s)
{
    vector<string> res;
    if(s.length()==0)
        return res;
    permhelp(s, 0, res);
    set<string> x;
    for(int i=0; i<res.size(); i++)
    {
        x.insert(res[i]);
    }
    res.clear();
    set<string>::iterator it;
    for(it=x.begin(); it!=x.end(); it++)
    {
        res.push_back(*it);
    }
    return res;
}

int main()
{  
    string s = "aabc";
    set<string> example;
    for(int i=0; i<s.length(); i++)
    {
        auto search = example.find(s.substr(i,1));
        if(search != example.end()) 
        {
            cout<<"found";
        }
        else 
        {
            example.insert(s.substr(i,1));
        }
    }
}