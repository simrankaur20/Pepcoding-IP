#include<bits/stdc++.h>
using namespace std;
int fun(int n1, int n2)
{
    int n = n1 ^ n2;
    return log2(n & -n) + 1;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1>>n2;
        cout<<fun(n1,n2)<<endl;
    }

	return 0;
}