#include<bits/stdc++.h>
using namespace std;




	void shortest_distance(vector<vector<int>>&matrix){
	    
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix[i].size();j++)
	        {
	            if(i==j)
	            matrix[i][j]=0;
	            else if(matrix[i][j]==-1)
	            matrix[i][j]=INT_MAX;
	        }
	        
	    }
	    for(int k=0;k<matrix.size();k++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	            for(int j=0;j<matrix.size();j++)
	            {
	                if(matrix[i][k]!=INT_MAX and matrix[k][j]!=INT_MAX)
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            if(matrix[i][j]==INT_MAX)
	            matrix[i][j]=-1;
	        }
	    }
	    
	}