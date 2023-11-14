#include<bits/stdc++.h>
using namespace std;


// using BFS APPROACH 
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int>visit(V+1,0);
	    queue<pair<int,int>>q;
	    for(int i=0;i<V;i++)
	    {
	        if(visit[i]==0)
	        {
	            q.push({i,-1});
	            while(!q.empty())
	            {
	                int child=q.front().first;
	                int color=q.front().second;
	                q.pop();
	                for(auto it:adj[child])
	                {
	                    if(visit[it]==0)
	                    {
	                        
	                        if(color==-1)
	                        {
	                            visit[it]=1;
	                            q.push({it,1});
	                        }
	                        else
	                        {
	                            visit[it]=-1;
	                            q.push({it,-1});
	                        }
	                    }
	                    else 
	                    {
	                        if(visit[it]==color)
	                        return false;
	                    }
	                }
	            }
	        }
	        
	    }
	    return true;
	}




    // USING DFS APPROACH 

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>visit(V+1,0);
	    for(int i=0;i<V;i++)
	    {
	        if(visit[i]==0)
	        {
	            if(dfs(i,-1,-1,V,adj,visit)==false)
	            return false;
	        }
	   
	        
	    }
	    return true;
	}
	bool dfs(int start,int parent,int color,int V,vector<int>adj[],vector<int>&visit)
	{
	    visit[start]=color;
	    for(auto it:adj[start])
	    {
	        if(visit[it]==0)
	        {
	            if(color==1)
	            {
	                if(dfs(it,start,-1,V,adj,visit)==false)
	                return false;
	            }
	            else
	            {
	                if(dfs(it,start,1,V,adj,visit)==false)
	                return false;
	            }
	            
	        }
	        else 
	        {
	            if(visit[it]==visit[start])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
	
	

};
    