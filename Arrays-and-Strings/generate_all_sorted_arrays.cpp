#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> & ans)
{
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
void func(vector<int> &a, vector<int> &b , int i1, int i2, vector<int> &ans , int turn)
{

    if(turn == 1){
//                if(i1 == a.size())
//                {
//                    printvector(ans);
//                    return ;
//                }

                for(int x = i1; x < a.size() ; x++)
                {
                    if(ans.size() == 0 || (a[x] > ans[ans.size()-1]))
                    {
                        ans.push_back(a[x]);
                        func(a , b , x+1, i2, ans , -1);
                        ans.pop_back();
                    }
                }
    }
    else{
//            if(i2 == b.size())
//            {
//                printvector(ans);
//                return ;
//            }
            for(int i =  i2 ; i  < b.size() ; i++)
            {
                if( b[i] > ans[ans.size() - 1])
                {
                    ans.push_back(b[i]);
                    printvector(ans);
                    func(a,b, i1 , i+1 , ans, 1);
                    ans.pop_back();
                }
            }
    }
}

int main()
{
    vector<int> a{10,15,25};
    vector<int> b{1,5,20,30};
    vector<int> ans;
    func(a,b, 0,0,ans, 1);
}
