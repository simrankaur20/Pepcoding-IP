#include<bits/stdc++.h>
using namespace std;
class pers{
    public:
    string f,l;
    pers(string x, string y)
    {
        this->f = x;
        this->l = y;
    }
    bool operator==(const pers &p) const
    {
        return f == p.f && l == p.l;
    }

};

class myhasfun{
    public:
    size_t operator()(const pers &p) const
    {
        return 0;
    }
};

int main()
{
    unordered_map<pers,string, myhasfun> m;

    pers p1("simran" , "kaur"), p2("supreet" , "singh"), p3("pyaaru" , "singh") ;
    m[p1] = "one";
    m.insert({p2, "two"});
    m[p3] = "three";
    unordered_map<pers, string, myhasfun> :: iterator it;

    for(it = m.begin() ; it != m.end(); it++)
    {
        cout<<it->first.f << " " << it->first.l << " " << it->second<<endl;
    }

    m.clear();
}