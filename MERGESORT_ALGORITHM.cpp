#include<bits/stdc++.h>
using namespace std;    

vector<int>ans; // global vector for tle issue 
void merge(int arr[], int l, int m, int r)
    {
        ans.clear();
        int left=l;
        int right=m+1;
        while(left<=m and right<=r)
        {
            if(arr[left]<=arr[right])
            {
                ans.push_back(arr[left]);
                left++;
            }
            else{
                ans.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m)
        {
            ans.push_back(arr[left]);
            left++;
            
        }
        while(right<=r)
        {
            ans.push_back(arr[right]);
            right++;
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=ans[i-l];
        }
         
         
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        
        if(l>=r)
        return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }