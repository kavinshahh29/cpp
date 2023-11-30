#include<bits/stdc++.h>
using namespace std;


	int detectCycle(int V, vector<int>adj[])
	{
	    int parent[V];
	    for(int i=0;i<V;i++)
	    {
	        parent[i]=i;
	        
	    }
	    int rank[V]={0};
	    for(int i=0;i<V;i++)
	    {
	      
	        for(int j=0;j<adj[i].size();j++)
	        {
	            if(i<adj[i][j])
	            {
	                int utl_u=find(i,parent);
	                int utl_v=find(adj[i][j],parent);
	                if(utl_u==utl_v)
	                return 1;
	                if(rank[utl_u]>rank[utl_v])
	                {
	                    parent[utl_v]=utl_u;
	                }
	                else if(rank[utl_u]<rank[utl_v])
	                {
	                    parent[utl_u]=utl_v;
	                }
	                else
	                {
	                    parent[utl_u]=utl_v;
	                    rank[utl_v]++;
	                    
	                }
	                
	            }
	        }
	        
	      
	    }
	    return 0;
	    
	}
	int find(int node,int parent[])
	{
	    if(parent[node]==node)
	    return node;
	    
	    return find(parent[node],parent);
	}