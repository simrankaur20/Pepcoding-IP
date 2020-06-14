#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int mask = (1 << k);
	    cout << (n | mask) << endl;
	}
	return 0;
}