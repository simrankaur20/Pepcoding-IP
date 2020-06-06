#include<bits/stdc++.h>
using namespace std;
class person{
    public:

    string name ;
    int id;
    person(string x, int y)
    {
        this->name = x;
        this->id = y;
    }

    bool operator==(const person &t) const
    {
        return this->id == t.id;
    }

};

class myhashfunc{
    public:
    size_t operator()(const person &p) const
    {
        return p.id;
    }
};
int main()
{
    person p1("simran" , 1) , p2("supreet" , 2);
   // cout<<"hello";
    unordered_set<person, myhashfunc> s;
    s.insert(p1);
    s.insert(p2);

    cout<<(s.find(person("simran" , 1)))->name<<endl;

    for(auto x : s)
    {
        cout<<x.name << " " << x.id<<endl;
    }


}