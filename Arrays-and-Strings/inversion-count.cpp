#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &arr, int si, int midx , int ei)
{
    vector<int> temp(ei - si +1, 0);
    int counter = 0;
    int l = si, r = midx , k =  0;
    while(l < midx && r<=ei)
    {
        if(arr[l] <= arr[r])
        {
            temp[k++] = arr[l++];
        }
        else 
        {
            temp[k++] = arr[r++];
            counter += (midx - l);
        }
    }
    while(l< midx)
    {
        temp[k++] = arr[l++];
    }
    while(r<=ei)
    {
        temp[k++] = arr[r++];
    }
    for(int i = si , k = 0 ; i <= ei ; i++ , k++)
    {
        arr[i] = temp[k]; 
    }
    return counter; 
}
int mergesort(vector<int> &v,int si, int ei)
{
    if(si >= ei)
    {
        return 0;
    }
    int mid = (si + ei)/2;
    int lc = mergesort(v , si , mid );
    int rc = mergesort(v , mid+1 , ei );
    int mycount = merge(v, si, mid+1, ei);

    return lc + rc + mycount;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>> n;
	    vector<int>v(n);
	    for(int i = 0 ; i  < n ; i ++)
	    {
	        cin>>v[i];
	    }
	    cout<<mergesort(v,0,n-1)<<endl;
	}
	return 0;
}