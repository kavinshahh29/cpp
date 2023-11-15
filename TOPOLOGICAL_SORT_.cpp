#include<bits/stdc++.h>
using namespace std;


//APPROACH USING DFS 

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    stack<int>st;
	    vector<bool>visit(V+1,false);
	    for(int i=0;i<V;i++)
	    {
	        if(visit[i]==false)
	        {
	            dfs(i,visit,adj,st);
	        }
	    }
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	    
	}
	void dfs(int start,vector<bool>&visit,vector<int>adj[],stack<int>&st)
	{
	    visit[start]=true;
	    
	    for(auto it:adj[start])
	    {
	        if(visit[it]==false)
	        {
	            dfs(it,visit,adj,st);
	        }
	    }
	    st.push(start);
	}



//APPROACH USING BFS 



vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>indegree(V+1,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int>ans;
	     while(!q.empty())
	     {
	         int start=q.front();
	         q.pop();
	         ans.push_back(start);
	         for(auto it:adj[start])
	         {
	             indegree[it]--;
	             if(indegree[it]==0)
	             {
	                 q.push(it);
	             }
	             
	         }
	     }
	     return ans;
	    
	    
	    
	}

