#include<bits/stdc++.h>
using namespace std;

// FIND FLOOR AND CEIL VALUE IN SORTED ARRAY
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int i=0;
	int j=n-1;
	int ans2=-1;
	while(i<=j)
	{
		int mid=(i+j)/2;
		if(a[mid]>=x)
		{
			ans2=a[mid];
			j=mid-1;
			
		}
		else
		i=mid+1;

	}
	i=0;
	j=n-1;
	int ans1=-1;
	while(i<=j)
	{
		int mid=(i+j)/2;
		if(a[mid]<=x)
		{
			ans1=a[mid];
			i=mid+1;
		}
		else
		j=mid-1;
	}
	return {ans1,ans2};
}