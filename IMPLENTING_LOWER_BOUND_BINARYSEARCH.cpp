#include<bits/stdc++.h>
using namespace std;
// IMPLEMENT LOWER BOUND 
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int in=n;
	int i=0;
	int j=n-1;
	while(i<=j)
	{
		int mid=(i+j)/2;
		if(arr[mid]>=x)
		{
			in=mid;
			j=mid-1;
		}
		else
		i=mid+1;
	}
	return in;
	
}
