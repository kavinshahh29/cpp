#include<bits/stdc++.h>
using namespace std;



//  USING DFS

bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    vector<int>adj[N+1];
	    for(int i=0;i<pre.size();i++)
	    {
	        int f=pre[i].first;
	        int s=pre[i].second;
	        adj[s].push_back(f);
	        
	        
	    }
	    vector<bool>visit(N+1,false);
	    vector<bool>pathvisit(N+1,false);
	    for(int i=0;i<N;i++)
	    
	    {
	        if(visit[i]==false)
	        {
	            
	            if(dfs(i,visit,pathvisit,adj)==true)
	            return false;
	        }
	    }
	    return true;
	    
	    
	    
	}
	bool dfs(int start,vector<bool>&visit,vector<bool>&pathvisit,vector<int>adj[])
	{
	    pathvisit[start]=true;
	    visit[start]=true;
	    
	    for(auto it:adj[start])
	    {
	        if(visit[it]==false)
	        {
	            if(dfs(it,visit,pathvisit,adj)==true)
	            return true;;
	        }
	        else if(pathvisit[it]==true)
	        return true;
	    }
	    pathvisit[start]=false;
	    return false;
	}




// USING BFS 



bool isPossible(int n,int m, vector<pair<int, int> >& pre) {
	    
	     vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            adj[pre[i].second].push_back(pre[i].first);
            
        }
        vector<int>ans;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push({i});
            }
        }
        while(!q.empty())
        {
            int start=q.front();
            q.pop();
            for(auto it:adj[start])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            ans.push_back(start);
        }
        if(ans.size()!=n)
        return false;
        return true;
        
	}