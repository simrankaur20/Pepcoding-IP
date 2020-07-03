#include<bits/stdc++.h>
using namespace std;

string check(int * arr , int n)
{

    int count = 0 ;
     bool isup = true;

    for(int i = 0 ;  i<n-1 ; i ++)
    {

        if(isup && arr[i+1] > arr[i])
        {

        }
        else if(!isup && arr[i+1] < arr[i])
        {

        }
        else{
            count++;
            isup = !isup;
        }
    }
    if(!isup) count++;
    return count == 2 ? "yes" : "no";
}
int main()
{
    int n;
    cin>>n;
    int * arr = new int[n];

    for(int i = 0 ; i  < n ; i++)
    {

        cin>>arr[i];
    }
    cout<<check(arr, n);
}
