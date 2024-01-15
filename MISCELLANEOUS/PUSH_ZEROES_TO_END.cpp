#include<bits/stdc++.h>
using namespace std;

	void pushZerosToEnd(int arr[], int n) {
	    
	    int i=0;
	    int j=1;
	    while(j<n and i<n)
	    {
	      if(arr[i]!=0)
	      {
	          i++;
	          j++;
	      }
	      else 
	      {
	          if(arr[j]==0)
	          j++;
	          else{
	          swap(arr[i],arr[j]);
	          i++;
	          }
	      }
	        
	   
	    }
	}