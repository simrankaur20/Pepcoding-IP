#include<bits/stdc++.h>
using namespace std;
string window(string s)
{

    unordered_map<char, int> m1;
    int  start = 0 , end = 0;
    int mlen = s.length() , mstart = 0, mend = 0;
    unordered_set<char> hs;
    for(char x : s)
    {
        hs.insert(x);
    }
    while(start < s.length())
    {
        if(m1.size() < hs.size() && end<s.length())
        {
            m1[s[end]]++;
            end++;
        }
        else if(m1.size() >= hs.size())
        {
                int len = (end-start + 1);
                if(len < mlen)
                {
                    mstart = start;
                    mend = end;
                    mlen = len;
                }
                m1[s[start]]--;
                if(m1[s[start]]==0)
                {
                    m1.erase(s[start]);
                }
                start++;
        }
        else{
            break;
        }

    }
    return s.substr(mstart, mend);
}
int main()
{

    string s;
     cin>>s;
     cout<<window(s);
}
