#include<iostream>
 #include<vector>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input N. It should return the number of structurally unique BSTs.
 int cat(int n)
 {
     if(  n==1 || n==0 )
     {
         return 1;
     }
     int s = 0;
     for(int i = 0 ; i <  n ; i++)
     {
         s = s + (cat(i) * cat(n-i-1));
     }
     return s;
 }
 int numTrees(int n) {

 return cat(n);
 }

 int main(int argc, char** argv){
     int N;
     cin>>N;
     cout<<numTrees(N)<<endl;
 }
