#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void rec(string x, int idx, string ssofar)
{
    if(idx > x.length())
    {
        return ;
    }

    if(idx == x.length() )
    {
        cout<<ssofar << " ";
        return;
    }


        if(x[idx] == '1' || x[idx] == '0')
        {
           rec(x, idx+1, ssofar+(char) x[idx]);
        }
        else
        {
            rec(x, idx+1 , ssofar + '0');
            rec(x, idx+1 , ssofar + '1');

        }

}

void bfs(string s)
{
    queue<string>q;
    if(s[0] == '?')
    {
        q.push("0");
        q.push("1");
    }
    else
    {
        q.push("" + (char) s[0]);
    }
    int idx = 1;
    while(!q.empty())
    {
        int c = q.size();

        while(c--)
        {
             string curr = q.front();
            cout<<q.front() << " ";
            q.pop();
            /*if(idx < s.length() && s[idx] == '?')
            {
                q.push(curr+"0");
                q.push(curr + "1");
            }
            else if(idx < s.length())
            {
                q.push(curr + (char)s[idx]);
            }*/
        }
       /* idx++;
        if(idx == s.length())
        {
            break;
        }*/
    }
    /*while(!q.empty())
    {
        cout<<q.front() << " ";
        q.pop();
    }*/
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    bfs(s);
	    //rec(s,0,"");
	    cout<<endl;
	}
	return 0;
}
