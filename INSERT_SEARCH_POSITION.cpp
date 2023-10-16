
#include<bits/stdc++.h>
using namespace std;
// SEARCH THE INSER POSITION IF SEARCH_ELEMENT IS ABSENT
int searchInsert(vector<int>& arr, int m)
{
	int ans=arr.size();
	int i=0;
	int j=arr.size()-1;
	while(i<=j)
	{
		int mid=(i+j)/2;
		if(arr[mid]>=m)
		{
			ans=mid;
			j=mid-1;
		}
		else
		i=mid+1;
	}
	return ans;
	// Write your code here.
}