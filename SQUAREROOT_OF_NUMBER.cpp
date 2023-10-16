#include<bits/stdc++.h>
using namespace std;

 long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int i=0;
        long long int j=x;
       long long int ans=0;
        while(i<=j)
        {
            long long int mid=(i+j)/2;
            if(mid*mid>x)
            {
                j=mid-1;
            }
            else
            {
                ans=mid;
                i=mid+1;
            }
        }
        return ans;
        
        
    }