#include<bits/stdc++.h>
using namespace std;
void upheapify(int arr[] , int n , int i)
{
     int ci = i, pi = (i-1)/2;
     
     while(ci > 0)
     {
         pi = (ci-1)/2;
         
         if(arr[pi] > arr[ci])
            break;
        else 
            swap(arr[pi],arr[ci]);
        ci = pi;
     }
}


// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    cout<<"inside bh";
   for(int i = n-1;i>=0;i--)
        downheapify(arr,n,i);     //would be downheapify

}
void downheapify(int *arr, int i, int n)
{
    int pi = i;
    while(pi < n)
    {
        int cil = 2*pi + 1 , cir = 2*pi+2;
        int maxidx = pi;
        if(cil < n && arr[cil] > arr[maxidx])
            maxidx = cil;
        if(cir < n && arr[cir] > arr[maxidx])
            maxidx = cir;
        if(maxidx == pi) break;
        else
        {
            swap(arr[maxidx] , arr[pi]);
        }
        pi = maxidx;
        
    }
}

void heapsort(int *arr , int n)
{
    buildHeap(arr,n);

    for(int i = n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        downheapify(arr,0,i);
    }
}


int main()
{
    int arr[] = {4,1,3,9,7};
    cout<<"mjlfjefkmk"<<endl;
    heapsort(arr,5);
    for(int x : arr)
    {
        cout<<x<<" ";
    }
}
