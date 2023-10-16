#include<bits/stdc++.h>
using namespace std;
/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int ans1=-1;
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
	        else if(arr[mid]<x)
	        i=mid+1;
	        else
	        j=mid-1;
	    }
	    if(ans1==-1)
	    return 0;
	    i=0;
	    j=n-1;
	    int ans2=0;
	    while(i<=j)
	    {
	        int mid=(i+j)/2;
	        if(arr[mid]==x)
	        {
	            ans2=mid;
	            i=mid+1;
	        }
	        else if(arr[mid]<x)
	        {
	            i=mid+1;
	        }
	        else
	        j=mid-1;
	    }
	    return ans2-ans1+1;
	    
	}