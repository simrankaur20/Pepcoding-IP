
#include <iostream>
using namespace std;
int toggle(int n, int l , int r)
{
    int mask = ((1<<r) - 1) ^ ((1 << (l-1)) - 1);
    return n ^ mask;
    
}
int main() {
	//code
	
	int t;
	cin>> t;
	while(t--)
	{
	    int n,l,r;
	    cin>>n >> l>> r;
	    cout<<toggle(n,l,r)<<endl;
	}
	return 0;
}