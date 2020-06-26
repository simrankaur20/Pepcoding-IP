#include <iostream>
using namespace std;
int set_bit(int n)
{
    int c=0;
    while(n)
    {
        if(n&1) c++;
        n >>= 1;
    }
    return c;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<set_bit(n)<<endl;
	}
	return 0;
}