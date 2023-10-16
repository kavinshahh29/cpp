#include<bits/stdc++.h>
using namespace std;
	int NthRoot(int n, int m)
	{
	    // Code here.
	   // int ans=-1;
	    int i=0;
	    int j=m;
	    while(i<=j)
	    {
	        int mid=(i+j)/2;
	        if(pow(mid,n)==m)
	        return mid;
	        else if(pow(mid,n)>m)
	        j=mid-1;
	        else
	        i=mid+1;
	    }
	    return -1;
	}  