#include<bits/stdc++.h>
using namespace std; 
void radix(int arr[],int n,int p)
{
    int freq[10]={0};
    for(int i=0;i<n;i++)
    {
        freq[arr[i]/p%10]++;
    }
    for(int i=1;i<10;i++)
    {
        freq[i]+=freq[i-1];
    }
    vector<int>ans(n,0);
    for(int i=n-1;i>=0;i--)
    {
        ans[--freq[arr[i]/p%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    arr[i]=ans[i];
}
void radixSort(int arr[], int n) 
{ 
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    for(int i=1;maxi/i>0;i*=10)
    {
        radix(arr,n,i);
    }
    
   
} 