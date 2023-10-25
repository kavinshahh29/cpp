#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
    {
        
        for(int i=1;i<n;i++)
        {
            int j=i;
            while(j>0 and arr[j-1]>arr[j])
            {
                int t=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=t;
                j--;
            }
        }
    }