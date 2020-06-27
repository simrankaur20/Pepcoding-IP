#include<bits/stdc++.h>
using namespace std;
string fun(string s1, string s2)
{

    unordered_map<char, int> master, temp;

    for(char x : s2)
    {
        master[x]++;
    }
    int mc = 0;

    int start = 0, end = 0 , mstart = 0, mend = 0, mlen = INT_MAX;

    for(;end<s1.length();end++)
    {
        temp[s1[end]]++;
        if(master.count(s1[end]) && temp[s1[end]] <= master[s1[end]])
        {
            mc++;
        }
        if(mc == s2.length())
        {
            while( temp[s1[start]] > master[s1[start]])
            {

                temp[s1[start]]--;
                if(temp[s1[start]] == 0)
                {
                    temp.erase(s1[start]);
                }
                start++;
            }

            int len = end-start+1;
            if(len < mlen)
            {
                mstart = start;
                mlen = len;
                mend=  end;
            }
        }
    }
    return s1.substr(mstart, mlen);
}
 int main()
 {

     string s1, s2;

     cin>>s1>>s2;
     cout<<fun(s1,s2);
 }
