#include<bits/stdc++.h>
using namespace std;
int countbitright(int n)
{
    if(!n) return 0;
    return log2(n & -n) + 1;
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countbitright(n)<<endl;
    }
	//code
	return 0;
}