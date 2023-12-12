#include<bits/stdc++.h>
using namespace std;



 int toyCount(int N, int k, vector<int> arr)
    {
        sort(arr.begin(),arr.end());
        long long int sum=0;
        long long int count=0;
        
        for(int i=0;i<N;i++)
        {
            sum=sum+arr[i];
            if(sum<=k)
            {
                count++;
            }
        }
        return count;
    }


    