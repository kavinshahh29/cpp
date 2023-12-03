#include<bits/stdc++.h>
using namespace std;
  void selectionSort(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            int val=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[val]>arr[j])
                {
                    val=j;
                    
                    
                    
                }
                
            }
            if(i!=val)
            swap(arr[i],arr[val]);
        }
       
    }