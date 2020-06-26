#include<bits/stdc++.h>
using namespace std;
class myhm{
public:
    unordered_set<char> m;
    myhm(unordered_set<char> &m1)
    {

        this->m = m1;
    }
    bool operator==(const myhm& h2) const
        {return m == h2.m;}
};
class myhashfn{
public:
    size_t operator()(const myhm &h) const
    {

        return 0;
    }
};
void sameset(vector<string> &ip)
{
    unordered_map<myhm , vector<string> , myhashfn> m;
    for(int i = 0 ; i  <  ip.size() ; i++)
    {
        unordered_set<char> curr;
        for(int j = 0 ; j   < ip[i].size() ; j++)
        {
            curr.insert(ip[i][j]);
        }
         m[myhm(curr)].push_back(ip[i]);

    }
    unordered_map<myhm , vector<string> , myhashfn>  :: iterator it;
    for(it = m.begin() ; it != m.end() ; it++)
    {
        for(int x = 0; x < it->second.size() ; x++)
        {
            cout<<it->second.at(x) << " ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<string> ip;
    int n;
    cin>>n;
    for(int i = 0 ; i  <n ; i++)
    {
        string x;
        cin>>x;
        ip.push_back(x);
    }
    sameset(ip);
}
