#include<bits/stdc++.h>
using namespace std;
 vector<int> find(int arr[], int n , int x )
    {
        // code here
        int ans1=-1;
        int ans2=-1;
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr[mid]==x)
            {
                ans1=mid;
                j=mid-1;
            }
            else if(arr[mid]>x)
            {
                j=mid-1;
                
            }
            else
            i=mid+1;
        }
        i=0;
        j=n-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr[mid]==x)
            {
                i=mid+1;
                ans2=mid;
            }
            else if(arr[mid]>x)
            {
                j=mid-1;
            }
            else
            i=mid+1;
        }
        return {ans1,ans2};
    }