#include <iostream>
using namespace std;
string check(int n ,int k)
{
    int mask = 1 << k;
    
    if(mask & n)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    cout<<check(n,k)<<endl;
	}
	return 0;
}